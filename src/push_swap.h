/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:13:20 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/28 11:42:34 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*  						 LIBRARYS	                                      */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/libftprintf.h"
#include <unistd.h>			// read()	/	write()
#include <stdlib.h>			// malloc()	/	free()	/ exit()
#include <limits.h>			// INT_MAX	/	INT_MIN
#include <stdbool.h>		// true	/	false

/* ************************************************************************** */
/*  							 STRUCT                                       */
/* ************************************************************************** */

typedef struct s_stack
{
	int				nb;

	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

/* ************************************************************************** */
/*  						 FUNCTIONS	                                      */
/* ************************************************************************** */

//int		main(int ac, char **av);

// handle errors
//void	ft_error(t_stack *stack, int ac, char **av);

// stack initialization
char	**split(char *str, char c);



// nodes initialization

// stack utils
void	add_to_top(t_stack **stack, t_stack *new_node);
t_stack	*remove_top(t_stack **stack);
t_stack	*remove_last(t_stack **stack);
void	add_at_last(t_stack **stack, t_stack *new_node);

	// swap operations
void	swap(t_stack **stack);	
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


#endif