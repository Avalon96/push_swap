/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:05:41 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/23 15:51:05 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bucket_sort.h"
#include "bucket_sort_utils.h"
#include "insertion_sort.h"
#include "push_swap.h"
#include "utils.h"

static void	set_cheap_bucket(int i, t_ps *ps, t_move *m, int target_a)
{
	m->a_dir = (get_relative_index(target_a, ps->a.size) < 0) * -1
		+ (get_relative_index(target_a, ps->a.size) >= 0) * 1;
	m->a_count = ft_abs(get_relative_index(target_a, ps->a.size));
	m->b_dir = (get_relative_index(i, ps->b.size) < 0) * -1
		+ (get_relative_index(i, ps->b.size) >= 0) * 1;
	m->b_count = ft_abs(get_relative_index(i, ps->b.size));
	if (m->a_dir == m->b_dir)
	{
		if (m->a_count > m->b_count)
			m->total = m->a_count;
		else
			m->total = m->b_count;
	}
	else
		m->total = m->a_count + m->b_count;
}

static void	set_cheapest_move_bucket(t_ps *ps, t_move *best)
{
	t_dll	*curr_b;
	t_move	m;
	int		i;
	int		target_a;

	curr_b = ps->b.head;
	best->total = 2147483647;
	i = 0;
	while (i < ps->b.size)
	{
		target_a = find_target_in_a(&ps->a, curr_b->value.num);
		set_cheap_bucket(i, ps, &m, target_a);
		if (m.total < best->total)
			*best = m;
		curr_b = curr_b->next;
		i++;
	}
}

static void	execute_move_to_a(t_ps *ps, t_move m)
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
	push_a(ps);
}

static void	push_b_to_a(t_ps *ps)
{
	t_move	best;

	while (ps->b.size > 0)
	{
		if (ps->a.size == 0)
		{
			push_a(ps);
			continue ;
		}
		set_cheapest_move_bucket(ps, &best);
		execute_move_to_a(ps, best);
	}
	cdll_iter(ps->a.head, indexer, NULL);
	rotate_a_to_top(ps, get_min_pos(&ps->a));
	cdll_iter(ps->a.head, indexer, NULL);
}

void	sort_buckets_insertion(t_ps *ps)
{
	int	bucket;

	bucket = ps->bucket_sort.bucket_ct;
	sort_buckets(ps);
	push_b_to_a(ps);
}
