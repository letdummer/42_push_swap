/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 19:39:13 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_large_sort(t_stack **a, t_stack **b)
{
	t_stack	*best_move;
	t_stack	*current_b;

	while (ft_size_list(*a) > 3)
		ft_pb(a, b);
	ft_sort_three(a);
	while (*b)
	{
		ft_calculate_mov_b(b);
		current_b = *b;
		while (current_b)
		{
			ft_calculate_mov_a(a, current_b);
			ft_optimize_moves(current_b);
			current_b = current_b->next;
			if (current_b == *b)
				break ;
		}
		best_move = ft_get_min_mov(*b);
		ft_execute_moves(best_move, a, b);
	}
	ft_final_position(a, ft_size_list(*a));
}

t_stack	*ft_get_min_mov(t_stack *b)
{
	t_stack	*current;
	t_stack	*min;

	current = b;
	min = current;
	while (current)
	{
		current = current->next;
		if (current->total_steps < min->total_steps)
			min = current;
		if (current == b)
			return (min);
	}
	return (0);
}

void	ft_execute_moves(t_stack *best_move, t_stack **a, t_stack **st_b)
{
	t_stack	*b;

	while (best_move->ra-- > 0)
		ft_ra(a);
	while (best_move->rb-- > 0)
		ft_rb(st_b);
	while (best_move->rr-- > 0)
		ft_rr(a, st_b);
	while (best_move->rra-- > 0)
		ft_rra(a);
	while (best_move->rrb-- > 0)
		ft_rrb(st_b);
	while (best_move->rrr-- > 0)
		ft_rrr(a, st_b);
	ft_pa(a, st_b);
	b = *st_b;
	while (*st_b && b)
	{
		ft_init_moves(b);
		b = b->next;
		if (b == *st_b)
			break ;
	}
}
