/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:02:42 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 15:49:21 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "struct.h"

# define EXIT_NUM 2

void	ft_echo(char **argv, t_shell *data);
void	ft_cd(char **argv, t_shell *data);
void	ft_pwd(t_shell *data);
void	ft_export(char **argv, t_shell *data);
void	ft_unset(char **argv, t_shell *data);
void	ft_env(char **argv, t_shell *data);
void	ft_exit(char **argv, t_shell *data);

#endif
