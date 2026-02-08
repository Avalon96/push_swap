/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:07 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/08 12:45:07 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_ps *ps)
{
	t_lld	*first;
	t_lld	*second;

	if (!ps || ps->a.size < 2)
		return ;
	first = ps->a.top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	ps->a.top = second;
}

void	swap_b(t_ps *ps)
{
	t_lld	*first;
	t_lld	*second;

	if (!ps || ps->b.size < 2)
		return ;
	first = ps->b.top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	ps->b.top = second;
}

void	push_a(t_ps *ps)
{
	t_lld	*a;
	t_lld	*b;

	if (!ps || ps->b.size == 0)
		return ;
	a = ps->a.top;
	b = ps->b.top;
	ps->b.top = b->next;
	if (ps->b.top)
		ps->b.top->prev = NULL;
	b->prev = NULL;
	b->next = a;
	if (a)
		a->prev = b;
	ps->a.top = b;
	ps->a.size++;
	ps->b.size--;
}

void	push_b(t_ps *ps)
{
	t_lld	*a;
	t_lld	*b;

	if (!ps || ps->a.size == 0)
		return ;
	a = ps->a.top;
	b = ps->b.top;
	ps->a.top = a->next;
	if (ps->a.top)
		ps->a.top->prev = NULL;
	a->prev = NULL;
	a->next = b;
	if (b)
		b->prev = a;
	ps->b.top = a;
	ps->b.size++;
	ps->a.size--;
}
