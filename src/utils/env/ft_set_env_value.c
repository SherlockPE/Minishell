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

static void	ft_change_value(t_shell *data, t_list *env, const char *content)
{
	free(env->content);
	env->content = ft_strdup(content);
	if (!(char *)env->content)
		ft_exit_program(data, "malloc");
}

void	ft_set_env_value(const char *content, t_shell *data)
{
	size_t	len_name;
	size_t	len_env;
	char	*temp;
	t_list	*temp_node;

	len_name = ft_strlenchr(content, '=');
	temp_node = data->env;
	while (temp_node)
	{
		temp = (char *)temp_node->content;
		len_env = ft_strlenchr(temp, '=');
		if (len_name == len_env && !ft_strncmp(content, temp, len_name))
			return (ft_change_value(data, temp_node, content));
		temp_node = temp_node->next;
	}
	temp = ft_strdup(content);
	if (!temp)
		ft_exit_program(data, "malloc");
	temp_node = ft_lstnew(temp);
	if (!temp_node)
	{
		free(temp);
		ft_exit_program(data, "malloc");
	}
	ft_lstadd_back(&data->env, temp_node);
}
