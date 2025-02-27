/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 19:45:09 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	i = 1;
	while (i < ac)
	{
		if (!ft_is_valid(&stack_a, av[i]))
			ft_error(&stack_a);
		i++;
	}
	stack_a = start_stack_a(stack_a, ac, av);
	if (!ft_is_sorted(stack_a))
		ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

t_stack	*start_stack_a(t_stack *a, int ac, char **av)
{
	long	n;
	int		i;

	i = 1;
	if (ac < 2 || !av || !av[0])
		ft_error(&a);
	while (i < ac)
	{
		n = ft_atoi_ps(av[i]);
		if (n == 0 && av[i][0] != '0')
		{
			ft_error(&a);
			return (NULL);
		}
		add_at_last(&a, (int)n);
		i++;
	}
	ft_check_duplicates(&a);
	return (a);
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min;

	size = ft_size_list(*stack_a);
	if (size == 2 && !ft_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		min = ft_find_min_value(*stack_a);
		ft_move_to_top(stack_a, min);
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (size > 5)
		ft_large_sort(stack_a, stack_b);
}
