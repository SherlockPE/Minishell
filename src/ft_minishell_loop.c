/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:09:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/12 17:33:18 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_signal(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line(rl_line_buffer, 0);
		rl_redisplay();
	}
}

void	ft_minishell_loop(t_shell *data)
{
	char	*input;

	if (signal(SIGINT, ft_signal) == SIG_ERR)
		perror(NULL);
	if (signal(SIGQUIT, ft_signal) == SIG_ERR)
		perror(NULL);
	while (1)
	{
		input = ft_get_input(data);
		if (!input)
			break ;
		if (*input)
			ft_parser(data, input);
		free(input);
	}
	rl_clear_history();
	printf("Exiting minishell\n");
}
