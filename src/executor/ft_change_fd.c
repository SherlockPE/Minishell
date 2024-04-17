/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:34:52 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 16:34:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_change_fd(t_pipe *com, t_shell *data)
{
	int		fd;
	int		i;

	if (com->input.file_name)
	{
		fd = open(com->input.file_name, O_RDONLY);
		if (fd == -1)
			ft_exit_program(data, "open");
		i = dup2(fd, STDIN_FILENO);
		close(fd);
		if (i == -1)
			ft_exit_program(data, "input: dup2");
	}
	if (com->output.file_name)
	{
		if (com->output.type == TRUNC)
			fd = open(com->output.file_name, O_WRONLY | O_TRUNC);
		else if (com->output.type == APPEND)
			fd = open(com->output.file_name, O_WRONLY | O_APPEND);
		if (fd == -1)
			ft_exit_program(data, "open");
		i = dup2(fd, STDOUT_FILENO);
		close(fd);
		if (i == -1)
			ft_exit_program(data, "output: dup2");
	}
}
