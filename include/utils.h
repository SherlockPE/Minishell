/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:16:12 by albartol          #+#    #+#             */
/*   Updated: 2024/04/25 13:25:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/libft/libft.h"
# include "struct.h"

//env
char	*ft_get_env_value(const char *name, t_list *env);
int		ft_set_env_value(const char *content, t_shell *data);
int		ft_update_env_value(const char *name, const char *value, t_shell *data);
void	ft_init_env(t_shell *data, char **env);
char	**get_env(t_shell *data);

//array
int		array_len(const char **array);

//free
void	free_input(t_shell *data);
void	free_program(t_shell *data);
void	ft_exit_program(t_shell *data, const char *message);
void	ft_free_array(char **array);

int		ft_exit_funct(char *message, int exit);
char	*ft_update_prompt(void);
size_t	ft_strlenchr(const char *str, const char c);
short	check_quotes(const char *input);
void	ft_handle_signals(void);
int 	exec_fail(const char *path, const char *message, const int error_code);

#endif
