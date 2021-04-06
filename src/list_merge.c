/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:37:35 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 14:02:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_merge(t_list *sentinel_a, t_list *sentinel_b)
{
	t_list	*tmp;

	tmp = sentinel_a->prev;
	if (sentinel_b->prev != sentinel_b)
		sentinel_a->prev = sentinel_b->prev;
	if (sentinel_b->next != sentinel_b)
		tmp->next = sentinel_b->next;
	tmp->next->prev = tmp;
	sentinel_b->prev->next = sentinel_a;
	free(sentinel_b);
	return (sentinel_a);
}
