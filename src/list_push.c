/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:35:59 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 13:52:16 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_push_front(t_list *sentinel, t_type type, void *data, t_size size)
{
	t_list	*new_member;
	void	*tmp;
	t_size	array_size;

	new_member = malloc(sizeof(t_list));
	if (!new_member)
		return (-1);
	new_member->data = alloc_type(type, size + type);
	if (!new_member->data)
		return ((int)destroy(new_member) - 1);
	tmp = new_member->data;
	array_size = type * size;
	while (array_size--)
		*((char *)tmp++) = *((char *)data++);
	array_size = type;
	while (array_size--)
		*((char *)tmp++) = 0;
	new_member->next = sentinel->next;
	new_member->prev = sentinel;
	sentinel->next = new_member;
	new_member->next->prev = new_member;
	return (0);
}

int	lst_push_back(t_list *sentinel, t_type type, void *data, t_size size)
{
	t_list	*new_member;
	void	*tmp;
	t_size	array_size;

	new_member = malloc(sizeof(t_list));
	if (!new_member)
		return (-1);
	new_member->data = alloc_type(type, size + type);
	if (!new_member->data)
		return ((int)destroy(new_member) - 1);
	tmp = new_member->data;
	array_size = type * size;
	while (array_size--)
		*((char *)tmp++) = *((char *)data++);
	array_size = type;
	while (array_size--)
		*((char *)tmp++) = 0;
	new_member->next = sentinel;
	new_member->prev = sentinel->prev;
	sentinel->prev = new_member;
	new_member->prev->next = new_member;
	return (0);
}
