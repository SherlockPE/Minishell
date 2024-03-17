/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:19:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/17 20:47:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_splits(char *input, char c)
{
	int		i;
	int		splits;

	i = 0;
	splits = 1;
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == c)
			splits++;
		i++;
	}
	return (splits);
}

static int	ft_split_len(char const *input, char c)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_quotes(char *com, char c)
{
	char	**array;
	int		i;
	int		len;
	int		splits;

	i = 0;
	splits = ft_splits(com, c);
	array = (char **)ft_calloc(splits + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < splits)
	{
		len = ft_split_len(com, c);
		array[i] = ft_substr(com, 0, len);
		if (!array[i])
		{
			ft_free_array(array);
			return (NULL);
		}
		com += len + 1;
		i++;
	}
	array[i] = 0;
	return (array);
}
