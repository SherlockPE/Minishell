/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:48:24 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/22 14:03:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_signal_name(int exit_code)
{
	if (exit_code == 11)
		printf("Segmentation fault :");
	else if (exit_code == 15)
		printf("Terminated :");
	printf("%d\n", exit_code);
}

void	ft_handle_exit(t_shell *data, int wstatus)
{
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
	if (WIFSIGNALED(wstatus))
	{
		print_signal_name(WTERMSIG(wstatus));
		data->exit_code = WTERMSIG(wstatus) + 128;
	}
}
