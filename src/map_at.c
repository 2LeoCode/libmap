/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:34:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:33:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

void	*map_at(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	while (keys != map->data.first)
	{
		if (!(*map->key_cmp)(keys->data, key))
			return (values->data);
		values = values->next;
		keys = keys->next;
	}
	return (NULL);
}
