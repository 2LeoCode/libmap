/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:47:11 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 17:23:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <stdio.h>

static t_size	get_data_size(const void *data, t_type type)
{
	char	*data_checker;
	t_bool	is_end;
	t_size	size;
	int		i;

	is_end = false;
	size = 0;
	data_checker = (char *)data;
	while (!is_end)
	{
		is_end = true;
		i = -1;
		while (++i < (int)type)
			if (data_checker[i] != 0)
				is_end = false;
		size += !is_end;
		data_checker += type;
	}
	return (size);
}

t_list	*lst_dup(const t_list *sentinel, t_type type)
{
	t_list	*new_list;
	t_list	*tmp;
	t_size	size;

	new_list = lst_new_sentinel();
	if (!new_list)
		return (NULL);
	tmp = sentinel->next;
	while (tmp != sentinel)
	{
		size = get_data_size(tmp->data, type);
		if (lst_push_back(new_list, type, tmp->data, size))
			return (lst_clear(new_list));
		tmp = tmp->next;
	}
	return (new_list);
}
