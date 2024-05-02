/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/04/26 14:30:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_title(void)
{
	printf(WHITE"\n");
	printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗   ██╗ \n");
	printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║   ██║ \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║   ██║ \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║   ██║ \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗█████╗█████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚════╝╚════╝\n");
	printf("\nBy: "GREEN"albartol"RESET" && "GREEN"flopez-r\n"RESET);
}

static void	save_term_config(t_shell *data)
{
	if (isatty(STDIN))
		tcgetattr(STDIN, &data->conf);
}

void	ft_minishell_init(t_shell *data, char **env)
{
	data->env = 0;
	data->input.str = 0;
	data->input.value = 0;
	data->input.read_pos = 0;
	data->input.peek_pos = 0;
	data->com = 0;
	data->com_len = 0;
	data->child = 0;
	data->exit_code = 0;
	rl_catch_signals = 0;
	ft_init_env(data, env);
	save_term_config(data);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("signal");
	print_title();
}
