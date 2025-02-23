/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:40:50 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/23 22:07:09 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{ 
	t_stack	*first;
	
	if (!stack_a)
		return (1);
	first = stack_a;
	while (stack_a->next != first)
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
	while (current->next != *stack)
	{
		checker = current->next;
		while (checker->next != *stack)
		{
			if (current->content == checker->content)
			{
				ft_error(stack);
				exit (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return(0);
}

int	ft_is_valid(t_stack **a, char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return((ft_error(a)), 0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return((ft_error(a)), 0);
		i++;
	}
	return(1);	
}
/* int	ft_is_valid(t_stack *a, char *str)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->content == ft_atoi_ps(str))
			return (0);
		tmp = tmp->next;
	}
	return (1);
} */

int	ft_size_list(t_stack *stack_a)
{
	int		i;
	t_stack	*node;

	i = 0;
	if (!stack_a)
		return (0);
	node = stack_a;
	while (node->next != stack_a)
	{
		i++;
		node = node->next;
	}
	return (i + 1);
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
//	printf("CONVERTENDO: %s\n", str);  // DEBUG
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if ((nb * signal) > 2147483647 || (nb * signal) < -2147483648)
		ft_error(NULL);
	return (signal * nb);
}
