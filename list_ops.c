/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:41:18 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 15:14:39 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

t_dll	*clld_new(int value)
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
	b->prev = a;
	b->next = c;
}

/**
 * bottom ptr is HEAD->prev, cache it for O(1) access.
 * ensure stack->size > 0 before calling
 */
// void	ft_lldadd_front(t_stack *stack, t_dll *new)
// {
// 	new->prev = stack->bottom;
// 	new->next = stack->top;
// 	stack->top->prev = new;
// 	stack->bottom->next = new;
// 	stack->top = new;
// }

int	cdll_size(t_dll *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	cdll_clear(t_dll **lst)
{
	t_dll	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	cdll_iter(t_dll *lst, void (*f)(int *v, int i, void *data), void *data)
{
	if (lst == NULL)
		return ;
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
