/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_file_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:50 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/23 13:29:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* void	replace_slash(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '/')
			buffer[i] = '_';
		i++;
	}
}

int	create_tmp_file_name(t_redir *red)
{
	char	buff[9];
	int		fd;
	int		i;

	buff[8] = 0;
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (ft_exit_funct("open", EXIT_FAILURE));
	i = read(fd, buff, 8);
	close(fd);
	if (i == -1)
		return (ft_exit_funct("read", EXIT_FAILURE));
	replace_slash(buff);
	red->file_name = ft_strjoin("/tmp/.", (const char *)buff);
	if (!red->file_name)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	return (EXIT_SUCCESS);
} */

int	create_tmp_file_name(t_redir *red)
{
	char		*buff;
	static int	i;

	buff = ft_itoa(i++);
	if (!buff)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	red->file_name = ft_strjoin(HERE_DOC_PATH, (const char *)buff);
	free(buff);
	if (!red->file_name)
		return (ft_exit_funct("malloc", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
