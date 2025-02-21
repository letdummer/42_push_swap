/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:06:43 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:06 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	top = remove_top(stack);
	add_at_last(stack, top->content);
	free(top);
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
