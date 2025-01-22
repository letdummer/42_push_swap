/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:31:39 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/22 20:22:40 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		SWAP
// swap the two firsts elements of a stack
void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	
	if (!stack || !*stack || !(*stack)->next)
		return (1);
	first = *stack;
	second = first->next;

	first->next = second->next;
	if(second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;

	*stack = second;
}

void	ft_sa(t_stack **stack_a)
{
	ft_printf("sa\n");
	swap(stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	ft_printf("sb\n");
	swap(stack_b);	
}
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	swap(stack_a);	
	swap(stack_b);	
}