/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:14:01 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:26:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_rev(t_list *sentinel)
{
	t_list	*lst;

	lst = sentinel->next;
	while (lst != sentinel)
	{
		ft_swap(&lst->prev, &lst->next, POINTER);
		lst = lst->prev;
	}
	ft_swap(&sentinel->prev, &sentinel->next, POINTER);
}
