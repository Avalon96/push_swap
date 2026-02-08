/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:45:38 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/08 18:36:46 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *s)
{
	t_lld	*curr;
	int		max_val;
	int		max_pos;
	int		i;

	curr = s->top;
	max_val = curr->value;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

static int	find_insert_position(t_stack *b, int value)
{
	t_lld	*curr;
	int		pos;

	if (value > stack_max(b) || value < stack_min(b))
		return (get_max_pos(b));
	curr = b->top;
	pos = 1;
	while (curr->next)
	{
		if (curr->value > value && curr->next->value < value)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (0);
}

static void	rotate_to_position(t_ps *ps, int pos)
{
	int	size;

	size = ps->b.size;
	if (pos <= size / 2)
	{
		while (pos--)
			rotate_b(ps);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			reverse_rotate_b(ps);
	}
}

void	insertion_sort(t_ps *ps)
{
	int	pos;

	if (ps->a.size > 0)
		push_b(ps);
	if (ps->a.size > 0)
		push_b(ps);
	while (ps->a.size > 0)
	{
		pos = find_insert_position(&ps->b, ps->a.top->value);
		rotate_to_position(ps, pos);
		push_b(ps);
	}
	pos = get_max_pos(&ps->b);
	rotate_to_position(ps, pos);
	while (ps->b.size > 0)
		push_a(ps);
}
