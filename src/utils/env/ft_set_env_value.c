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

static int	change_env_value(t_shell *data, t_list *env, const char *content)
{
	char	*temp;

	temp = ft_strdup(content);
	if (!temp)
	{
		perror("couldn't change the env: malloc");
		return (2);
	}	
	free(env->content);
	env->content = temp;
	return (1);
}

static int	check_env_value(t_shell *data, const char *content)
{
	size_t	len_name;
	size_t	len_env;
	t_list	*temp_node;
	char	*temp;

	len_name = ft_strlenchr(content, '=');
	temp_node = data->env;
	while (temp_node)
	{
		temp = (char *)temp_node->content;
		len_env = ft_strlenchr(temp, '=');
		if (len_name == len_env && !ft_strncmp(content, temp, len_name))
			return (change_env_value(data, temp_node, content));
		temp_node = temp_node->next;
	}
	return (0);
}

int	ft_set_env_value(const char *content, t_shell *data)
{
	char	*temp;
	t_list	*temp_node;
	int		result;

	result = check_env_value(data, content);
	if (result <= 1)
		return (0);
	else if (result == 2)
		return (1);
	temp = ft_strdup(content);
	if (!temp)
	{
		perror("couldn't set the env: malloc");
		return (1);
	}	
	temp_node = ft_lstnew(temp);
	if (!temp_node)
	{
		free(temp);
		perror("couldn't set the env: malloc");
		return (1);
	}
	ft_lstadd_back(&data->env, temp_node);
	return (0);
}
