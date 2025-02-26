/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:12:53 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/26 16:09:55 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	ft_rra(t_stack **stack_a)
{
	ft_printf("rra\n");
	ft_rev_rotate(stack_a);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_printf("rrb\n");
	ft_rev_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}
