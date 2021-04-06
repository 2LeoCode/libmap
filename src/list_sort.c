/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:13:24 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 16:27:20 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_sort(t_list *sentinel, t_cmpf cmp_f)
{
	t_list	*lst;
	t_list	*head;

	lst = sentinel->next;
	while (lst != sentinel)
	{
		head = lst->next;
		while (head != sentinel)
		{
			if (((*cmp_f)(lst->data, head->data) > 0)
				&& ft_swap(&lst->data, &head->data, POINTER))
				return ((int)lst_clear(sentinel) - 1);
			head = head->next;
		}
		lst = lst->next;
	}
	return (0);
}
