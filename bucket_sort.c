/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:05:41 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/22 11:54:10 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bucket_sort.h"
#include "bucket_sort_utils.h"
#include "utils.h"
#include "insertion_sort.h"

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
	ssize_t				nearest;
	t_find_gap *fg;

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

size_t	get_first_bucket(t_ps *ps)
{
	size_t	i;

	i = 0;
	while (i < ps->bucket_sort.bucket_ct
		&& ps->bucket_sort.buckets[i].size == 0)
	{
		i++;
	}
	return (i);
}

void	sort_buckets(t_ps *ps)
{
	size_t	norme;

	ps->bucket_sort.ctor = &(t_collector){
		.ps = ps,
		.data = &ps->bucket_sort,
	};
	ps->bucket_sort.fg = &(t_find_gap){.stack = &ps->a,
		.filter = bucket_selective, .data = &ps->bucket_sort.pushing_bucket};
	ps->bucket_sort.pushing_bucket = get_first_bucket(ps);
	norme = ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
	ps->bucket_sort.pushing_remaining = norme;
	push_first_number_of_first_bucket(ps);
	ps->bucket_sort.ctor->collect_fun = &push_b;
	while (ps->bucket_sort.pushing_bucket < ps->bucket_sort.bucket_ct - 1)
	{
		push_bucket(ps);
		ps->bucket_sort.pushing_bucket++;
		if (ps->bucket_sort.pushing_bucket >= ps->bucket_sort.bucket_ct)
			break ;
		norme = ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
		ps->bucket_sort.pushing_remaining = norme;
	}
	push_last_bucket(ps);
}

int	bucket_selective(t_custom *v, int i, void *data)
{
	size_t *const	bucket = data;

	(void)i;
	return (v->this->value.bucket_index == *bucket);
}

void	count_buckets(t_stack *a, t_bucket_sort *bucket_sort)
{
	cdll_iter(a->head, set_bucket, bucket_sort);
}

void	set_occupied_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort *const	bucket_sort = data;
	size_t					bucket_index;
	t_bucket				*bucket;

	(void)i;
	bucket_index = bucket_sort->bucket_ct * ((ssize_t)v->num
			- (ssize_t)bucket_sort->minmax[0])
		/ ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0]
			+ 1);
	if (bucket_index >= bucket_sort->bucket_ct)
		bucket_index = bucket_sort->bucket_ct - 1;
	bucket = &bucket_sort->buckets[bucket_index];
	if (bucket->size > 0 && !bucket->counted)
	{
		bucket->counted = 1;
		bucket_sort->occupied_ct++;
	}
}

void	count_occupied_buckets(t_stack *a, t_bucket_sort *bucket_sort)
{
	cdll_iter(a->head, set_occupied_bucket, bucket_sort);
}

void	set_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort *const	bucket_sort = data;
	size_t					bucket_index;

	(void)i;
	bucket_index = bucket_sort->bucket_ct * ((ssize_t)v->num
			- (ssize_t)bucket_sort->minmax[0])
		/ ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0]
			+ 1);
	if (bucket_index >= bucket_sort->bucket_ct)
		bucket_index = bucket_sort->bucket_ct - 1;
	v->bucket_index = bucket_index;
	bucket_sort->buckets[bucket_index].size++;
}

static void	set_cheap_bucket(int i, t_ps *ps, t_move *m, int target_a)
{
	if (i <= ps->b.size / 2)
	{
		(*m).b_dir = 1;
		(*m).b_count = i;
	}
	else
	{
		(*m).b_dir = -1;
		(*m).b_count = ps->b.size - i;
	}
	if (target_a <= ps->a.size / 2)
	{
		(*m).a_dir = 1;
		(*m).a_count = target_a;
	}
	else
	{
		(*m).a_dir = -1;
		(*m).a_count = ps->a.size - target_a;
	}
}

static void	set_best_bucket(t_move *m, t_move **best)
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
		set_best_bucket(&m, &best);
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
