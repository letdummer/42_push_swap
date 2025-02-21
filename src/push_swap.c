/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:43 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_print_stack(t_stack *stack);
void ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_a = start_stack_a(stack_a, ac, av);
	ft_print_stack(stack_a);					//DELETAR
	if (!ft_is_sorted(stack_a))
	{
		if (ft_size_list(stack_a) > 5)
			ft_normalize(&stack_a);				//DELETAR
		ft_sort_stack(&stack_a, &stack_b);
	}
	
	ft_print_stack(stack_a);					//DELETAR
	
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
	printf("\nATOI start:\t");
	while (av[i])
	{
		n = ft_atoi_ps(av[i]);
		printf("| %ld ", n);
		if (n > INT_MAX || n < INT_MIN)
		{	
			ft_error(&a);
			return NULL;
		}
		if(!ft_is_valid(a, av[i]))
			ft_error(&a);
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

	size = ft_size_list(*stack_a);

	if (size == 2 && !ft_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}	
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (size > 5)
	{
		// quick_sort/radix
	}
}



int	ft_find_insert_position(t_stack *stack_a, int value)
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
}




//DELETAR
void ft_print_stack(t_stack *stack)
{
    t_stack *current;

    current = stack;
	printf("\n\nSTACK:\t");
    while (current != NULL)
    {
        printf("| %d ", current->content);
        current = current->next;
    }
    printf("\n");
}

void ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_a;
    t_stack *current_b;

    current_a = stack_a;
    current_b = stack_b;

    printf("\nSTACK A:\t");
    while (current_a != NULL)
    {
        printf("%d ", current_a->content);
        current_a = current_a->next;
    }

    printf("\nSTACK B:\t");
    while (current_b != NULL)
    {
        printf("%d ", current_b->content);
        current_b = current_b->next;
    }
    printf("\n");
}