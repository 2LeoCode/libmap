/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cmp_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 02:00:04 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 16:33:56 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

int	char_cmp(const void *m1, const void *m2)
{
	const char	*s1 = (char *)m1;
	const char	*s2 = (char *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	short_cmp(const void *m1, const void *m2)
{
	const short	*s1 = (short *)m1;
	const short	*s2 = (short *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	int_cmp(const void *m1, const void *m2)
{
	const int	*s1 = (int *)m1;
	const int	*s2 = (int *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	long_cmp(const void *m1, const void *m2)
{
	const long	*s1 = (long *)m1;
	const long	*s2 = (long *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	llong_cmp(const void *m1, const void *m2)
{
	const long long	*s1 = (long long *)m1;
	const long long	*s2 = (long long *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}
