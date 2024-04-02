/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:02:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/02 15:07:13 by albartol         ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'' || str[i] == '$'
			 || ft_isnotprint(str[i]))
			return (i);
		i++;
	}
	return (i);
}

static void	expand_exit_code(t_shell *data, int i, int j)
{
	int		final_size;
	char	*temp;
	char	*expand;

	expand = ft_itoa(data->exit_code);
	if (!expand)
		ft_exit_program(data, "malloc");
	final_size = ft_strlen(data->pipes[i]) - 2 + ft_strlen(expand);
	temp = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!temp)
		ft_exit_program(data, "malloc");
	ft_strlcat(temp, data->pipes[i], j + 1);
	ft_strlcat(temp, expand, final_size + 1);
	free(expand);
	ft_strlcat(temp, data->pipes[i] + j + 2, final_size + 1);
	free(data->pipes[i]);
	data->pipes[i] = temp;
}

static void	expand(t_shell *data, int i, int j, int name_len)
{
	int		final_size;
	char	*temp;
	char	*expand;

	if (data->pipes[i][j + 1] == '?')
		expand_exit_code(data, i, j);
	else
	{
		temp = ft_substr(data->pipes[i], j + 1, name_len - 1);
		if (!temp)
			ft_exit_program(data, "malloc");
		expand = ft_get_env_value(temp, data->env);
		free(temp);
		final_size = ft_strlen(data->pipes[i]) - name_len + ft_strlen(expand);
		temp = (char *)ft_calloc(final_size + 1, sizeof(char));
		if (!temp)
			ft_exit_program(data, "malloc");
		ft_strlcat(temp, data->pipes[i], j + 1);
		ft_strlcat(temp, expand, final_size + 1);
		ft_strlcat(temp, data->pipes[i] + j + name_len, final_size + 1);
		free(data->pipes[i]);
		data->pipes[i] = temp;
	}
}

void	ft_expansor(t_shell *data)
{
	int	i;
	int	j;
	int	name_len;

	i = 0;
	while (data->pipes[i])
	{
		j = 0;
		while (data->pipes[i][j])
		{
			if (!simple_quotes(data->pipes[i][j]) && data->pipes[i][j] == '$')
			{
				name_len = find_name_len(&data->pipes[i][j]);
				if (name_len > 1)
					expand(data, i, j, name_len);
			}
			j++;
		}
		i++;
	}
}
