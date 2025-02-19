/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:21:03 by lmaria            #+#    #+#             */
/*   Updated: 2025/01/03 13:54:26 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/* Free an array of strings */
static void	free_split(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

/* Count the number of words in the string */
static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

/* Copy a word to a new string */
static char	*copy_word(const char *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

/* Allocate and fill array of strings */
static int	fill_result(char **result, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = copy_word(s, c);
			if (!result[i])
			{
				free_split(result, i);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (1);
}

/* Main function */
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	words = count_words(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}
