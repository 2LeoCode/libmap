/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:58:25 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 16:08:48 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_rm(t_list *member)
{
	member->prev->next = member->next;
	member->next->prev = member->prev;
	free(member->data);
	member->data = NULL;
	free(member);
	return (1);
}

int	lst_rm_if(t_list *sentinel, t_cmpf cmp_f, void *dataref)
{
	t_list	*lst;
	t_list	*tmp;
	int		rm_count;

	lst = sentinel->next;
	rm_count = 0;
	while (lst != sentinel)
	{
		if (!(*cmp_f)(lst->data, dataref))
		{
			tmp = lst->next;
			rm_count += lst_rm(lst);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (rm_count);
}
