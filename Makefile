# **************************************************************************** #
#                                                                              #
#			▗▖  ▗▖ ▗▄▖ ▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▄▖▗▖   ▗▄▄▄▖						   #
#			▐▛▚▞▜▌▐▌ ▐▌▐▌▗▞▘▐▌   ▐▌     █  ▐▌   ▐▌   						   #
#			▐▌  ▐▌▐▛▀▜▌▐▛▚▖ ▐▛▀▀▘▐▛▀▀▘  █  ▐▌   ▐▛▀▀▘						   #
#			▐▌  ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▖▐▌   ▗▄█▄▖▐▙▄▄▖▐▙▄▄▖   					   #
#																			   #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

#------------------------------------------------------------------------------#
#									FILES  				     				   #
#------------------------------------------------------------------------------#

SRC_DIR		= src
OBJ_DIR		= obj

#SRC_FILES = [list the ".c" files]
SRC_FILES			= ft_errors.c	\
					ft_op_push.c \
					ft_op_rev_rotate.c \
					ft_op_rotate.c \
					ft_op_swap.c \
					push_swap_utils.c \
					push_swap.c \
					ft_free_stack.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT_DIR	= libft
LIBFT_LIB	= /libft/libft.a

INPUT		= 1 3 5 -10 -50 87 6


#------------------------------------------------------------------------------#
#								COMPILATION 		  						   #
#------------------------------------------------------------------------------#

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -g

#------------------------------------------------------------------------------#
#								COMMANDS    		  						   #
#------------------------------------------------------------------------------#

RM= rm -f

#------------------------------------------------------------------------------#
#								BASE		 		  						   #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(call success, "All files have been compiled ✅")
	$(call text, "Creating library $(NAME) [...]")
	$(call success, "Build complete: $(NAME) 📚 ✨")       

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(call warn, "Compiling [...] $<")
	@$(CC) $(CFLAGS) -c $< -o $@


#------------------------------------------------------------------------------#
#						CREATE FILE TO LIBFT 		  						   #
#------------------------------------------------------------------------------#

$(LIBFT_LIB) : $(LIBFT_DIR)
	$(call text, "COMPILING LIBFT")
	@make -C $(LIBFT_DIR)

#------------------------------------------------------------------------------#
#								CLEAN-UP RULES 		  						   #
#------------------------------------------------------------------------------#
#	clean the .o objects
clean:
	$(call text, "Removing object files [...]")
	@$(RM) $(OBJ)
	$(call text, "Removing libft object folder [...]")
	@make clean -C $(LIBFT_DIR)
	$(call success, "		Object files cleaned. 💣"); \

# clean the .o objects, the objs folder and the project file
fclean: clean
	$(call text, "Removing files [...]")
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	$(call highligth, "FULL CLEANING DONE! ✅")

#	refresh the project
re: fclean all
	$(call success, "All files have been recompiled ✅")

#------------------------------------------------------------------------------#
#								EXTRA		 		  						   #
#------------------------------------------------------------------------------#
#________ TEMPORARY FILE TO CHECK NORMINETTE __________________________________#

TEMP_PATH	= .temp

$(TEMP_PATH):
	@mkdir -p $(TEMP_PATH)
	@echo "* $(YELLOW)Creating $(TEMP_PATH) folder:$(RESET) $(_SUCCESS)"

_SEP 			= =====================

#________		NORMINETTE			___________________________________________#

#	Run norminette on all files
norm: $(TEMP_PATH)		
# print the directory name
	@printf "${_NORM}: $(YELLOW)$(SRC_FILES)$(RESET)\n"
# list all files in the directory
	@ls $(SRC_FILES) | wc -l > $(TEMP_PATH)/norm_ls.txt
# print the number of files
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
# run norminette on all files
	@printf "$(_NORM_SUCCESS) "
# count the number of "OK" in the output
# if the output is empty, print "0"
	@norminette $(SRC_FILES) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
# if the output is not empty, print the errors
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRC_FILES) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YELLOW)Everything is OK$(RESET)]\n"; \
	fi
# if the output is empty, print "Everything is OK"
# remove the temporary files
	@echo "$(CYAN_BOLD)$(_SEP)$(RESET)"
	@make --no-print-directory norm_bonus


#________		GDB					___________________________________________#
#	Run with GDB w/ custom arg=""
gdb:				
	gdb --tui --args ./$(NAME) $(INPUT)


#________		VALGRIND			___________________________________________#
#	rule to valgrind
valgrind: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(INPUT)
	make clean
	./push_swap $(INPUT)

#------------------------------------------------------------------------------#
#								MANUAL		 		  						   #
#------------------------------------------------------------------------------#

#manual:
#	@echo "$(CYAN_BOLD)\n\t\tFT_PRINTF MANUAL$(RESET)"
#	@echo "$(CYAN_BOLD)\t---------------------------------$(RESET)"
#	@echo "$(CYAN_BOLD)\t%c$(RESET)	$(CYAN)Print a single character.$(RESET)"
#	@echo "$(CYAN_BOLD)\t%s$(RESET)	$(CYAN)Print a string.$(RESET)"

	
#------------------------------------------------------------------------------#
#								HELP MENU	 		  						   #
#------------------------------------------------------------------------------#

help:
	@echo "$(CYAN_BOLD)\n\tAVAILABLE OPTIONS:$(RESET)"
	@echo "$(CYAN_BOLD)\t---------------------------------$(RESET)"
	@echo "$(CYAN)\tmake			- Compiles the project and creates the library $(NAME).$(RESET)"
	@echo "$(CYAN)\tmake clean		- Removes object files (.o).$(RESET)"
	@echo "$(CYAN)\tmake fclean	  	- Removes object files and the library $(NAME).$(RESET)"
	@echo "$(CYAN)\tmake re			- Cleans and recompiles the project.$(RESET)"
	@echo "$(CYAN)\tmake valgrind	- To run valgrind with "--leak-check=full".$(RESET)"
	@echo "$(CYAN)\tmake help		- Displays this help message.$(RESET)"
#	@echo "$(CYAN)\tmake manual		- Displays the push_swap manual.$(RESET)"

#------------------------------------------------------------------------------#
#						COLORS AND WARNINGS		 	 						   #
#------------------------------------------------------------------------------#
# font name for titles: ANSI REGULAR
# https://patorjk.com/software/taag/#p=display&f=ANSI%20Regular&t=push_swap

# or https://www.asciiart.eu/text-to-ascii-art
# Alligator width 80

#________		DEFINING ANSI COLORS___________________________________________#

RED_BOLD	  := $(shell echo "\033[1;31m")
GREEN_BOLD	:= $(shell echo "\033[1;32m")
PURPLE  := $(shell echo "\033[0;35m")
BLUE	 := $(shell echo "\033[0;34m")
CYAN	:= $(shell echo "\033[0;36m")
CYAN_BOLD	:= $(shell echo "\033[1;36m")
RESET	:= $(shell echo "\033[0m")

#________		FUNCTIONS TO PRINT COLORS______________________________________#

text = @echo "$(PURPLE)$(1)$(RESET)"
warn = @echo "$(BLUE)$(1)$(RESET)"
error = @echo "$(RED_BOLD)$(1)$(RESET)"
success = @echo "$(GREEN_BOLD)$(1)$(RESET)"
highligth = @echo "$(CYAN)$(1)$(RESET)"
highligth_bold = @echo "$(CYAN_BOLD)$(1)$(RESET)"


#______________________________________________________________________________#
.PHONY: all clean fclean re help manual norm valgrind gdb