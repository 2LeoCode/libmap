/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:24:07 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:33:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_size	lst_size(const t_list *sentinel)
{
	t_size	size;
	t_list	*tmp;

	size = 0;
	tmp = ((t_list *)sentinel)->next;
	while (tmp != sentinel)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
