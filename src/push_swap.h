/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:13:20 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 23:36:42 by ldummer-         ###   ########.fr       */
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
# include <limits.h>			// INT_MAX	/	INT_MIN
# include <stdbool.h>		// true	/	false

/* ************************************************************************** */
/*  							 STRUCT                                       */
/* ************************************************************************** */

typedef struct s_stack
{
	int				content;
	int				index;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ************************************************************************** */
/*  						 FUNCTIONS	                                      */
/* ************************************************************************** */

//int		main(int ac, char **av);

	// handle errors
void	ft_error(t_stack **stack);
void	ft_free_stack(t_stack **stack);
void	free_split(char **split);

// stack initialization
char	**split_stack(char *str, char c);
t_stack	*start_stack_a(t_stack *a, int ac, char **av);

	// check argsint	
int		ft_is_sorted(t_stack *stack_a);
int		ft_atoi_ps(const char *str);
int		ft_is_valid(t_stack **a, char *str);
int		ft_check_duplicates(t_stack **stack);

	// stack utils
t_stack	*create_node(int value);
void	add_to_top(t_stack **stack, int value);
t_stack	*remove_top(t_stack **stack);
int		ft_size_list(t_stack *stack_a);
void	add_at_last(t_stack **stack, int value);
//t_stack	*remove_last(t_stack **stack);

	// swap operations
void	ft_swap(t_stack **stack);	
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

	// push operations
void	ft_push(t_stack **from, t_stack **to);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

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

	// algorithms

void	ft_normalize(t_stack **stack);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **a);
void	ft_sort_five(t_stack **a, t_stack **b);
int		ft_find_min(t_stack *stack);
void	ft_move_to_top(t_stack **a, int min);

//int		ft_find_index(t_stack *sorted_stack, int value);
//void	ft_sort_large(t_stack **stack_a, t_stack **stack_b);
//void	ft_quick_sort(t_stack **stack);
//void	ft_radix(t_stack *a, t_stack *b);
//void ft_radix(t_stack **a, t_stack **b);
void	ft_large_sort(t_stack **a, t_stack **b);

void ft_print_stacks(t_stack **stack_a, t_stack **stack_b);		//DELETARRRR
void ft_print_stack(t_stack **stack);							//DELETARRRR
#endif