ROOT=..
TIME_LIMIT=1

TRACE=./trace_basic
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

make -C $ROOT

clear

confirm() {
    read -r -p "${1:-Continue? [y/N]} " response
    case "$response" in
        [yY][eE][sS]|[yY]) 
            clear
            ;;
        *)
			printf "EXIT\n"
            exit 0
            ;;
    esac
}

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in basic_test.sh is correct\n"
	exit 1
fi

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

printf "_____________ERROR_______________TEST_____________\n\n"

for ((i=1;i<=15;i++));
do
	printf "test_case_$i\n\n"
	printf "one number per argument : \n\n"
	($ROOT/push_swap $(cat $TRACE/error_files/test_case_$i.txt) > stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	if [[ -s stdout ]];
	then
		printf "${RED}KO, stdout must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		printf "${GREEN}OK${NOCOLOR}\n"
	fi
	if [[ -s stderr ]];
	then
		printf "Error\n" > e
		diff e stderr > x
		if [[ -s x ]]
		then
			printf "${RED}KO, Output message in stderr is wrong\n${NOCOLOR}"
		else
			printf "${GREEN}OK${NOCOLOR}\n"
		fi
		rm -rf e x
	else
		printf "${RED}KO, \"Error\" must be written in stderr followed by a newline${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	fi
	rm -rf stdout stderr a b
	# Substituindo 'leaks' por 'valgrind' aqui
	valgrind --leak-check=full --error-exitcode=1 --quiet --log-file=valgrind.log $ROOT/push_swap $(cat $TRACE/error_files/test_case_$i.txt) 1>a 2>b & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep "0 bytes in 0 blocks are definitely lost" valgrind.log > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="Valgrind command not found"
			LEAKFLAG="Valgrind command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n"
	rm -rf valgrind.log x y
	printf "\none argument\n\n"
	($ROOT/push_swap "$(cat $TRACE/error_files/test_case_$i.txt)" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	if [[ -s stdout ]];
	then
		printf "${RED}KO, stdout must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		printf "${GREEN}OK${NOCOLOR}\n"
	fi
	if [[ -s stderr ]];
	then
		printf "Error\n" > e
		diff e stderr > x
		if [[ -s x ]]
		then
			printf "${RED}KO, Output message in stderr is wrong\n${NOCOLOR}"
		else
			printf "${GREEN}OK${NOCOLOR}\n"
		fi
		rm -rf e x
	else
		printf "${RED}KO, \"Error\" must be written in stderr followed by a newline${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	fi
	rm -rf stdout stderr
	# Substituindo 'leaks' por 'valgrind' aqui também
	valgrind --leak-check=full --error-exitcode=1 --quiet --log-file=valgrind.log $ROOT/push_swap "$(cat $TRACE/error_files/test_case_$i.txt)" 1>a 2>b & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep "0 bytes in 0 blocks are definitely lost" valgrind.log > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="Valgrind command not found"
			LEAKFLAG="Valgrind command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf valgrind.log x y
done

printf "\n\nERROR_TEST\n\nresult : $FLAG\nmemory : $LEAKFLAG\n\n\n"

confirm

