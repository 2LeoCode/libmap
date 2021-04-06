/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:14:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 17:06:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>
#include <stdio.h>

int	map_insert(t_map *map, t_pair data, t_pair size)
{
	t_size	key_size;
	t_size	value_size;

	key_size = (t_size)size.first;
	value_size = (t_size)size.second;
	map_erase(map, data.first);
	if (lst_push_front(map->data.first, (t_type)map->type.first,
			data.first, key_size)
		|| lst_push_front(map->data.second, (t_type)map->type.second,
			data.second, value_size))
		return ((int)map_clear(map) - 1);
	map->size++;
	map->empty = false;
	map->begin = ((t_list *)map->data.second)->next;
	map->rbegin = ((t_list *)map->data.second)->prev;
	return (0);
}
