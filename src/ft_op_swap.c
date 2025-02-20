/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:31:39 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/19 15:24:57 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		SWAP
// swap the two firsts elements of a stack
void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	ft_sa(t_stack **stack_a)
{
	ft_printf("sa\n");
	ft_swap(stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	ft_printf("sb\n");
	ft_swap(stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a);
	ft_swap(stack_b);
}
