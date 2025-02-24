/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RESERVA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/24 20:23:27 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_large_sort(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*best_move;

	size = ft_size_list(*a);
	while (size > 3)
	{
		ft_pb(a, b);
		size--;
	}
	ft_sort_three(a);
/* 	while (*b)
	{
		ft_calculate_mov_b(b);
		
		//printf("CONT A:\t%d\n", (*a)->content);
		//printf("CONT B:\t%d\n", (*b)->content);
		//ft_print_stacks(a, b);
		
		if ((*b)->content < (*a)->content && (*b)->content > (*a)->prev->content)
			ft_pa(a, b);
		else if ((*b)->content > (*a)->content && (*b)->content > (*a)->prev->content && (*a)->content < (*a)->prev->content) // novo maximo em A
			ft_pa(a, b);
		else if ((*b)->content < (*a)->content && (*b)->content < (*a)->prev->content && (*a)->content < (*a)->prev->content) // novo min em A
			ft_pa(a, b);
		else 
			ft_ra(a);
		printf("\n____________________\n");
		ft_print_stacks(a, b);
	} */
	while (*b)
	{
		printf("BEFORE CALCULATE TOTAL COST:\n");
		ft_print_stacks(a,b);
		ft_calculate_total_cost(a, b);
		printf("\n\nBEFORE FIND BEST MOVE:\n");
		ft_print_stack(b);
		best_move = ft_find_best_move(*b);

		/* if (best_move->ra)
			ft_ra(a);
		else if (best_move->rra)
			ft_rra(a);
		ft_pa(a, b);
	}
	while ((*a)->content > (*a)->prev->content)
		ft_rra(a); */
		while (best_move->ra && best_move->rb)
		{
			ft_rr(a, b);
			best_move->ra--;
			best_move->rb--;
		}
		while (best_move->rra && best_move->rrb)
		{
			ft_rrr(a, b);
			best_move->rra--;
			best_move->rrb--;
		}
		// Execute remaining rotations
		while (best_move->ra--)
			ft_ra(a);
		while (best_move->rb--)
			ft_rb(b);
		while (best_move->rra--)
			ft_rra(a);
		while (best_move->rrb--)
			ft_rrb(b);
		ft_pa(a, b);
	}
	// Final alignment - rotate until minimum is at top
	size = ft_size_list(*a);
	int min_pos = ft_get_min_position(*a);
	if (min_pos <= size / 2)
		while (min_pos--)
			ft_ra(a);
	else
		while (size - min_pos++)
			ft_rra(a);
}

void	ft_calculate_mov_b(t_stack **stack)
{
	t_stack	*c;
	int	i;
	int	size;

	c = *stack;
	i = 0;
	size = ft_size_list(*stack);
	while (c) // enquanto stack anterior for diferente da stack atual
	{
		if (i <= size / 2)
			c->rb = i;
		else
			c->rrb = size - i;
		i++;
		c = c->next;		
		if (c == *stack)	// se chegar ao fim da lista circular, quebra o loop
			break ;
	}
}

t_stack	*ft_find_best_move(t_stack *b)
{
	t_stack	*current;
	t_stack	*best_move;
	int		min_steps;

	if (!b)
	return (NULL);
	current = b;
	best_move = b;
	min_steps = b->total_steps;
	current = current->next;
	while (current != b)
	{
		// verifica se o elemento atual tem menos passos totais
		if (current->total_steps < min_steps)
		{
			best_move = current;
			min_steps = current->total_steps;	// atualiza os passos minimos
		}
		current = current->next;
	}
	return(best_move);
}

void ft_calculate_cost_a(t_stack **a, t_stack *b)
{
    t_stack *current_a;
    int i;
    int size;
    int min;
    int max;

    current_a = *a;
    i = 0;
    size = ft_size_list(*a);
    b->ra = 0;
    b->rra = 0;
    
    min = ft_find_min(*a);
    max = ft_find_max(*a);
    
    // If b is new min or max
    if (b->content < min)
    {
        i = ft_get_min_position(*a);
        if (i <= size / 2)
            b->ra = i;
        else
            b->rra = size - i;
        return;
    }
    if (b->content > max)
    {
        i = ft_get_min_position(*a);
        if (i <= size / 2)
            b->ra = i;
        else
            b->rra = size - i;
        return;
    }

    // Find position between numbers
    while (current_a)
    {
        if ((current_a->content < b->content && current_a->next->content > b->content))
        {
            if (i <= size / 2)
                b->ra = i + 1;
            else
                b->rra = size - i - 1;
            return;
        }
        i++;
        current_a = current_a->next;
        if (current_a == *a)
            break;
    }
}


void ft_calculate_total_cost(t_stack **a, t_stack **b)
{
    t_stack *current;
    int ra, rb, rra, rrb;

    ft_calculate_mov_b(b);
    current = *b;
    
    while (current)
    {
        ft_calculate_cost_a(a, current);
        ra = current->ra;
        rb = current->rb;
        rra = current->rra;
        rrb = current->rrb;

        // Calculate most efficient combination
        if (ra && rb)
            current->total_steps = ft_get_max_moves(ra, rb);
        else if (rra && rrb)
            current->total_steps = ft_get_max_moves(rra, rrb);
        else
            current->total_steps = ra + rb + rra + rrb;

        current = current->next;
        if (current == *b)
            break;
    }
}

// Função auxiliar para retornar o maior entre dois valores
int ft_get_max_moves(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int ft_get_min_position(t_stack *stack)
{
	t_stack *current;
	int	 min;
	int	 pos;
	int	 min_pos;

	if (!stack)
		return (0);
	current = stack;
	min = current->content;
	pos = 0;
	min_pos = 0;
	
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_pos = pos;
		}
		current = current->next;
		pos++;
		if (current == stack)
			break;
	}
	return (min_pos);
}

int	ft_find_max(t_stack *stack)
{
    t_stack *current;
    int     max;

    if (!stack)
        return (0);
    current = stack;
    max = current->content;
    do
    {
        if (current->content > max)
            max = current->content;
        current = current->next;
    } while (current != stack);
	printf("MAX A: %d\t", max);
	return (max);
}

int	ft_find_min(t_stack *stack)
{
    t_stack	*current;
    int		min;

    if (!stack)
        return (0);
    current = stack;
    min = current->content;
    current = current->next;
    while (current != stack)
    {
        if (current->content < min)
            min = current->content;
        current = current->next;
    }
	printf("MIN A: %d\n", min);
    return (min);
}