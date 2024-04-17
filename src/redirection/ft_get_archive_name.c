/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_archive_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:05:36 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/04/17 16:42:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*trim_archive_name(char *com, int i, t_shell *data)
{
	char	*aux;
	char	*temp;
	char	*file_name;

	aux = ft_substr(com, 0, i);
	if (!aux)
		return (NULL);
	temp = ft_expand_str(aux, data);
	free(aux);
	if (!temp)
		return (NULL);
	file_name = ft_trim_quotes(temp);
	free(temp);
	if (!file_name)
		return (NULL);
}

char	*ft_get_archive_name(char *com, t_shell *data)
{
	int		i;

	i = 0;
	while (com[i])
	{
		if (!quotes(com[i]) && ft_strchr(" <>", com[i]))
			return (trim_archive_name(com, i, data));
		i++;
	}
	return (trim_archive_name(com, i, data));
}
