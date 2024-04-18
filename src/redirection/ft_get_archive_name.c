/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_archive_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:05:36 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/04/18 16:55:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*trim_archive_name(const char *com, int i, t_shell *data)
{
	char	*aux;
	char	*temp;
	char	*file_name;

	aux = ft_substr(com, 0, i);
	if (!aux)
		return (NULL);
	temp = ft_expand_str(aux, data);
	if (temp != aux)
	{
		free(aux);
		if (!temp)
			return (NULL);
	}
	file_name = ft_trim_quotes(temp);
	free(temp);
	if (!file_name)
		return (NULL);
	return (file_name);
}

char	*ft_get_archive_name(const char *com, t_shell *data)
{
	int		i;

	i = 0;
	if (com[i] == ' ')
		com++;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			return (trim_archive_name(com, i, data));
		i++;
	}
	return (trim_archive_name(com, i, data));
}
