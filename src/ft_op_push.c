/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:47:00 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 19:23:58 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from)
		return ;
	node = remove_top(from);
	if (!node)
		return ;
	add_to_top(to, node->content);
	free(node);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	ft_push(stack_b, stack_a);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	ft_push(stack_a, stack_b);
}
