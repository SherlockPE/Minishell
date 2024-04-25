/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:22 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 12:47:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "struct.h"

# define IS_DIR 126
# define PERM_DENIED 126
# define NOT_COMMAND 127
# define NOT_FILE 127

void	ft_pipex(t_shell *data);
void	ft_exec_one(t_shell *data);
int		child_process_pipe(t_shell *data, t_pipe *com);
int		child_process(t_shell *data, t_pipe *com);
void	ft_change_fd(t_pipe *com, t_shell *data);
void	ft_send_com(char **argv, t_shell *data);
void	ft_exec_command(char **argv, t_shell *data);
void	ft_exec_bin(char **argv, t_shell *data);
void	ft_handle_exit(t_shell *data, int wstatus);
char	*ft_check_bin(char *bin, char *path);

#endif
