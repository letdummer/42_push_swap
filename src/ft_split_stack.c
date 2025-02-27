/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:44 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 18:39:37 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_word(char *str, char c);

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

int	count_word(char *str, char c)
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
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[index] != c) && str[index])
		next_word[i++] = str[index++];
	next_word[i] = '\0';
	return (next_word);
}
