/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:11:06 by albartol          #+#    #+#             */
/*   Updated: 2024/04/13 18:14:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int		ft_parser(t_shell *data);
int		ft_trim_input(t_shell *data);
int		ft_val_input(const char *com, const char c, const char b);
char	**ft_split_pipes(const char *com);
char	**ft_split_quotes(const char *com, const char c);
int		ft_expansor(t_shell *data);
char	*ft_trim_quotes(const char *str);
int 	quotes(const char c);

#endif
