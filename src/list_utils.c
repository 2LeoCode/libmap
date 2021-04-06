/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:28:14 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:04:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	*destroy(void *data)
{
	free(data);
	return (NULL);
}

void	*alloc_type(t_type type, t_size size)
{
	return (malloc(type * size));
}

t_size	ft_strlen(const char *s)
{
	t_size	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, void *src, t_size size)
{
	void	*begin;

	begin = dst;
	while (size--)
		*((char *)dst++) = *((char *)src++);
	return (begin);
}

int	ft_swap(void *a, void *b, t_type type)
{
	void	*tmp;

	tmp = malloc((size_t)type);
	if (!tmp)
		return (-1);
	ft_memcpy(tmp, b, (t_size)type);
	ft_memcpy(b, a, (t_size)type);
	ft_memcpy(a, tmp, (t_size)type);
	free(tmp);
	tmp = NULL;
	return (0);
}
