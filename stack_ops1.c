/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:07 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/08 17:41:54 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // del

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
	printf("sa\n"); // del
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
	printf("sb\n"); // del
}

void	push_a(t_ps *ps)
{
	t_lld	*b;

	if (!ps || ps->b.size == 0)
		return ;
	b = ps->b.top;
	ps->b.top = b->next;
	if (ps->b.top)
		ps->b.top->prev = NULL;
	else
		ps->b.bottom = NULL;
	b->prev = NULL;
	b->next = ps->a.top;
	if (ps->a.top)
		ps->a.top->prev = b;
	else
		ps->a.bottom = b;
	ps->a.top = b;
	ps->a.size++;
	ps->b.size--;
	printf("pa\n"); // del
}

void	push_b(t_ps *ps)
{
	t_lld	*a;

	if (!ps || ps->a.size == 0)
		return ;
	a = ps->a.top;
	ps->a.top = a->next;
	if (ps->a.top)
		ps->a.top->prev = NULL;
	else
		ps->a.bottom = NULL;
	a->prev = NULL;
	a->next = ps->b.top;
	if (ps->b.top)
		ps->b.top->prev = a;
	else
		ps->b.bottom = a;
	ps->b.top = a;
	ps->b.size++;
	ps->a.size--;
	printf("pb\n"); // del
}
