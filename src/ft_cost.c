/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:30 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/24 19:35:33 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_large_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_size_list(*a);
	while (size > 3)
	{
		ft_pb(a, b); // Move os elementos de A para B
		size--;
	}

	ft_sort_three(a); // Ordena os 3 elementos restantes em A

	// Primeira etapa: Apenas calcular os movimentos necessários em B
	t_stack *tmp = *b;
	while (tmp)
	{
		ft_calculate_mov(&tmp);
		tmp = tmp->next;
		if (tmp == *b)
			break; // Evita loop infinito na pilha circular
	}

	// Segunda etapa: Agora ordenar e mover os elementos de B para A
	while (*b)
	{
		ft_calculate_mov(b);

		// Determinar onde inserir em A e executar os movimentos
		if ((*b)->content < (*a)->content && (*b)->content > (*a)->prev->content)
			ft_pa(a, b);
		else if ((*b)->content > (*a)->content && (*b)->content > (*a)->prev->content && (*a)->content < (*a)->prev->content) // Novo máximo em A
			ft_pa(a, b);
		else if ((*b)->content < (*a)->content && (*b)->content < (*a)->prev->content && (*a)->content < (*a)->prev->content) // Novo mínimo em A
			ft_pa(a, b);
		else 
			ft_ra(a);
	}

	// Garantir que A fique alinhado corretamente
	while ((*a)->content > (*a)->prev->content)
		ft_rra(a);
}


void	ft_calculate_mov(t_stack **stack)
{
	t_stack	*c;
	int	i;
	int	size;

	c = *stack;
	i = 0;
	size = ft_size_list(*stack);
	while (c) 
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