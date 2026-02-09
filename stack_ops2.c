/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:19 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 03:11:27 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_a(t_ps *ps)
{
	t_lld	*old_top;
	t_lld	*new_top;
	
	if (!ps || ps->a.size <= 1)
		return ;
	old_top = ps->a.top;
	new_top = old_top->next;
	ps->a.top = new_top;
	new_top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = ps->a.bottom;
	ps->a.bottom->next = old_top;
	ps->a.bottom = old_top;
	printf("ra\n"); // del
}

void	rotate_b(t_ps *ps)
{
	t_lld	*old_top;
	t_lld	*new_top;

	if (!ps || ps->b.size <= 1)
		return ;
	old_top = ps->b.top;
	new_top = ps->b.top->next;
	ps->b.top = new_top;
	new_top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = ps->b.bottom;
	ps->b.bottom->next = old_top;
	ps->b.bottom = old_top;
	printf("rb\n"); // del
}

void	reverse_rotate_a(t_ps *ps)
{
	t_lld	*old_bottom;
	t_lld	*new_bottom;

	if (!ps || ps->a.size <= 1)
		return ;
	old_bottom = ps->a.bottom;
	new_bottom = ps->a.bottom->prev;
	ps->a.bottom = new_bottom;
	new_bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = ps->a.top;
	ps->a.top->prev = old_bottom;
	ps->a.top = old_bottom;
	printf("rra\n"); // del
}

void	reverse_rotate_b(t_ps *ps)
{
	t_lld	*old_bottom;
	t_lld	*new_bottom;

	if (!ps || ps->b.size <= 1)
		return ;
	old_bottom = ps->b.bottom;
	new_bottom = ps->b.bottom->prev;
	ps->b.bottom = new_bottom;
	new_bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = ps->b.top;
	ps->b.top->prev = old_bottom;
	ps->b.top = old_bottom;
	printf("rrb\n"); // del
}
