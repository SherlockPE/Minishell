/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:58:51 by albartol          #+#    #+#             */
/*   Updated: 2024/03/05 19:05:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// for printf
# include <stdio.h>
// for malloc, free & exit
# include <stdlib.h>
// for write
# include <unistd.h>
// for open, close & read
# include <fcntl.h>
// for signal, sigaction & kill
# include <signal.h>
// for fork & kill
# include <sys/types.h>
// for waitpid, wait, waitpid, wait3 & wait4
# include <sys/wait.h>

#endif