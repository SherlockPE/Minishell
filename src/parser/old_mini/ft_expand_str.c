/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:02:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/27 18:25:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

static char *expand_fail(char *message)
{
	perror(message);
	return (NULL);
}

static char	*expand_exit_code(const char *str, int *i, t_shell *data)
{
	int		final_size;
	char	*new_str;
	char	*expand;
	int		new_pos;

	expand = ft_itoa(data->exit_code);
	if (!expand)
		return (expand_fail("malloc"));
	final_size = ft_strlen(str) - 2 + ft_strlen(expand);
	new_str = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!new_str)
	{
		free(expand);
		return (expand_fail("malloc"));
	}
	ft_strlcat(new_str, str, *i + 1);
	ft_strlcat(new_str, expand, final_size + 1);
	new_pos = ft_strlen(new_str) - 1;
	free(expand);
	ft_strlcat(new_str, str + *i + 2, final_size + 1);
	*i = new_pos;
	return (new_str);
}

static char	*expand(const char *str, int *i, int name_len, t_shell *data)
{
	int		final_size;
	char	*new_str;
	char	*expand;
	int		new_pos;

	if (str[*i + 1] == '?')
		return (expand_exit_code(str, i, data));
	new_str = ft_substr(str, *i + 1, name_len - 1);
	if (!new_str)
		return (expand_fail("malloc"));
	expand = ft_get_env_value(new_str, data->env);
	free(new_str);
	final_size = ft_strlen(str) - name_len + ft_strlen(expand);
	new_str = (char *)ft_calloc(final_size + 1, sizeof(char));
	if (!new_str)
		return (expand_fail("malloc"));
	ft_strlcat(new_str, str, *i + 1);
	ft_strlcat(new_str, expand, final_size + 1);
	new_pos = ft_strlen(new_str) - 1;
	ft_strlcat(new_str, str + *i + name_len, final_size + 1);
	*i = new_pos;
	return (new_str);
}

// static char	*return_str(const char *str, char *new_str)
// {
// 	char	*temp;

// 	if (new_str != str)
// 	{
// 		temp = ft_trim_input(new_str);
// 		free(new_str);
// 		if (!temp)
// 			return (NULL);
// 		new_str = temp;
// 	}
// 	return (new_str);
// }

static char	*return_str(const char *str, char *new_str)
{
	if (new_str != str)
	{
		if (ft_validate_input(new_str))
		{
			ft_putstr_fd(new_str, STDERR);
			ft_putstr_fd("\n", STDERR);
			free(new_str);
			return (NULL);
		}
	}
	return (new_str);
}

char	*ft_expand_str(const char *str, t_shell *data)
{
	int		i;
	int		name_len;
	char	*new_str;
	char	*temp;

	i = 0;
	new_str = (char *)str;
	while (new_str[i])
	{
		if (!simple_quotes(new_str[i]) && new_str[i] == '$')
		{
			name_len = find_name_len(&new_str[i]);
			if (name_len > 1)
			{
				temp = expand(new_str, &i, name_len, data);
				if (new_str != str)
					free(new_str);
				if (!temp)
					return (NULL);
				new_str = temp;
			}
		}
		i++;
	}
	// return (new_str);
	return (return_str(str, new_str));
}
