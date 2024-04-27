/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:19:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 15:49:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_splits(const char *str, const char *set)
{
	int		i;
	int		splits;

	i = 0;
	splits = 1;
	while (str[i])
	{
		if (!quotes(str[i]) && ft_strchr(set, str[i]))
			splits++;
		i++;
	}
	return (splits);
}

static int	ft_split_len(const char *str, const char *set)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!quotes(str[i]) && ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_quotes(const char *str, const char *set)
{
	char	**array;
	int		i;
	int		len;
	int		splits;

	i = 0;
	splits = ft_splits(str, set);
	array = (char **)ft_calloc(splits + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < splits)
	{
		len = ft_split_len(str, set);
		array[i] = ft_substr(str, 0, len);
		if (!array[i])
		{
			ft_free_array(array);
			return (NULL);
		}
		str += len + 1;
		i++;
	}
	array[i] = 0;
	return (array);
}
