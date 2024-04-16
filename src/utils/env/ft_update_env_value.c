/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:10:01 by albartol          #+#    #+#             */
/*   Updated: 2024/03/16 18:20:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_update_env_value(const char *name, const char *value, t_shell *data)
{
	char	*content;

	content = ft_strjoin(name, value);
	if (!content)
	{
		perror("couldn't update the env: malloc");
		return (1);
	}
	ft_set_env_value(content, data);
	free(content);
	return (0);
}
