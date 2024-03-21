/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:48:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/21 16:33:11 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* static short	parse_eof(char *eof)
{
	size_t			i;

	i = ft_strlenchr(eof, ' ');
	while (eof[i] && eof[i] != '\n')
		i++;
	if (!eof[i])
		return (1);
	i++;
	while (eof[i])
	{
		if (!ft_strncmp(eof, &eof[i], ft_strlenchr(eof, ' ')))
			return (1);
		i++;
	}
	return (0);
}

static short	check_eof(char *input)
{
	int		i;
	short	eof;

	i = 0;
	eof = 0;
	while (input[i])
	{
		if (!quotes(input[i]) && input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			while (input[i] && input[i] == ' ')
				i++;
			eof ^= parse_eof(&input[i]);
			break ;
			i += ft_strlenchr(&input[i], ' ');
		}
		if (input[i])
			i++;
	}
	return (eof);
} */

/* static void	get_command(t_shell *data)
{
	char	*aux;
	char	*new_input;

	data->command = readline(data->prompt);
	free(data->prompt);
	if (!data->command)
		return ;
	while (check_quotes(data->command) || check_eof(data->command))
	{
		(void)write(0, ">", 1);
		new_input = get_next_line(0);
		if (!new_input)
			return ;
		aux = data->command;
		data->command = ft_strjoin(data->command, new_input);
		free(new_input);
		free(aux);
		if (!data->command)
			ft_exit_program(data, "malloc");
	}
} */

static void	get_command(t_shell *data)
{
	char	*aux;
	char	*new_input;

	data->command = readline(data->prompt);
	free(data->prompt);
	if (!data->command)
		return ;
	while (check_quotes(data->command))
	{
		aux = data->command;
		data->command = ft_charjoin(data->command, '\n');
		free(aux);
		if (!data->command)
			ft_exit_program(data, "malloc");
		new_input = readline("> ");
		// (void)write(0, "> ", 2);
		// new_input = get_next_line(0);
		if (!new_input)
			return ((void)printf("unexpected EOF while looking for \"\'\n"));
		// printf("unexpected EOF while looking for matching `\"\'\n");
		aux = data->command;
		data->command = ft_strjoin(data->command, new_input);
		free(aux);
		if (!data->command)
			ft_exit_program(data, "malloc");
	}
}

void	ft_get_input(t_shell *data)
{
	ft_update_prompt(data);
	get_command(data);
}
