/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:27:40 by akolupae          #+#    #+#             */
/*   Updated: 2025/04/30 12:35:30 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*split_word(size_t *src_i, const char *src, char c);
static void		free_arr(char **arr);
static void		split_str(char **arr, size_t words, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	words = count_words(s, c);
	arr = (char **) malloc ((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	split_str(arr, words, s, c);
	return (arr);
}

static void	split_str(char **arr, size_t words, char const *s, char c)
{	
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		if (s[j] != c)
		{
			arr[i] = split_word(&j, &s[j], c);
			if (arr[i] == NULL)
			{
				free_arr(arr);
				free(arr);
				return ;
			}
			i++;
		}
		j++;
	}
	arr[words] = NULL;
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	bool	new_wrd;
	size_t	words;

	i = 0;
	new_wrd = true;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && new_wrd == true)
		{
			words++;
			new_wrd = false;
		}
		else if (s[i] == c)
			new_wrd = true;
		i++;
	}
	return (words);
}

static char	*split_word(size_t *src_i, const char *src, char c)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = 0;
	while (src[len] != c && src[len] != '\0')
		len++;
	*src_i += len;
	dest = ft_calloc (len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
}
