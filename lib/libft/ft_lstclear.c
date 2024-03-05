/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:07:40 by albartol          #+#    #+#             */
/*   Updated: 2023/10/04 13:23:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;
	t_list	*temp;

	clear = *lst;
	while (clear)
	{
		temp = clear;
		del(temp->content);
		clear = clear->next;
		free(temp);
	}
	*lst = 0;
}
