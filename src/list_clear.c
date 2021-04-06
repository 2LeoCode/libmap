/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:32:19 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:05:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	*lst_clear(t_list *sentinel)
{
	t_list	*tmp;
	t_list	*head;

	tmp = sentinel->next;
	while (tmp != sentinel)
	{
		free(tmp->data);
		tmp->data = NULL;
		head = tmp->next;
		free(tmp);
		tmp = head;
	}
	free(sentinel);
	return (NULL);
}
