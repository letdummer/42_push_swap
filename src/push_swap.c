/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 14:45:09 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//					MAIN					//
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
 	// call split function to handle the string
	//else if (ac == 2)
	//	av = ft_split_stack(av[1], ' ');
 
	start_stack_a(&stack_a, av + 1);
	ft_check_duplicates(&stack_a);
	
	if (ft_is_sorted(stack_a))
		ft_free_stack(&stack_a);
	ft_normalize(&stack_a);
	ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	start_stack_a(t_stack **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		//if (error_syntax(av[i]))
		//	ft_error(a);
		n = ft_atoi_ps(av[i], *a);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(a);
		//if (error_duplicate(*a, (int)n))
		//	ft_error(a);
		add_to_top(a, (int)n);
		i++;
	}
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size_list(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if (size == 5)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	/* else
		ft_sort_large(stack_a, stack_b); */
}
