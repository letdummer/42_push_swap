/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:55 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/22 20:02:59 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that add a new node at the top of the list
// stack is a pointer to the top of the list
// new_node is the pointer to be added to the top
void	add_to_top(t_stack **stack, t_stack *new_node)
{
	if(!stack || !new_node)
		return;
	new_node->next = *stack;
	if(*stack)
		(*stack)->prev = new_node;
	new_node->prev = NULL;
	*stack = new_node;
}

// remove the first element of the stack and return it
t_stack	*remove_top(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return(NULL);
	top = *stack;
	*stack = top->next;
	if(*stack)
		(*stack)->prev = NULL;
	top->next = NULL;
	return(top);
}

// remove the last element of the stack and return it
t_stack	*remove_last(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack)
		return(NULL);
	last = *stack;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	else
		*stack = NULL;
	last->prev = NULL;
	return(last);
}

// add a new node to the end of the stack
void	add_at_last(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!stack || !new_node)
		return;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	new_node->next = NULL;
}