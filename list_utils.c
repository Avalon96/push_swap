/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:41:18 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/21 16:25:00 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include <stdlib.h>

void	cdll_link(t_dll *a, t_dll *b, t_dll *c)
{
	b->value.this = b;
	b->prev = a;
	b->next = c;
}

void	cdll_iter(t_dll *lst, void (*f)(t_custom *v, int i, void *data),
		void *data)
{
	int				i;
	t_dll *const	tail = lst->prev;

	i = 0;
	f(&lst->value, i++, data);
	lst = lst->next;
	while (lst != tail->next)
	{
		f(&lst->value, i++, data);
		lst = lst->next;
	}
}

t_dll	*cdll_find(t_dll *lst, int (*f)(t_custom *v, int i, void *data),
		void *data)
{
	int				i;
	t_dll *const	tail = lst->prev;

	i = 0;
	if (f(&lst->value, i++, data))
		return (lst);
	lst = lst->next;
	while (lst != tail->next)
	{
		if (f(&lst->value, i++, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
