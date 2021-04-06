/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:21:05 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 13:25:17 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_last(const t_list *sentinel)
{
	if (sentinel->prev == sentinel)
		return (NULL);
	return ((t_list *)sentinel->prev);
}

t_list	*lst_first(const t_list *sentinel)
{
	if (sentinel->next == sentinel)
		return (NULL);
	return ((t_list *)sentinel->next);
}
