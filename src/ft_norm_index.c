/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 14:45:32 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_stack *sorted_stack, int value)
{
	int	index;

	index = 0;
	while (sorted_stack)
	{
		if (sorted_stack->content == value)
			return (index);
		index++;
		sorted_stack = sorted_stack->next;
	}
	return (-1);
}

void	ft_normalize(t_stack **stack)
{
	t_stack	*current;
	t_stack	*sorted_stack;

	if (!stack || !*stack)
		return ;
	sorted_stack = NULL;
	current = *stack;
	while (current)
	{
		add_to_top(&sorted_stack, current->content);
		current = current->next;
	}
	//ft_quick_sort(&sorted_stack);
	current = *stack;
	while (current)
	{
		current->content = ft_find_index(sorted_stack, current->content);
		current = current->next;
	}
	ft_free_stack(&sorted_stack);
}
