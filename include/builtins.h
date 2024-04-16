/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:02:42 by albartol          #+#    #+#             */
/*   Updated: 2024/04/13 18:08:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "struct.h"

void	ft_echo(char **argv);
void	ft_cd(char **argv, t_shell *data);
void	ft_pwd(void);
void	ft_export(char **argv, t_shell *data);
void	ft_unset(char **argv, t_shell *data);
void	ft_env(char **argv, t_shell *data);
void	ft_exit(char **argv, t_shell *data);

#endif
