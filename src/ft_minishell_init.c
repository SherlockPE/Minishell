/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:25:49 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 14:47:47 by albartol         ###   ########.fr       */
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

static void	save_term_config(t_shell *data)
{
	if (tcgetattr(STDIN_FILENO, &data->conf) == -1)
		perror("tcgetattr");
}

void	ft_minishell_init(t_shell *data, char **env)
{
	data->env = 0;
	data->input = 0;
	data->com = 0;
	data->com_len = 0;
	data->exit_code = 0;
	ft_init_env(data, env);
	save_term_config(data);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("signal");
	print_title();
}
