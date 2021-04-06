/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cmp_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 02:25:42 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/05 22:29:44 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

int	float_cmp(const void *m1, const void *m2)
{
	const float	*s1 = (float *)m1;
	const float	*s2 = (float *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	double_cmp(const void *m1, const void *m2)
{
	const double	*s1 = (double *)m1;
	const double	*s2 = (double *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	ldouble_cmp(const void *m1, const void *m2)
{
	const long double	*s1 = (long double *)m1;
	const long double	*s2 = (long double *)m2;

	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}

int	ptr_cmp(const void *m1, const void *m2)
{
	char	**s1;
	char	**s2;

	s1 = (char **)m1;
	s2 = (char **)m2;
	while (*s1 && *s2 && !char_cmp((void *)*s1, (void *)*s2))
	{
		s1++;
		s2++;
	}
	return ((*s1 > *s2) - (*s1 < *s2));
}
