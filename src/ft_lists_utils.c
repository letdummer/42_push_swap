/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:55 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 23:36:49 by ldummer-         ###   ########.fr       */
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
	new_node->prev = NULL;
	return (new_node);
}

// function that add a new node at the top of the list
void	add_to_top(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	
	if (!new_node)
		return ;
	if (!*stack)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

// add a new node to the end of the stack
// also updates pointers on the top of the stack
// 	temp = (*stack)->prev => Set tmp = to the last value of the stack
void	add_at_last(t_stack **stack, int value)
{
	t_stack *new_node;
	t_stack *temp;

	new_node = create_node(value);
	if (!new_node)
		return;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return;
	}
	temp = (*stack)->prev;
	temp->next = new_node;
	new_node->prev = temp;	
	temp = *stack;
	temp->prev = new_node;
	new_node->next = temp;
}

// remove the first element of the stack and return it
t_stack	*remove_top(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	if((*stack)->next == *stack)
	{
		*stack = NULL;
		return(top);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	*stack = (*stack)->next;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}

// remove the last element of the stack and return it
/* t_stack	*remove_last(t_stack **stack)
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
} */
