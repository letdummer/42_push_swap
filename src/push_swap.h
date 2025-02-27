/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:13:20 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 19:45:27 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*  						 LIBRARYS	                                      */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"
# include <unistd.h>			// read()	/	write()
# include <stdlib.h>			// malloc()	/	free()	/ exit()

/* ************************************************************************** */
/*  							 STRUCT                                       */
/* ************************************************************************** */

typedef struct s_stack
{
	int				content;

	struct s_stack	*next;
	struct s_stack	*prev;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_steps;
}	t_stack;

/* ************************************************************************** */
/*  						 FUNCTIONS	                                      */
/* ************************************************************************** */

int		main(int ac, char **av);

	// stack initialization
t_stack	*start_stack_a(t_stack *a, int ac, char **av);
char	**split_stack(char *str, char c);
int		count_word(char *str, char c);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

	// check args	
int		ft_is_valid(t_stack **a, char *str);
int		ft_is_sorted(t_stack *stack_a);
int		ft_check_duplicates(t_stack **stack);
int		ft_size_list(t_stack *stack_a);
int		ft_atoi_ps(const char *str);

	// handle errors and free stack
void	ft_error(t_stack **stack);
void	ft_free_stack(t_stack **stack);
void	free_split(char **split);

	// list utils
t_stack	*create_node(int value);
void	add_to_top(t_stack **stack, int value);
void	add_at_last(t_stack **stack, int value);
t_stack	*remove_top(t_stack **stack);

	// push operations
void	ft_push(t_stack **from, t_stack **to);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

	// swap operations
void	ft_swap(t_stack **stack);	
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

	// rotate operations
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rb(t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rotate(t_stack **stack);

	// reverse rotate operations
void	ft_rev_rotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

	// sort elements
void	ft_sort_three(t_stack **a);
void	ft_sort_five(t_stack **a, t_stack **b);
int		ft_find_min_value(t_stack *stack);
void	ft_move_to_top(t_stack **a, int min);

	// algorithms
void	ft_large_sort(t_stack **a, t_stack **b);
void	ft_calculate_mov_a(t_stack **stack, t_stack *stack_b);
void	ft_calculate_mov_b(t_stack **stack);
t_stack	*ft_total_moves(t_stack *b);
void	ft_execute_moves(t_stack *best_move, t_stack **a, t_stack **st_b);
int		ft_check_pa(t_stack *a, t_stack *b);

t_stack	*ft_get_min_mov(t_stack *b);
void	ft_final_position(t_stack **a, int size);
void	ft_init_moves(t_stack *node);

void	ft_optimize_moves(t_stack *b);
void	ft_optimize_single_rotations(t_stack *single);
void	ft_optimize_rev_rotations(t_stack *rev_rot);
void	ft_optimize_rotations(t_stack *rot);

#endif