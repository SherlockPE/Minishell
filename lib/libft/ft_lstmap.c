/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:38:32 by albartol          #+#    #+#             */
/*   Updated: 2023/10/04 13:23:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp_list;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	list = 0;
	while (lst)
	{
		tmp = f(lst->content);
		tmp_list = ft_lstnew(tmp);
		if (!tmp_list)
		{
			free(tmp);
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, tmp_list);
		lst = lst->next;
	}
	return (list);
}

/* #include <stdio.h>

int	main(void)
{
  t_list *l1;
  t_list *l2;
  t_list *l3;

  l1 = malloc(sizeof(l1));
  l2 = malloc(sizeof(l2));
  l3 = malloc(sizeof(l3));

  l1->content = 1;
  l1->next = l2;

  l2->content = 2;
  l2->next = l3;

  l3->content = 3;
  l3->next = NULL;

  t_list *res = ft_lstmap(l1,f,del);

  return (0);
} */