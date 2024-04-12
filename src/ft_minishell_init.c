/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/04/12 14:17:20 by flopez-r         ###   ########.fr       */
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
	printf(RESET"\n");
}

static void    save_term_config(t_shell *data)
{
	if (tcgetattr(STDIN_FILENO, &data->init_conf) == -1)
		ft_exit_program(data, "tcgetattr");
}

void	ft_minishell_init(t_shell *data, char **env)
{
	data->env = 0;
	data->com = 0;
	data->input = 0;
	data->pipes = 0;
	data->prompt = 0;
	data->exit_code = 0;
	ft_init_env(data, env);
	save_term_config(data);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		ft_exit_program(data, "signal");
	print_title();
}
