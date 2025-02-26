/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:44 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/26 10:38:51 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_word(char *str, char c);
static int	count_word(char *str, char c);

char	**split_stack(char *str, char c)
{
	int		word_count;
	char	**result_array;
	int		i;

	if (!str)
		return (NULL);
	word_count = count_word(str, c);
	if (word_count == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (word_count + 1));
	if (!result_array)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result_array[i] = get_next_word(str, c);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

static int	count_word(char *str, char c)
{
	size_t	word;

	word = 0;
	while (*str)
	{
		while (*str == c)
			++str;
		if (*str != c && *str)
		{
			++word;
			while (*str != c && *str)
				++str;
		}
	}
	return (word);
}

static char	*get_next_word(char *str, char c)
{
	static int	index = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[index] == c)
		++index;
	while ((str[index + len] != c) && str[index + len])
		++len;
	//printf("len: %d\n", len);
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[index] != c) && str[index])
		next_word[i++] = str[index++];
	next_word[i] = '\0';
	return (next_word);
}

/*
int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (ac < 2)
        return (0);
    
    start_stack_a(&stack_a, av + 1);

    if (ft_is_sorted(stack_a))
        return (0);

    if (ft_size_list(stack_a) <= 3)
        ft_sort_three(&stack_a);
    else if (ft_size_list(stack_a) <= 5)
        ft_sort_five(&stack_a, &stack_b);
    else
        ft_sort_large(&stack_a, &stack_b);

    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    return (0);
}
*/