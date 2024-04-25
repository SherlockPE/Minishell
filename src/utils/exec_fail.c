/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:30:42 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 12:33:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exec_fail(const char *path, const char *message, const int error_code)
{
	ft_putstr_fd(path, STDERR);
	ft_putstr_fd(message, STDERR);
	return (error_code);
}
