/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:40:50 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/28 17:53:46 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	atol(const char *str);

void	start_stack_a(t_stack **a, char **av)
{
	long	n;
	int		i;
	
	i = 0;
	while(av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

static long int	atol(const char *str)
{
	int	i;

	i = 0;
	while(str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || 
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			
		}
	}
	
	return();
}