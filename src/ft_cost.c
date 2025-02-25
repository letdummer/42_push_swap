/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/25 19:30:14 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_large_sort(t_stack **a, t_stack **b)
{
	int	size;
	t_stack	*best_move;
	t_stack *current_b;

	size = ft_size_list(*a);
	while (size > 3)
	{
		ft_pb(a, b);
		size--;
	}
	ft_print_stack(b, 'b');
	ft_sort_three(a);
	while(*b)
	{	
		ft_calculate_mov_b(b);
		current_b = *b;
		while (current_b)
		{
			ft_calculate_mov_a(a, current_b);
			current_b = current_b->next;
			if (current_b == *b)
				break;
		}
		//current_b = *b;

		best_move = ft_get_min_mov(*b);
		ft_print_stack(a, 'a');
		ft_print_stack(b, 'b');
		printf("BEST_MOVE content => %d\n", best_move->content);
		ft_execute_moves(best_move, a, b);
	}
	// Garantir que A fique alinhado corretamente
	while ((*a)->content > (*a)->prev->content)
		ft_rra(a);
}


void	ft_calculate_mov_b(t_stack **stack_b)
{
	t_stack	*top;
	int	i;
	int	size;

	i = 0;
	top = *stack_b;
	size = ft_size_list(*stack_b);
	while (top) 
	{
		if (i <= size / 2){
			top->rb = i;
		//	printf("RB: %d\n", i);
		}
		else{
			top->rrb = size - i;
		//printf("RRB: %d\n", size - i);
		}
		i++;
		top = top->next;		
		if (top == *stack_b)	// se chegar ao fim da lista circular, quebra o loop
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
	while(a)
	{
		if (ft_check_pa(a, current_b) == 1) 
		{
			current_b->ra = i;
			current_b->rra = size - i;
			if (current_b->ra > current_b->rra)
				current_b->ra = 0;
			else
				current_b->rra = 0;
			return;
		}
		i++;
		//ft_printf("B a inserir = %d\n", current_b->content);
		ft_print_stack(&a, 'a');
		a = a->next;
		if (a == *stack_a)
		{	
			printf("Nao foi encontrada posiaco para o numero: %d na stack A\n", current_b->content);
			break ;
		}
	}
}

int	ft_check_pa(t_stack *a, t_stack *b)
{
	if (b->content < a->content && b->content > a->prev->content)
		return(1);
	else if (b->content > a->content && b->content > a->prev->content && a->content < a->prev->content) // Novo máximo em A
		return(1);
	else if (b->content < a->content && b->content < a->prev->content && a->content < a->prev->content) // Novo mínimo em A
		return(1);
	else 
		return(0);
}

t_stack *ft_get_min_mov(t_stack *b) // os asteriscos podem estar errados, verificar os apontadores ** ou *
{
	t_stack *current;// os asteriscos podem estar errados, verificar os apontadores ** ou *
	t_stack *min;// os asteriscos podem estar errados, verificar os apontadores ** ou *
	
	ft_total_moves(b);
	current = b;
	min = current;
	while(current)
	{
		if (current->total_steps < min->total_steps )
			min = current;
		current = current->next;
	//	printf("\nStack with min moves: ");
	//	ft_print_stack(min, 'm');
		if (current == b)
			return(min);
	}
	return (0);
}


// calculates total moviments (+1 is for ft_pa)
void	ft_total_moves(t_stack *b)
{
	t_stack	*current;

	current = b;
	while (b)
	{
		current->total_steps = current->rb + current->rrb + current->ra + current->rra;
		current = current->next;
		if (current == b)
			break;
	}
}

void	ft_execute_moves(t_stack *best_move, t_stack **stack_a, t_stack **stack_b)
{
	t_stack *b;
	
	ft_print_moves(stack_b);
	while (best_move->ra-- > 0)
		ft_ra(stack_a);
	while (best_move->rb-- > 0)
		ft_rb(stack_b);
	while (best_move->rra-- > 0)
		ft_rra(stack_a);
	while (best_move->rrb-- > 0)
		ft_rrb(stack_b);	
	ft_pa(stack_a, stack_b);
	b = *stack_b;
	while (*stack_b)
	{
		b->ra = 0;
		b->rb = 0;
		b->rra = 0;
		b->rrb = 0;
		b->total_steps = 0;
		b = b->next;
		if (b == *stack_b)
			break ;
	}
}
