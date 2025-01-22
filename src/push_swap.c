/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:34:27 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/22 17:59:39 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
type ft_check_input()
{}
*/

/*
type ft_free_stack()
{}
*/

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return(1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	// call split function to handle the string

	// iniciar stack_a
	// lidar com erros como overflow, duplicatas, syntax error, conter somente digitos, ou sinais como '-' ou '+'
	// se houverem erros, dar free na stack_a e chamar ft_error

	// checar se casa input eh um long int
		// se o input for uma string, converter para long int
	// acrescentar o no na stack_a

	// checar se a stack_a esta ordenada
		// se nao estiver, chamar a funcao de ordenacao
			// se tiver 2 numeros
				// simplismente dar swap
			// se tiver 3 numeros
				// implementar funcao para "ordenar tres"
			// se tiver mais que 3 numeros
				// implementar algoritmo Turk
	

	// free stack_a
	// free stack_b
	return (0);
}

/*
	BASIC UTILS

	* functions to handle errors
	* functions for the operations
	* stack length
	* last node
	* min and max nodes
		




*/



/*				tests			*/

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("TEST\n");
		printf("%d ", stack->nb);
		stack = stack->next;
	}
	printf("\n");
}
