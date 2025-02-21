/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:40:50 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/21 15:33:53 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	if (!stack_a|| !stack_a->next)
	return (1);
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int ft_check_duplicates(t_stack **stack)
{
	t_stack *current;
	t_stack *checker;

	if (!stack || !*stack)
		return (1);

	current = *stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
			{
				ft_error(stack);
				return (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return(0);
}


int	ft_is_valid(t_stack *a, char *str)
{
	t_stack	*tmp;
	int		n;

	if (!str || !*str)
		return 0;
	n = ft_atoi_ps(str);
	if (n == INT_MIN || n == INT_MAX)
		return 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_size_list(t_stack *stack_a)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stack_a;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	ft_atoi_ps(const char *str)
{
	long int	nb;
	int			signal;
	int			i;

	signal = 1;
	nb = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (signal * nb);
}