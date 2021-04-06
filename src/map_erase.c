/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_erase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:14:38 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 17:23:57 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

static t_bool	map_contains(t_map *map, t_list *member)
{
	t_list	*check;

	check = member->next;
	while (check != map->end)
	{
		if ((check == NULL) || (check == member))
			return (false);
		check = check->next;
	}
	return (true);
}

int	map_erase(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	while (keys != ((t_list *)map->data.first))
	{
		if (!(*map->key_cmp)(keys->data, key))
		{
			if (values == map->begin)
				map->begin = values->next;
			else if (values == map->rbegin)
				map->rbegin = values->prev;
			lst_rm(keys);
			lst_rm(values);
			if (!--map->size)
				map->empty = true;
			return (1);
		}
		values = values->next;
		keys = keys->next;
	}
	return (0);
}

int	map_erase_member(t_map *map, t_list *member)
{
	if (!map_contains(map, member))
		return (0);
	return (lst_rm(member));
}

int	map_erase_range(t_map *map, t_list *begin, t_list *end)
{
	int		rm_count;
	t_list	*key;
	t_list	*tmp;

	if ((begin == end) || !map_contains(map, begin) || !map_contains(map, end))
		return (0);
	rm_count = 0;
	key = map_find_key(map, begin->data);
	while ((begin != end) && (begin != map->end))
	{
		if (begin == map->begin)
			map->begin = begin->next;
		else if (begin == map->rbegin)
			map->rbegin = begin->prev;
		tmp = begin->next;
		lst_rm(begin);
		begin = tmp;
		tmp = key->next;
		lst_rm(key);
		key = tmp;
		rm_count++;
	}
	map->size -= rm_count;
	map->empty = !map->size;
	return (rm_count);
}
