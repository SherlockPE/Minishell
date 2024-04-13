/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:13:55 by albartol          #+#    #+#             */
/*   Updated: 2024/04/13 18:15:28 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "minishell.h"

int		ft_check_redirection(t_shell *data, t_redir *red);
void	ft_create_archive(t_shell *data, t_redir *red);
void	ft_get_limit(t_shell *data, t_redir *red);
void	ft_get_archive_name(t_shell *data, t_redir *red);

#endif
