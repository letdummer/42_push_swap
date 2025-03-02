/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:44 by ldummer-          #+#    #+#             */
/*   Updated: 2025/03/01 18:30:41 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_mov_b(t_stack **stack_b)
{
	t_stack	*top;
	int		i;
	int		size;

	i = 0;
	top = *stack_b;
	size = ft_size_list(*stack_b);
	while (top)
	{
		top->rb = i;
		top->rrb = size - i;
		if (i == 0)
			top->rrb = 0;
		i++;
		top = top->next;
		if (top == *stack_b)
			break ;
	}
}

void	ft_calculate_mov_a(t_stack **stack_a, t_stack *current_b)
{
	t_stack	*a;
	int		i;
	int		size;

	i = 0;
	a = *stack_a;
	size = ft_size_list(*stack_a);
	while (a)
	{
		if (ft_check_pa(a, current_b) == 1)
		{
			current_b->ra = i;
			current_b->rra = size - i;
			if (i == 0)
				current_b->rra = 0;
			return ;
		}
		i++;
		a = a->next;
		if (a == *stack_a)
			break ;
	}
}

int	ft_check_pa(t_stack *a, t_stack *b)
{
	if (b->content < a->content && b->content > a->prev->content)
		return (1);
	else if (b->content > a->content && b->content > a->prev->content
		&& a->content < a->prev->content)
		return (1);
	else if (b->content < a->content && b->content < a->prev->content
		&& a->content < a->prev->content)
		return (1);
	else
		return (0);
}

// calculates total moviments
t_stack	*ft_total_moves(t_stack *current)
{
	current->total_steps = current->rb + current->rrb + current->ra
		+ current->rra + current->rrr + current->rr;
	return (current);
}

void	ft_final_position(t_stack **a, int size)
{
	t_stack	*current_a;
	int		best_final_position;

	best_final_position = 0;
	current_a = *a;
	while (current_a->content > current_a->prev->content)
	{
		best_final_position++;
		current_a = current_a->next;
	}
	while ((*a)->content > (*a)->prev->content)
	{
		if (best_final_position < size / 2)
			ft_ra(a);
		else
			ft_rra(a);
	}
}
