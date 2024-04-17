static void	new_stdin(t_shell *data, char *final_str, t_redir *red)
{
	int	fd;

	fd = open(HERE_DOC, O_WRONLY | O_TRUNC | O_CREAT, FILE_PERM);
	if (fd == -1)
	{
		red->success = 0;
		free(final_str);
		return (perror("open"));
	}
	ft_putstr_fd(final_str, fd);
	close(fd);
	free(final_str);
	fd = open(HERE_DOC, O_RDONLY, FILE_PERM);
	if (fd == -1)
	{
		red->success = 0;
		return (perror("open"));
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		red->success = 0;
		close(fd);
		// ft_exit_program(data, "dup2");
		return (perror("dup2"));
	}
	close(fd);
	if (unlink(HERE_DOC) == -1)
		perror("unlink");
}

static int	file_dup(t_redir *red, int fd)
{
	int	fileno;

	fileno = STDOUT_FILENO;
	if (red->type == 3)
		fileno = STDIN_FILENO;
	if (dup2(fd, fileno) == -1)
	{
		
		close(fd);
		// ft_exit_program(data, "dup2");
		perror("dup2");
		return (0);
	}
	close(fd);
	return (1);
}