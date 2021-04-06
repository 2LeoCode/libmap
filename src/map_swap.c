/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:40:11 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 21:46:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

int	map_swap(t_map *a, t_map *b)
{
	int	ret;

	if ((a->type.first != b->type.first) || (a->type.second != b->type.second))
		return (-1);
	ret = ft_swap(&a->data.first, &b->data.first, POINTER);
	ret += ft_swap(&a->data.second, &b->data.second, POINTER);
	ret += ft_swap(&a->begin, &b->begin, POINTER);
	ret += ft_swap(&a->end, &b->end, POINTER);
	ret += ft_swap(&a->rbegin, &b->rbegin, POINTER);
	ret += ft_swap(&a->rend, &b->rend, POINTER);
	ret += ft_swap(&a->empty, &b->empty, CHAR);
	ret += ft_swap(&a->size, &b->size, INT);
	ret += ft_swap(&a->key_cmp, &b->key_cmp, POINTER);
	ret += ft_swap(&a->value_cmp, &b->value_cmp, POINTER);
	if (ret < 0)
		return ((int)map_clear(a) + (int)map_clear(b) - 1);
	return (0);
}
