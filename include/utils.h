/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:16:12 by albartol          #+#    #+#             */
/*   Updated: 2024/04/15 14:52:52 by albartol         ###   ########.fr       */
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

//array
int		array_len(const char **array);
size_t	array_char_len(const char **array);
char	*array_to_str(const char **array, const char spliter);
char	**array_dup(const char **array);

//free
void	free_input(t_shell *data);
void	free_program(t_shell *data);
void	ft_exit_program(t_shell *data, const char *message);
void	ft_free_array(char **array);

int		ft_exit_funct(char *message, int exit);
char	*ft_update_prompt(void);
int		ft_isnotprint(const char c);
size_t	ft_strlenchr(const char *str, const char c);
short	check_quotes(const char *input);

#endif
