/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:48:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/01 15:19:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_count_words(char *string, char *set)
{
	int	i;
	int	cant_words;

	i = 0;
	cant_words = 0;
	while (string[i])
	{
		while (string[i] && strchr(set, string[i]))
			i++;
		while (string[i] && !strchr(set, string[i]))
		{
			i++;
			if (strchr(set, string[i]) || string[i] == 0)
				cant_words++;
		}
	}
	return (cant_words);
}

char	**ft_fill_box(char *string, char *set, char **result)
{
	int	i;
	int	pos;
	int	start;

	i = 0;
	pos = 0;
	start = 0;
	while (string[i])
	{
		while (string[i] && strchr(set, string[i]))
			i++;
		start = i;
		while (string[i] && !strchr(set, string[i]))
		{
			i++;
			if (strchr(set, string[i]) || string[i] == 0)
			{
				result[pos] = ft_substr(string, start, i - start);
				if (!result[pos])
				{
					ft_free_array(result);
					return (NULL);
				}
				pos++;
			}
		}
	}
	return (result);
}

char	**ft_split_all(char *string, char *set)
{
	char **result;
	int c_words;

	c_words = ft_count_words(string, set);
	result = (char **)ft_calloc(c_words, sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_fill_box(string, set, result);
	if (!result)
		return (NULL);
	return (result);
}