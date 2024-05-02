/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:19:15 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 15:49:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_splits(const char *str, int value)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] && str[i] == value)
		i++;
	if (str[i])
		n++;
	while (str[i])
	{
		if (str[i] == value && str[i + 1] != value && str[i + 1] != 0)
			n++;
		i++;
	}
	return (n);
}

static int	ft_split_len(const char *str, int value)
{
	int	i;

	i = 0;
	while (str[i] != value && str[i])
		i++;
	return (i);
}

static void	fill_array(char **array, t_input *input, int value, int splits)
{
	int		i;
	int		n;
	char	*str;
	char	*key;

	i = 0;
	n = 0;
	str = input->str;
	key = input->value;
	while (i < splits)
	{
		while (key[n] == value && key[n])
			n++;
		array[i] = ft_substr(str, n, ft_split_len(key + n, value));
		if (!array[i])
		{
			ft_free_array(array);
			array = NULL;
			return ;
		}
		while (key[n] != value && key[n])
			n++;
		i++;
	}
}

char	**ft_split_value(t_input *input, int value)
{
	char	**array;
	int		splits;

	splits = ft_splits(input->value, value);
	array = (char **)ft_calloc(splits + 1, sizeof(char *));
	if (!array)
		return (NULL);
	fill_array(array, input, value, splits);
	return (array);
}
