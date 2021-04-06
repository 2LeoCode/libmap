/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:46:07 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:13:35 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

t_list	*map_find(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	while (keys != map->data.first)
	{
		if (!(*map->key_cmp)(keys->data, key))
			return (values);
		values = values->next;
		keys = keys->next;
	}
	return (NULL);
}

t_list	*map_find_key(t_map *map, void *value)
{
	t_list	*keys;
	t_list	*values;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	while (keys != map->data.first)
	{
		if (!(*map->value_cmp)(values->data, value))
			return (keys);
		values = values->next;
		keys = keys->next;
	}
	return (NULL);
}

t_list	*map_lower_bound(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;
	t_list	*lower;
	int		cmp_lower;
	int		cmp_ret;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	lower = NULL;
	while (keys != map->data.first)
	{
		cmp_ret = (*map->key_cmp)(keys->data, key);
		if ((cmp_ret <= 0) && (!lower || (cmp_ret > cmp_lower)))
		{
			lower = values;
			cmp_lower = cmp_ret;
		}
		values = values->next;
		keys = keys->next;
	}
	if (!lower)
		return (NULL);
	return (lower);
}

t_list	*map_upper_bound(t_map *map, void *key)
{
	t_list	*keys;
	t_list	*values;
	t_list	*upper;
	int		cmp_upper;
	int		cmp_ret;

	keys = ((t_list *)map->data.first)->next;
	values = ((t_list *)map->data.second)->next;
	upper = NULL;
	while (keys != map->data.first)
	{
		cmp_ret = (*map->key_cmp)(keys->data, key);
		if ((cmp_ret > 0) && (!upper || (cmp_ret < cmp_upper)))
		{
			upper = values;
			cmp_upper = cmp_ret;
		}
		values = values->next;
		keys = keys->next;
	}
	if (!upper)
		return (NULL);
	return (upper);
}

t_pair	map_equal_range(t_map *map, void *key)
{
	return (pair((void *)map_lower_bound(map, key),
			(void *)map_upper_bound(map, key)));
}
