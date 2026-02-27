/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:51:20 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/23 15:52:08 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bucket_sort.h"
#include "utils.h"

int	pushb_buckets_num(t_collector *ctor)
{
	t_bucket_sort *const	sorter = ctor->data;

	if (bucket_selective(&ctor->ps->a.head->value, 0,
			&sorter->pushing_bucket) == 0)
	{
		ctor->ps->instruction[ctor->shift_cmd](ctor->ps);
		return (0);
	}
	ctor->collect_fun(ctor->ps);
	cdll_iter(ctor->ps->a.head, indexer, NULL);
	sorter->pushing_remaining--;
	return (1);
}

void	push_last_bucket(t_ps *ps)
{
	int	i;

	i = ps->a.size - 1;
	while (i--)
	{
		push_b(ps);
	}
	push_b_last(ps);
	cdll_iter(ps->b.head, indexer, NULL);
}

void	update_collector(t_ps *ps, t_collector *ctor)
{
	ssize_t		nearest;
	t_find_gap	*fg;

	fg = ps->bucket_sort.fg;
	get_biggest_gap(fg);
	nearest = get_nearest(fg->duo[0]->value.index, fg->duo[1]->value.index,
			fg->stack);
	if (nearest > 0)
		ctor->shift_cmd = RA;
	else if (nearest < 0)
		ctor->shift_cmd = RRA;
	ctor->limit = ft_abs(nearest);
}

void	push_first_number_of_first_bucket(t_ps *ps)
{
	update_collector(ps, ps->bucket_sort.ctor);
	ps->bucket_sort.ctor->collect_fun = &push_b_first;
	while (ps->bucket_sort.ctor->limit-- != (size_t)-1)
		if (pushb_buckets_num(ps->bucket_sort.ctor) == 1)
			return ;
}

void	push_bucket(t_ps *ps)
{
	while (ps->bucket_sort.pushing_remaining != 0)
	{
		update_collector(ps, ps->bucket_sort.ctor);
		while (ps->bucket_sort.ctor->limit-- != ((size_t) - 1))
			pushb_buckets_num(ps->bucket_sort.ctor);
	}
}
