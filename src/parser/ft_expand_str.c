/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:02:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/17 18:29:12 by flopez-r         ###   ########.fr       */
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

static char	*expand_exit_code(const char *str, int i, t_shell *data)
{
	int		final_size;
	char	*new_str;
	char	*expand;

	expand = ft_itoa(data->exit_code);
	if (!expand)
	{
		perror("malloc");
		return (NULL);
	}
	final_size = ft_strlen(str) - 2 + ft_strlen(expand);
	new_str = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!new_str)
	{
		free(expand);
		perror("malloc");
		return (NULL);
	}
	ft_strlcat(new_str, str, i + 1);
	ft_strlcat(new_str, expand, final_size + 1);
	free(expand);
	ft_strlcat(new_str, str + i + 2, final_size + 1);
	return (new_str);
}

static char	*expand(const char *str, int i, int name_len, t_shell *data)
{
	int		final_size;
	char	*new_str;
	char	*expand;

	if (str[i + 1] == '?')
		return (expand_exit_code(str, i, data));
	new_str = ft_substr(str, i + 1, name_len - 1);
	if (!new_str)
	{
		perror("malloc");
		return (NULL);
	}
	expand = ft_get_env_value(new_str, data->env);
	free(new_str);
	final_size = ft_strlen(str) - name_len + ft_strlen(expand);
	new_str = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!new_str)
	{
		perror("malloc");
		return (NULL);
	}
	ft_strlcat(new_str, str, i + 1);
	ft_strlcat(new_str, expand, final_size + 1);
	ft_strlcat(new_str, str + i + name_len, final_size + 1);
	return (new_str);
}

char	*ft_expand_str(const char *str, t_shell *data)
{
	int	i;
	int	name_len;

	i = 0;
	while (str[i])
	{
		if (!simple_quotes(str[i]) && str[i] == '$')
		{
			name_len = find_name_len(&str[i]);
			if (name_len > 1)
			{
				return (expand(str, i, name_len, data));
				i = -1;
			}
		}
		i++;
	}
	return ((char *)str);
}
