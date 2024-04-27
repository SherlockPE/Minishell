/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:11:06 by albartol          #+#    #+#             */
/*   Updated: 2024/04/27 17:18:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

void	ft_parser(t_shell *data);
int		ft_validate_input(const char *input);
t_pipe	*ft_div_com(const char *input, int *com_len);
char	*ft_trim_input(const char *input);
char	**ft_split_quotes(const char *com, const char *set);
int		ft_expansor(t_shell *data);
char	*ft_expand_str(const char *str, t_shell *data);
int		ft_div_argv(t_shell *data);
char	**ft_rm_quotes(const char **argv);
char	*ft_trim_quotes(const char *str);
char	*trim_input(const char *input);
short	quotes(const char c);
short	simple_quotes(const char c);

#endif
