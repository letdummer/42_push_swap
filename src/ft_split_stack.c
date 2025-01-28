/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:44 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/28 16:34:37 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static char	*get_next_word(char *str, char c);
static int	count_word(char *str, char c);

static int	count_word(char *str, char c)
{
	int		word;
	bool	in_word;

	word = 0;
	while (*str)
	{
		in_word = false;
		while (*str == c)
			++str;
		while (*str != c && *str)
		{
			if (!in_word)
			{
				++word;
				in_word = true;
			}
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
	printf("len: %d\n", len);
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[index] != c) && str[index])
		next_word[i++] = str[index++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split_stack(char *str, char c)
{
	int		word_count;
	char	**result_array;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	word_count = count_word(str, c);
	if (word_count == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (word_count + 1));
	if (!result_array)
		return (NULL);
	while (word_count-- > 0)
	{
		result_array[i++] = get_next_word(str, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

/* int main(void)
{
	char	*str = "testing the function 123";
	char	delimiter = ' ';
	char	**result;
	int		i = 0;

	result = split_stack(str, delimiter);
	if (!result)
	{
		printf("Error\n");
		return(1);
	}
	printf("Result:\n");
	while(result[i])
	{
		printf("Palavra %d:	'%s'\n", i, result[i]);
		free(result[i]);
		i++;		
	}
	free(result);

	return(0);
} */