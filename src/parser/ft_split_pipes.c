/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:18:14 by albartol          #+#    #+#             */
/*   Updated: 2024/03/21 18:00:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_splits(const char *str)
{
	int		i;
	int		splits;

	i = 0;
	splits = 1;
	while (str[i])
	{
		if (!quotes(str[i]) && str[i] == '|' && str[i + 1] != '|'
			&& (i > 0 && str[i - 1] != '|'))
			splits++;
		i++;
	}
	return (splits);
}

static int	ft_split_len(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!quotes(str[i]) && str[i] == '|' && str[i + 1] != '|'
			&& (i > 0 && str[i - 1] != '|'))
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_pipes(const char *str)
{
	char	**array;
	int		i;
	int		len;
	int		splits;

	i = 0;
	splits = ft_splits(str);
	array = (char **)ft_calloc(splits + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < splits)
	{
		len = ft_split_len(str);
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
