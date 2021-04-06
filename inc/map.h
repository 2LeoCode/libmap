/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:59:19 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 17:24:30 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "list.h"

typedef struct s_pair
{
	void	*first;
	void	*second;
}	t_pair;

typedef struct s_map
{
	t_pair	type;
	t_pair	data;
	void	*begin;
	void	*end;
	void	*rbegin;
	void	*rend;
	t_cmpf	key_cmp;
	t_cmpf	value_cmp;
	t_size	size;
	t_bool	empty;
}	t_map;

int		map_init(t_map *map, t_type key_type, t_type value_type);

int		map_insert(t_map *map, t_pair data, t_pair size);

void	*map_at(t_map *map, void *key);

t_bool	map_count(t_map *map, void *key);

t_list	*map_find(t_map *map, void *key);
t_list	*map_find_key(t_map *map, void *value);

int		map_erase(t_map *map, void *key);
int		map_erase_member(t_map *map, t_list *member);
int		map_erase_range(t_map *map, t_list *begin, t_list *end);

int		map_swap(t_map *a, t_map *b);

void	*map_clear(t_map *map);

int		char_cmp(const void *m1, const void *m2);
int		short_cmp(const void *m1, const void *m2);
int		long_cmp(const void *m1, const void *m2);
int		int_cmp(const void *m1, const void *m2);
int		llong_cmp(const void *m1, const void *m2);
int		float_cmp(const void *m1, const void *m2);
int		double_cmp(const void *m1, const void *m2);
int		ldouble_cmp(const void *m1, const void *m2);
int		ptr_cmp(const void *m1, const void *m2);

t_pair	pair(void *first, void *second);
t_pair	size_pair(t_size first, t_size second);

#endif
