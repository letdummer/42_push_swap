/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:06:43 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 22:27:16 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
		*stack = (*stack)->next;
}

void	ft_ra(t_stack **stack_a)
{
	ft_printf("ra\n");
	ft_rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	ft_printf("rb\n");
	ft_rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
