/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:08:36 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 18:24:59 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **stack)
{
	ft_free_stack(stack);
	write(2, "Error\n", 6);
	return ;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack *node;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		node = remove_top(stack);
		free(node);
	}
}

int	ft_is_empty(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	else
		return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}