/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:08:36 by ldummer-          #+#    #+#             */
/*   Updated: 2025/03/02 11:10:21 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **stack)
{
	if (stack)
		ft_free_stack(stack);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*node;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		node = remove_top(stack);
		free(node);
	}
}

