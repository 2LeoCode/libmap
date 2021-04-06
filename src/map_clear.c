/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:30:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 21:16:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

void	*map_clear(t_map *map)
{
	map->type.first = NULL;
	map->type.second = NULL;
	lst_clear(map->data.first);
	map->data.first = NULL;
	lst_clear(map->data.second);
	map->data.second = NULL;
	map->begin = NULL;
	map->end = NULL;
	map->rbegin = NULL;
	map->rend = NULL;
	map->empty = false;
	map->size = 0;
	map->key_cmp = NULL;
	map->value_cmp = NULL;
	return (NULL);
}
