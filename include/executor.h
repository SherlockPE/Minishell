/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:22 by albartol          #+#    #+#             */
/*   Updated: 2024/04/13 18:08:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int		ft_pipex(t_shell *data);
void	ft_exec_one(t_shell *data);
int		child_process_pipe(t_shell *data, char *com);
int		child_process(t_shell *data, char *com);
void	ft_send_com(t_shell *data, char *com, t_com *com_struct);
void	ft_exec_command(t_shell *data);
void	ft_exec_bin(t_shell *data);
char	*ft_check_bin(t_shell *data);

#endif
