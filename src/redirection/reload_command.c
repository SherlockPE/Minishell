/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:57:53 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 15:43:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*reload_last_command(const char *com)
{
	int		i;

	i = 0;
	while (com[i] && ft_strchr("<> ", com[i]))
		i++;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			break ;
		i++;
	}
	while (ft_strchr(NOT_VAL, com[i]))
		i++;
	return (ft_substr(com, i, ft_strlen(com)));
}

static char	*reload_front_command(const char *com, int pos)
{
	int		i;
	int		len;
	char	*rel_com;

	while (ft_strchr(NOT_VAL, com[pos - 1]))
		pos--;
	i = pos;
	while (com[i] && ft_strchr("<> ", com[i]))
		i++;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			break ;
		i++;
	}
	len = pos + ft_strlen(&com[i]);
	rel_com = ft_calloc(len + 1, sizeof(char));
	if (!rel_com)
		return (NULL);
	ft_strlcpy(rel_com, com, pos + 1);
	ft_strlcat(rel_com, &com[i], len + 1);
	return (rel_com);
}

int	reload_command(t_pipe *pipe)
{
	int		i;
	char	*temp;

	temp = pipe->com;
	i = 0;
	while (temp[i])
	{
		if (!quotes(temp[i]) && ft_strchr("<>", temp[i]))
		{
			if (i == 0)
				temp = reload_last_command(pipe->com);
			else
				temp = reload_front_command(pipe->com, i);
			if (!temp)
			{
				perror("malloc");
				return (EXIT_FAILURE);
			}
			free(pipe->com);
			pipe->com = temp;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
