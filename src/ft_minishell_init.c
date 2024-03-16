/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/03/15 17:53:54 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_fill_node(t_env *env, char *data)
{
	int	i;

	i = 0;
	while (data[i] && data[i] != '=')
		i++;
	if (data[i] == '=')
		i++;
	env->name = ft_substr(data, 0, i);
	if (!ft_strncmp("SHLVL=", env->name, 6))
		env->value = ft_itoa(ft_atoi(data + i) + 1);
	else
		env->value = ft_strdup(data + i);
	if (!env->name || !env->value)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
}

void	ft_minishell_init(t_shell *data, char **env)
{
	t_env	*new_env;
	t_list	*new_node;
	int		i;

	i = 0;
	data->env = 0;
	data->exit_code = 0;
	data->command = 0;
	data->prompt = 0;
	while (env[i])
	{
		new_env = (t_env *)ft_calloc(1, sizeof(t_env));
		if (!new_env)
			ft_exit_program(data, "malloc");
		ft_fill_node(new_env, env[i]);
		new_node = ft_lstnew(new_env);
		if (!new_node)
			ft_exit_program(data, "malloc");
		ft_lstadd_back(&data->env, new_node);
		i++;
	}
}
