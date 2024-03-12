/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 15:50:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_fill_node(t_env *env, char *data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i] && data[i] != '=')
		i++;
	env->value = ft_strdup(data + i + 1);
	env->name = ft_calloc(i + 1, sizeof(char));
	if (!env->name || !env->value)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (j < i)
	{
		env->name[j] = data[j];
		j++;
	}
}

void	ft_minishell_init(t_shell *data, char **env)
{
	t_env	*new_env;
	t_list	*new_node;
	int		i;

	i = 0;
	while (env[i])
	{
		new_env = (t_env *)ft_calloc(1, sizeof(t_env));
		if (!new_env)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		ft_fill_node(new_env, env[i]);
		new_node = ft_lstnew(new_env);
		if (!new_node)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&data->env, new_node);
		i++;
	}
}
