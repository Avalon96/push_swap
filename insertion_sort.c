/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:45:38 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 17:57:56 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "insertion_sort.h"

static void	set_cheap(int i, t_ps *ps, t_move *m, int target_b)
{
	if (i <= ps->a.size / 2)
	{
		(*m).a_dir = 1;
		(*m).a_count = i;
	}
	else
	{
		(*m).a_dir = -1;
		(*m).a_count = ps->a.size - i;
	}
	if (target_b <= ps->b.size / 2)
	{
		(*m).b_dir = 1;
		(*m).b_count = target_b;
	}
	else
	{
		(*m).b_dir = -1;
		(*m).b_count = ps->b.size - target_b;
	}
}

static void	set_best(t_move *m, t_move **best)
{
	if ((*m).a_dir == (*m).b_dir)
	{
		if ((*m).a_count > (*m).b_count)
			(*m).total = (*m).a_count;
		else
			(*m).total = (*m).b_count;
	}
	else
		(*m).total = (*m).a_count + (*m).b_count;
	if ((*m).total < (*best)->total)
		**best = *m;
}

static void	set_cheapest_move(t_ps *ps, t_move *best)
{
	t_dll	*curr_a;
	t_move	m;
	int		i;
	int		target_b;

	curr_a = ps->a.head;
	best->total = 2147483647;
	i = 0;
	while (i < ps->a.size)
	{
		target_b = find_target_in_b(&ps->b, curr_a->value.num);
		set_cheap(i, ps, &m, target_b);
		set_best(&m, &best);
		curr_a = curr_a->next;
		i++;
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
		target = find_target_in_a(&ps->a, ps->b.head->value.num);
		rotate_a_to_top(ps, target);
		push_a(ps);
	}
	rotate_a_to_top(ps, get_min_pos(&ps->a));
}
