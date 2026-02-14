/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:41:18 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/14 00:56:22 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "dll.h"
#include <stddef.h>
#include <stdlib.h>

t_dll	*clld_new(t_custom value)
{
	t_dll *const	l = malloc(sizeof(t_dll));

	if (!l)
		return (NULL);
	l->value = value;
	l->next = l;
	l->prev = l;
	return (l);
}

/**
 * ensure least one element in the list before calling
 * @return new head
 */
t_dll	*cdll_add_front(t_dll *head, t_dll *tail, t_dll *new)
{
	new->prev = tail;
	new->next = head;
	tail->next = new;
	head->prev = new;
	return head;
}

void	cdll_link(t_dll *a, t_dll *b, t_dll *c)
{
	b->value.this = b;
	b->prev = a;
	b->next = c;
}

void	cdll_iter(t_dll *lst, void (*f)(t_custom *v, int i, void *data), void *data)
{
	t_dll	* const tail = lst->prev;
	int i;

	i = 0;
	f(&lst->value, i++, data);
	lst = lst->next;
	while (lst != tail->next)
	{
		f(&lst->value, i++, data);
		lst = lst->next;
	}
}

t_dll	*cdll_find(t_dll *lst, int (*f)(t_custom *v, int i, void *data), void *data)
{
	t_dll	* const tail = lst->prev;
	int i;

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

int		cdll_some(t_dll *lst, int (*f)(t_custom *v, int i, void *data), void *data)
{
	t_dll	* const tail = lst->prev;
	int i;

	i = 0;
	if (f(&lst->value, i++, data))
		return (1);
	lst = lst->next;
	while (lst != tail->next)
	{
		if (f(&lst->value, i++, data))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		cdll_every(t_dll *lst, int (*f)(t_custom *v, int i, void *data), void *data)
{
	t_dll	* const tail = lst->prev;
	int i;

	i = 0;
	if (!f(&lst->value, i++, data))
		return (0);
	lst = lst->next;
	while (lst != tail->next)
	{
		if (!f(&lst->value, i++, data))
			return (0);
		lst = lst->next;
	}
	return (1);
}
