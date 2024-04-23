/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:13:55 by albartol          #+#    #+#             */
/*   Updated: 2024/04/23 14:44:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "struct.h"

int		ft_check_redirection(t_shell *data);
int		ft_create_archive(t_redir *red, const char *com, t_shell *data);
int		ft_here_doc(t_redir *red, const char *com, t_shell *data);
int	    create_tmp_file_name(t_redir *red);
char	*ft_get_archive_name(const char *com, t_shell *data);
int		reload_command(t_pipe *pipe);
void	ft_unlink_here_doc(t_shell *data);

#endif
