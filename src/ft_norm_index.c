/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 21:36:30 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	ft_find_index(t_stack *sorted_stack, int value)
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
} */

void ft_normalize(t_stack **stack)
{
	t_stack *current;
	t_stack *temp;
	int i;

	current = *stack;
	while (current)
	{
		i = 0;
		temp = *stack;
		while (temp)
		{
			if (current->content > temp->content)
				i++;
			temp = temp->next;
			if (current == *stack)
				break;
		}
		current->index = i;
		current = current->next;
	}
}
