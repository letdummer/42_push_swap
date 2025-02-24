/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:20:14 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/24 18:33:08 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	while(!ft_is_sorted(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		if (first > second && second > third)
		{
			ft_sa(a);
			ft_rra(a);
		}
		else if (first < second && second > third)
			ft_rra(a);
		else if (first > second && second < third && first < third)
			ft_sa(a);
		else if (first < second && second > third && first < third)
		{
			ft_ra(a);
			ft_sa(a);
		}
		else if (first > second && second < third)
			ft_ra(a);
	}
	return ;
}

void ft_sort_five(t_stack **a, t_stack **b)
{
	int min, second_min;

	min = ft_find_min_value(*a);
	ft_move_to_top(a, min);
	ft_pb(a, b);
	second_min = ft_find_min_value(*a);
	ft_move_to_top(a, second_min);
	ft_pb(a, b);
	ft_sort_three(a);	
	ft_pa(a, b);
	ft_pa(a, b);
	if (!ft_is_sorted(*a))
	{
		if ((*a)->content > (*a)->next->content)
			ft_ra(a);
	}
}

int ft_find_min_value(t_stack *stack)
{
	int min;
	t_stack *first;

	if (!stack)
		return (0);
	first = stack;
	min = stack->content;
	while (stack->next != first)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	if (stack->content < min)
		min = stack->content;
	return (min);
}

void ft_move_to_top(t_stack **a, int min)
{
	t_stack *tmp = *a;
	int i = 0;
	while (tmp)
	{
		if (tmp->content == min)
			break;
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		return;
	if (i <= ft_size_list(*a) / 2)
	{
		while ((*a)->content != min)
			ft_ra(a);
	}
	else
	{
		while ((*a)->content != min)
			ft_rra(a);
	}
}
