/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:18:19 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/06 13:53:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef unsigned long	t_size;
typedef int				(*t_cmpf)(const void *, const void *);
typedef char			t_bool;

enum e_bool
{
	false,
	true
};

typedef enum e_type
{
	CHAR = sizeof(char),
	SHORT = sizeof(short),
	INT = sizeof(int),
	LONG = sizeof(long),
	LLONG = sizeof(long long),
	FLOAT = sizeof(float),
	DOUBLE = sizeof(double),
	LDOUBLE = sizeof(long double),
	POINTER = sizeof(void*)
}	t_type;

typedef struct s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*lst_new(t_type type, void *data, t_size size);
t_list	*lst_new_sentinel(void);

int		lst_push_front(t_list *sentinel, t_type type, void *data, t_size size);
int		lst_push_back(t_list *sentinel, t_type type, void *data, t_size size);

void	lst_rev(t_list *sentinel);

t_list	*lst_last(const t_list *sentinel);
t_list	*lst_first(const t_list *sentinel);

t_size	lst_size(const t_list *sentinel);

t_list	*lst_merge(t_list *sentinel_a, t_list *sentinel_b);

t_list	*lst_dup(const t_list *sentinel, t_type type);

int		lst_rm(t_list *member);
int		lst_rm_if(t_list *sentinel, t_cmpf cmp_function, void *dataref);

int		lst_sort(t_list *sentinel, t_cmpf cmp_function);

void	*lst_clear(t_list *sentinel);

void	*destroy(void *data);
t_size	ft_strlen(const char *s);
void	*alloc_type(t_type type, t_size size);
void	*ft_memcpy(void *dst, void *src, t_size size);
int		ft_swap(void *a, void *b, t_type type);

#endif
