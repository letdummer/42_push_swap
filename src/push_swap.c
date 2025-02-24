/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/24 18:35:18 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	i = 1;
	while (av[i])
	{
		if (!ft_is_valid(&stack_a, av[i]))
			return(-1);
		i++;
	}
	stack_a = start_stack_a(stack_a, ac, av);
	
	ft_print_stack(&stack_a);					//DELETAR
	
	if (!ft_is_sorted(stack_a))
		ft_sort_stack(&stack_a, &stack_b);
	
	ft_print_stack(&stack_a);					//DELETAR
	
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
	//printf("\nATOI start:\t");
	while (av[i])
	{
		n = ft_atoi_ps(av[i]);
		//printf("| %ld ", n);
		if (n > INT_MAX || n < INT_MIN)
		{	
			ft_error(&a);
			return NULL;
		}
		add_at_last(&a, (int)n);
		i++;
	}
	//ft_print_stack\(a\);				//DELETAR
	ft_check_duplicates(&a);
	return(a);
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

/* int	ft_find_insert_position(t_stack *stack_a, int value)
{
	int	position;
	t_stack	*current;

	position = 0;
	current = stack_a;
	while (current)
	{
		if (current->content > value)
			break ;
		position++;
		current = current->next;
	}
	return (position);
} */




//DELETAR
void ft_print_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *first;

    if (!stack || !*stack)
        return;
    current = *stack;
    first = *stack;
    printf("\nSTACK:\t");
    while (current)
    {
        printf("| %d ", current->content);
        current = current->next;
        if (current == first)
            break;
    }
    printf("\n");
}

void ft_print_stacks(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *current_b;
    t_stack *first_a;
    t_stack *first_b;

    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return;
    current_a = *stack_a;
    current_b = *stack_b;
    first_a = *stack_a;
    first_b = *stack_b;

    printf("STACK A:\t");
    while (current_a)
    {
        printf("%d ", current_a->content);
        current_a = current_a->next;
        if (current_a == first_a)
            break;
    }

	  printf("\nSTACK B:\t");
    while (current_b)
    {
        printf("%d ", current_b->content);
        current_b = current_b->next;
        if (current_b == first_b)
            break;
    }
    printf("\n");
}