/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:13:55 by albartol          #+#    #+#             */
/*   Updated: 2024/04/17 16:58:35 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "struct.h"

int		ft_check_redirection(t_shell *data);
int	    ft_create_archive(t_redir *red, char  *com, t_shell *data);
int 	ft_get_limit(t_shell *data, t_redir *red);
char	*ft_get_archive_name(char *com, t_shell *data);
int	    reload_command(t_pipe *pipe);

#endif
