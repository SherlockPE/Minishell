/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:18:14 by albartol          #+#    #+#             */
/*   Updated: 2024/03/18 17:01:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_splits(char *str)
{
	int		i;
	int		splits;

	i = 0;
	splits = 1;
	while (str[i])
	{
		if (!quotes(str[i]) && str[i] == '|' && str[i + 1] != '|' && 
			(i > 0 && str[i - 1] != '|'))
			splits++;
		i++;
	}
	return (splits);
}

static int	ft_split_len(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!quotes(str[i]) && str[i] == '|' && str[i + 1] != '|' && 
			(i > 0 && str[i - 1] != '|'))
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_pipes(char *com)
{
	char	**array;
	int		i;
	int		len;
	int		splits;

	i = 0;
	splits = ft_splits(com);
	array = (char **)ft_calloc(splits + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < splits)
	{
		len = ft_split_len(com);
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
