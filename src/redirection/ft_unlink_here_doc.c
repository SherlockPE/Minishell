/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:17:04 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 19:27:12 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unlink_here_doc(t_shell *data)
{
	int	i;

	i = 0;
	while (i < data->com_len)
	{
		if (data->com[i].input.type == HERE_DOC)
			unlink(data->com[i].input.file_name);
		i++;
	}
}
