/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:02:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/28 18:06:25 by flopez-r         ###   ########.fr       */
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

int	find_name_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\"' || str[i] == '\'' || str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	expand(t_shell *data, int i, int j)
{
	int		final_size;
	int		name_len;
	char	*new;
	char	*name;
	char	*expand;

	name_len = find_name_len(&data->pipes[i][j]);
	if (!name_len)
		return ;
	name = ft_substr(data->pipes[i], j + 1, name_len - 1);
	if (!name)
		ft_exit_program(data, "malloc");
	expand = ft_get_env_value(name, data->env);
	free(name);
	final_size = ft_strlen(data->pipes[i]) - name_len + ft_strlen(expand);
	new = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!new)
		ft_exit_program(data, "malloc");
	ft_strlcat(new, data->pipes[i], j + 1);
	ft_strlcat(new, expand, final_size + 1);
	ft_strlcat(new, data->pipes[i] + j + name_len, final_size + 1);
	free(data->pipes[i]);
	data->pipes[i] = new;
}

void	ft_expansor(t_shell *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->pipes[i])
	{
		j = 0;
		while (data->pipes[i][j])
		{
			if (!simple_quotes(data->pipes[i][j]) && data->pipes[i][j] == '$')
				expand(data, i, j);
			j++;
		}
		i++;
	}
}
