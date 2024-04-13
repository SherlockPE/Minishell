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

# include "minishell.h"

void	ft_echo(t_shell *data);
void	ft_cd(t_shell *data);
void	ft_pwd(void);
void	ft_export(t_shell *data);
void	ft_unset(t_shell *data);
void	ft_env(t_shell *data);
void	ft_exit(t_shell *data);

#endif
