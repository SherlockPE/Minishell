/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:47:32 by albartol          #+#    #+#             */
/*   Updated: 2024/01/24 16:03:15 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quick_split(int *list, int start, int len)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = list[(start + len) / 2];
	i = start;
	j = len;
	while (1)
	{
		while (list[i] < pivot)
			i++;
		while (list[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}
}

void	ft_quick_sort(int *list, int start, int len)
{
	int	split;

	if (len - start <= 1)
		return ;
	split = ft_quick_split(list, start, len);
	ft_quick_sort(list, start, split);
	ft_quick_sort(list, split, len);
}

/* int main(void)
{
    int i[] = {1,5,8,2,0,7,9,3,4,6};
    int n = 0;

    ft_quick_sort(i, 0, 10 - 1);
    while (n < 10)
        ft_printf("%d", i[n++]);
    return (0);
} */