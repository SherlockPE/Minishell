/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:02:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/16 16:00:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static short	simple_quotes(const char c)
{
	static short	simple_q;

	if (c == '\'')
		simple_q ^= 1;
	return (simple_q);
}

static int	find_name_len(const char *str)
{
	int	i;

	i = 1;
	if (str[i] == '?')
		return (2);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (i);
		i++;
	}
	return (i);
}

static int	expand_exit_code(t_shell *data, int i, int j)
{
	int		final_size;
	char	*temp;
	char	*expand;

	expand = ft_itoa(data->exit_code);
	if (!expand)
		ft_exit_funct("malloc", EXIT_FAILURE);
	final_size = ft_strlen(data->com[i].com) - 2 + ft_strlen(expand);
	temp = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!temp)
		ft_exit_funct("malloc", EXIT_FAILURE);
	ft_strlcat(temp, data->com[i].com, j + 1);
	ft_strlcat(temp, expand, final_size + 1);
	free(expand);
	ft_strlcat(temp, data->com[i].com + j + 2, final_size + 1);
	free(data->com[i].com);
	data->com[i].com = temp;
	return (EXIT_SUCCESS);
}

static int	expand(t_shell *data, int i, int j, int name_len)
{
	int		final_size;
	char	*temp;
	char	*expand;

	if (data->com[i].com[j + 1] == '?')
		return (expand_exit_code(data, i, j));
	else
	{
		temp = ft_substr(data->com[i].com, j + 1, name_len - 1);
		if (!temp)
			return (ft_exit_funct("malloc", EXIT_FAILURE));
		expand = ft_get_env_value(temp, data->env);
		free(temp);
		final_size = ft_strlen(data->com[i].com) - name_len + ft_strlen(expand);
		temp = (char *)ft_calloc(final_size + 1, sizeof(char));
		if (!temp)
			return (ft_exit_funct("malloc", EXIT_FAILURE));
		ft_strlcat(temp, data->com[i].com, j + 1);
		ft_strlcat(temp, expand, final_size + 1);
		ft_strlcat(temp, data->com[i].com + j + name_len, final_size + 1);
		free(data->com[i].com);
		data->com[i].com = temp;
	}
	return (EXIT_SUCCESS);
}

int	ft_expansor(t_shell *data)
{
	int	i;
	int	j;
	int	name_len;

	i = 0;
	while (i < data->com_len)
	{
		j = 0;
		while (data->com[i].com[j])
		{
			if (!simple_quotes(data->com[i].com[j]) && data->com[i].com[j] == '$')
			{
				name_len = find_name_len(&data->com[i].com[j]);
				if (name_len > 1)
				{
					if (expand(data, i, j, name_len))
						return (EXIT_FAILURE);
					j = -1;
				}
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
