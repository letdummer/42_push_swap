/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 16:02:35 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char    **args;
    int     i;

    stack_a = NULL;
    stack_b = NULL;

    if (ac == 1)
        exit(0);

    if (ac == 2 && (!av[1][0] || count_word(av[1], ' ') == 1))
    {
        write(2, "Error\n", 6);
        return (1);
    }

    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!args)
        {
            write(2, "Error\n", 6);
            return (1);
        }
    }
    else
        args = av;

    i = (ac == 2) ? 0 : 1;	///MUDAR, ELIMINAR TERNARIO
    while (args[i])
    {
        if (!ft_is_valid(&stack_a, args[i]))
        {
            if (ac == 2)
                free_split(args);
            write(2, "Error\n", 6);
            return (1);
        }
        i++;
    }

    stack_a = start_stack_a(stack_a, ac, args);
	
    if (!ft_is_sorted(stack_a))
        ft_sort_stack(&stack_a, &stack_b);

    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    if (ac == 2)
        free_split(args);

    return (0);
}


t_stack	*start_stack_a(t_stack *a, int ac, char **av)
{
	long	n;
	int		i;
	
	i = 0;
	if (ac < 2 || !av || !av[0])
		ft_error(&a);
	while (av[i])
	{
		n = ft_atoi_ps(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{	
			ft_error(&a);
			return NULL;
		}
		add_at_last(&a, (int)n);
		i++;
	}
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

/* 

void	ft_print_moves(t_stack **stack)
{
	t_stack *current;
	
	current = *stack;

	printf("RA  =>\t %d \n", current->ra);
	printf("RB  =>\t %d \n", current->rb);
	printf("RR  =>\t %d \n", current->rr);
	printf("RRA =>\t %d \n", current->rra);
	printf("RRB =>\t %d \n", current->rrb);
	printf("RRR =>\t %d \n", current->rrr);


    printf("\n");
}



//DELETAR
void ft_print_stack(t_stack **stack, char c)
{
    t_stack *current;
    t_stack *first;

    if (!stack || !*stack)
        return;
    current = *stack;
    first = *stack;
    if (c == 'a')
		printf("STACK A:\t");
    else if (c == 'b')
		printf("STACK B:\t");
	else
		printf("STACK %c:\t", c);
		
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

	  printf("STACK B:\t");
    while (current_b)
    {
        printf("%d ", current_b->content);
        current_b = current_b->next;
        if (current_b == first_b)
            break;
    }
    printf("\n");
}

 */