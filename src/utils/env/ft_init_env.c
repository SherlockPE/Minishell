/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:28:02 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/12 14:06:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_content(char *env)
{
	char	*new_env;
	char	*num;

	if (!ft_strncmp("SHLVL=", env, 6))
	{
		num = ft_itoa(ft_atoi(env + ft_strlenchr(env, '=')) + 1);
		if (!num)
			return (NULL);
		new_env = ft_strjoin("SHLVL=", num);
		free(num);
	}
	else
		new_env = ft_strdup(env);
	if (!new_env)
		return (NULL);
	return (new_env);
}

void	ft_init_env(t_shell *data, char **env)
{
	int		i;
	char	*new_env;
	t_list	*new_node;

	i = 0;
	while (env[i])
	{
		new_env = get_content(env[i]);
		if (!new_env)
			ft_exit_program(data, "malloc");
		new_node = ft_lstnew(new_env);
		if (!new_node)
		{
			free(new_env);
			ft_exit_program(data, "malloc");
		}
		ft_lstadd_back(&data->env, new_node);
		i++;
	}
}
