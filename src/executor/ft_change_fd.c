/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:34:52 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 14:36:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_output_fd(t_pipe *com, t_shell *data)
{
	int		fd;
	int		i;

	fd = 0;
	if (com->output.file_name)
	{
		if (com->output.type == TRUNC)
			fd = open(com->output.file_name, O_WRONLY | O_TRUNC);
		else if (com->output.type == APPEND)
			fd = open(com->output.file_name, O_WRONLY | O_APPEND);
		if (fd == 0)
			return ;
		if (fd == -1)
			ft_exit_program(data, "open");
		i = dup2(fd, STDOUT_FILENO);
		close(fd);
		if (i == -1)
			ft_exit_program(data, "output: dup2");
	}
}

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
	ft_output_fd(com, data);
}
