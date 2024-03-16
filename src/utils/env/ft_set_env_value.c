/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:18:51 by albartol          #+#    #+#             */
/*   Updated: 2024/03/15 18:35:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_new_node(t_shell *data, t_env *env, const char *name, const char *value)
{
	env->name = ft_strdup(name);
	env->value = ft_strdup(value);
	if (!env->name || !env->value)
		ft_exit_program(data, "malloc");
}

static void	ft_change_value(t_shell *data, t_list *env, const char *value)
{
	free(((t_env *)env->content)->value);
	((t_env *)env->content)->value = ft_strdup(value);
	if (!((t_env *)env->content)->value)
		ft_exit_program(data, "malloc");
}

void	ft_set_env_value(const char *name, const char *value, t_shell *data)
{
	size_t	len_name;
	size_t	len_env;
	char	*env_name;
	t_list	*temp_node;
	t_env	*new_env;

	len_name = ft_strlen(name);
	temp_node = data->env;
	while (temp_node)
	{
		env_name = ((t_env *)temp_node->content)->name;
		len_env = ft_strlen(env_name);
		if (len_name == len_env && !ft_strncmp(name, env_name, len_name))
			return (ft_change_value(data, temp_node, value));
		temp_node = temp_node->next;
	}
	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_env)
		ft_exit_program(data, "malloc");
	ft_new_node(data, new_env, name, value);
	temp_node = ft_lstnew(new_env);
	if (!temp_node)
		ft_exit_program(data, "malloc");
	ft_lstadd_back(&data->env, temp_node);
}
