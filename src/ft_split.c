/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:32:44 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:53 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	*get_next_word(char *str, char c);
static int	count_word(char *str, char c);

static int	count_word(char *str, char c)
{
	int	word;

	word = 0;
	while(*str)
	{
		if(*str != c && *str)
			word++;
		++str;
	}
	return(word);
}

static char	*get_next_word(char *str, char c)
{
	static int	index;
	char		*next_word;
	int			len;
	int			i;

	index = 0;
	len = 0;
	i = 0;
	while(str[index] == c)
		++index;
	while((str[index + len] != c) && str[index + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if(!next_word)
		return(NULL);
	while((str[index] != c) && str[index])
		next_word[i++] = str[index++];
	next_word[i] = '\0';
	return(next_word);
}

char	**split(char *str, char c)
{
	int		word_count;
	char	**result_array;
	int		i;

	i = 0;
	word_count = count_word(str, c);
	if (!word_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (word_count + 1));
	if (!result_array)
		return(NULL);
	while(word_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array)
				return(NULL);
			result_array[i++][0] = '\0';
			continue;
		}
		result_array[i++] = get_next_word(str, c);
	}
	result_array[i] = NULL;
	return(result_array);
}


int main(void)
{
	char *str = "testing the function";
	char	delimiter = ' ';
	char	**result;
	int i = 0;

	result = split(str, delimiter);
	if (!result)
	{
		write(1, "error\n", 6);
		return(1);
	}
	write(1, "Result:\n", 8);
	while(result[i])
	{
		ft_printf("Palavra %d:	'%s'\n", i, result[i]);
		free(result[i]);
		i++;		
	}
	free(result);

	return(0);
}