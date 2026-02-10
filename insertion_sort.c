/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:45:38 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/10 18:55:49 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *s)
{
	t_dll	*curr;
	int		max_val;
	int		max_pos;
	int		i;

	curr = s->head;
	max_val = curr->value;
	max_pos = 0;
	i = 0;
	while (i < s->size)
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

static int	get_min_pos(t_stack *s)
{
	t_dll	*curr;
	int		min_val;
	int		min_pos;
	int		i;

	curr = s->head;
	min_val = curr->value;
	min_pos = 0;
	i = 0;
	while (i < s->size)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

static int	find_target_in_b(t_stack *b, int val)
{
	t_dll	*curr;
	int		i;

	if (val < stack_min(b) || val > stack_max(b))
		return (get_max_pos(b));
	curr = b->head;
	i = 0;
	while (i < b->size)
	{
		if (curr->value > val && curr->next->value < val)
			return (i + 1);
		curr = curr->next;
		i++;
	}
	return (0);
}

static int	find_target_in_a(t_stack *a, int val)
{
	t_dll	*curr;
	int		i;

	if (val < stack_min(a) || val > stack_max(a))
		return (get_min_pos(a));
	curr = a->head;
	i = 0;
	while (i < a->size)
	{
		if (curr->value > val && curr->prev->value < val)
			return (i);
		curr = curr->next;
		i++;
	}
	return (0);
}

static void	set_cheapest_move(t_ps *ps, t_move *best)
{
	t_dll	*curr_a;
	t_move	m;
	int		i;
	int		target_b;

	curr_a = ps->a.head;
	best->total = 2147483647;
	i = -1;
	while (++i < ps->a.size)
	{
		if (i <= ps->a.size / 2)
		{
			m.a_dir = 1;
			m.a_count = i;
		}
		else
		{
			m.a_dir = -1;
			m.a_count = ps->a.size - i;
		}
		target_b = find_target_in_b(&ps->b, curr_a->value);
		if (target_b <= ps->b.size / 2)
		{
			m.b_dir = 1;
			m.b_count = target_b;
		}
		else
		{
			m.b_dir = -1;
			m.b_count = ps->b.size - target_b;
		}
		if (m.a_dir == m.b_dir)
		{
			if (m.a_count > m.b_count)
				m.total = m.a_count;
			else
				m.total = m.b_count;
		}
		else
			m.total = m.a_count + m.b_count;
		if (m.total < best->total)
			*best = m;
		curr_a = curr_a->next;
	}
}

static void	execute_move(t_ps *ps, t_move m)
{
	while (m.a_dir == m.b_dir && m.a_count > 0 && m.b_count > 0)
	{
		if (m.a_dir == 1)
			rotate_both(ps);
		else
			reverse_rotate_both(ps);
		m.a_count--;
		m.b_count--;
	}
	while (m.a_count-- > 0)
	{
		if (m.a_dir == 1)
			rotate_a(ps);
		else
			reverse_rotate_a(ps);
	}
	while (m.b_count-- > 0)
	{
		if (m.b_dir == 1)
			rotate_b(ps);
		else
			reverse_rotate_b(ps);
	}
	push_b(ps);
}

static void	sort_three_a(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a.head->value;
	second = ps->a.head->next->value;
	third = ps->a.head->prev->value;
	if (first > second && second < third && first < third)
		swap_a(ps);
	else if (first > second && second > third)
	{
		swap_a(ps);
		reverse_rotate_a(ps);
	}
	else if (first > second && second < third && first > third)
		rotate_a(ps);
	else if (first < second && second > third && first < third)
	{
		swap_a(ps);
		rotate_a(ps);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(ps);
}

static void	rotate_a_to_top(t_ps *ps, int pos)
{
	int	size;

	size = ps->a.size;
	if (pos <= size / 2)
		while (pos--)
			rotate_a(ps);
	else
	{
		pos = size - pos;
		while (pos--)
			reverse_rotate_a(ps);
	}
}

void	insertion_sort(t_ps *ps)
{
	t_move	best;
	int		target;

	if (ps->a.size > 3)
		push_b(ps);
	if (ps->a.size > 3)
		push_b(ps);
	while (ps->a.size > 3)
	{
		set_cheapest_move(ps, &best);
		execute_move(ps, best);
	}
	sort_three_a(ps);
	while (ps->b.size > 0)
	{
		target = find_target_in_a(&ps->a, ps->b.head->value);
		rotate_a_to_top(ps, target);
		push_a(ps);
	}
	rotate_a_to_top(ps, get_min_pos(&ps->a));
}
