/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:50:46 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:14:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

t_bool	map_count(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	while (keys != map->data.first)
	{
		if (!(*map->key_cmp)(keys->data, key))
			return (true);
		values = values->next;
		keys = keys->next;
	}
	return (false);
}
