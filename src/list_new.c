/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:25:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 13:52:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_new_sentinel(void)
{
	t_list	*sentinel;

	sentinel = malloc(sizeof(t_list));
	if (!sentinel)
		return (NULL);
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	sentinel->data = NULL;
	return (sentinel);
}

t_list	*lst_new(t_type type, void *data, t_size size)
{
	t_list	*sentinel;
	void	*tmp;
	t_size	array_size;

	sentinel = malloc(sizeof(t_list));
	if (!sentinel)
		return (NULL);
	sentinel->next = malloc(sizeof(t_list));
	if (!sentinel->next)
		return (destroy(sentinel));
	sentinel->data = NULL;
	sentinel->prev = sentinel->next;
	sentinel->next->data = alloc_type(type, size + 1);
	if (!sentinel->next->data)
		return (destroy(sentinel->next) + (int)destroy(sentinel));
	tmp = sentinel->next->data;
	array_size = size * type;
	while (array_size--)
		*((char *)tmp++) = *((char *)data++);
	array_size = type;
	while (array_size--)
		*((char *)tmp++) = 0;
	sentinel->next->next = sentinel;
	sentinel->next->prev = sentinel;
	return (sentinel);
}
