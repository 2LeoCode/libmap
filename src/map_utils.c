/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:45:38 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/04 23:20:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

t_pair	pair(void *first, void *second)
{
	return ((t_pair){first, second});
}

t_pair	size_pair(t_size first, t_size second)
{
	return ((t_pair){(void *)first, (void *)second});
}
