/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:55 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 11:25:43 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->next = NULL;
	return (new_node);
}

// function that add a new node at the top of the list
void	add_to_top(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

// remove the first element of the stack and return it
t_stack	*remove_top(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;

	top->next = NULL;
	top->prev = NULL;
	return (top);
}

// add a new node to the end of the stack
void	add_at_last(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

// remove the last element of the stack and return it
t_stack	*remove_last(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	current = *stack;
	while (current->next && current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	return (last);
}
