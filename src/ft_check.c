/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:40:50 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/20 12:06:37 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack	*node;

	if (stack_a == NULL || stack_a->next == NULL)
		return (1);
	node = stack_a;
	while (node->next != NULL)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

void ft_check_duplicates(t_stack **stack)
{
	t_stack *current;
	t_stack *checker;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
			{
				ft_error(stack);
				return;
			}
			checker = checker->next;
		}
		current = current->next;
	}
}


int	ft_is_valid(t_stack *a, char *str)
{
	t_stack	*tmp;
	int		n;

	tmp = a;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	n = ft_atoi_ps(str, a);
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

int	ft_atoi_ps(const char *str, t_stack *stack_a)
{
	long long int	res;
	int				signal;

	signal = 1;
	res = 0;
	while (*str == '\t' || *str == ' ' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		signal *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error(&stack_a);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(&stack_a);
		res = (res * 10) + (*str - 48);
		str++;
	}
	if (((signal * res) > 2147483647) || ((signal * res) < -2147483648))
		ft_error(&stack_a);
	return (signal * res);
}