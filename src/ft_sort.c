/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:20:14 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/21 15:41:34 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->content;
    second = (*a)->next->content;
    third = (*a)->next->next->content;

    if (first < second && second < third)
        return;
    // Caso 3 > 2 > 1
    if (first > second && second > third)
    {
        ft_sa(a);
		if (!ft_is_sorted(*a))
            ft_rra(a);
    }
    else if (first > second && second < third && first < third)
        ft_sa(a);
    else if (first < second && second > third && first < third)
    {
        ft_ra(a);
        ft_sa(a);
    }
/*     // Caso 1 > 2 > 3
    else if (first < second && second > third)
        ft_rra(a); */
    else if (first > second && second < third)
        ft_ra(a);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	second_min;

	min = ft_find_min(*a);
	ft_move_to_top(a, min);
	ft_pb(a, b);
	second_min = ft_find_min(*a);
	ft_move_to_top(a, second_min);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
}

int	ft_find_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	ft_move_to_top(t_stack **a, int min)
{
	while ((*a)->content != min)
		ft_ra(a);
}

/* void	ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_size_list(*stack_a) <= 100)
		ft_quick_sort(stack_a);
	else if (ft_size_list(*stack_a) > 100)
		ft_radix(*stack_a, *stack_b);
} */
