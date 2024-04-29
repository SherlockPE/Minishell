/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:43:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/17 14:29:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_redir(int num, t_pipe *com)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(com->redir[i].file_name);
		i++;
	}
	free(com->redir);
}

void	free_input(t_shell *data)
{
	int	i;

	i = 0;
	free(data->input.input);
	free(data->input.value);
	while (i < data->com_len)
	{
		free(data->com[i].com.input);
		free(data->com[i].com.value);
		ft_free_array(data->com[i].argv);
		free_redir(data->com[i].redir_num, &data->com[i]);
		i++;
	}
	free(data->com);
	data->input.input = 0;
	data->input.value = 0;
	data->input.read_pos = 0;
	data->input.peek_pos = 0;
	data->com = 0;
	data->com_len = 0;
}
