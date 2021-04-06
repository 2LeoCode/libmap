/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:59:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 17:06:32 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

static void	init_cmp_list(t_type *type_index, t_cmpf *cmp_list)
{
	cmp_list[0] = char_cmp;
	cmp_list[1] = short_cmp;
	cmp_list[2] = int_cmp;
	cmp_list[3] = long_cmp;
	cmp_list[4] = llong_cmp;
	cmp_list[5] = float_cmp;
	cmp_list[6] = double_cmp;
	cmp_list[7] = ldouble_cmp;
	cmp_list[8] = ptr_cmp;
	type_index[0] = CHAR;
	type_index[1] = SHORT;
	type_index[2] = INT;
	type_index[3] = LONG;
	type_index[4] = LLONG;
	type_index[5] = FLOAT;
	type_index[6] = DOUBLE;
	type_index[7] = LDOUBLE;
	type_index[8] = POINTER;
}

static t_cmpf	map_get_cmp(t_type type)
{
	t_type	type_index[9];
	t_cmpf	cmp_list[9];
	int		i;

	init_cmp_list(type_index, cmp_list);
	i = -1;
	while (type_index[++i])
		if (type_index[i] == type)
			return (cmp_list[i]);
	return (NULL);
}

static t_bool	is_valid_type(t_type type)
{
	return ((type == CHAR) || (type == SHORT) || (type == INT)
		|| (type == LONG) || (type == LLONG) || (type == FLOAT)
		|| (type == DOUBLE) || (type == LDOUBLE));
}

int	map_init(t_map *map, t_type key_type, t_type value_type)
{
	if (!is_valid_type(key_type) || !is_valid_type(value_type)
		|| !(map->data.first = lst_new_sentinel())
		|| !(map->data.second = lst_new_sentinel()))
		return ((int)lst_clear(map->data.first) - 1);
	map->type.first = (void *)key_type;
	map->type.second = (void *)value_type;
	map->begin = map->data.second;
	map->end = map->data.second;
	map->rbegin = map->data.second;
	map->rend = map->data.second;
	map->empty = true;
	map->size = 0;
	map->key_cmp = map_get_cmp(key_type);
	map->value_cmp = map_get_cmp(value_type);
	return (0);
}
