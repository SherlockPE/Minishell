/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:48:24 by flopez-r          #+#    #+#             */
/*   Updated: 2024/04/23 15:06:49 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_sig_message(char *message, int exit_code)
{
	ft_putstr_fd(message, STDERR);
	ft_putnbr_fd(exit_code, STDERR);
	ft_putchar_fd('\n', STDERR);
}

static void	print_signal_name(int exit_code)
{
	if (exit_code == SIGSEGV)
		print_sig_message("Segmentation fault :", exit_code);
	else if (exit_code == SIGTERM)
		print_sig_message("Terminated :", exit_code);
	else if (exit_code == SIGQUIT)
		print_sig_message("Quit :", exit_code);
	else if (exit_code == SIGKILL)
		print_sig_message("Killed :", exit_code);
	else if (exit_code == SIGSTOP)
		print_sig_message("Stoped :", exit_code);
}

void	ft_handle_exit(t_shell *data, int wstatus)
{
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		print_signal_name(WTERMSIG(wstatus));
		data->exit_code = WTERMSIG(wstatus) + 128;
	}
}
