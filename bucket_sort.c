/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:05:41 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/25 20:55:16 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bucket_sort.h"
#include "bucket_sort_utils.h"
#include "insertion_sort.h"
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

static void	set_cheapest_move_bucket(t_ps *ps, t_move *best, t_dll	*curr_b)
{
	t_move	m;
	size_t	i;
	int		target_a;

	best->total = 2147483647;
	i = ps->bucket_sort.buckets[curr_b->value.bucket_index].size--;
	while (i)
	{
		target_a = find_target_in_a(&ps->a, curr_b->value.num);
		set_cheap_bucket(curr_b->value.index, ps, &m, target_a);
		if (m.total < best->total)
			*best = m;
		curr_b = curr_b->next;
		i--;
	}
}

static void	update_head(t_ps *ps, t_dll **bucket_head)
{
	if (ps->b.head == *bucket_head)
		*bucket_head = ps->b.head->next;
}

static void	execute_move_to_a(t_ps *ps, t_move m, t_dll **bucket_head)
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
	update_head(ps, bucket_head);
	push_a(ps);
	// decrase bucket size
}

#include <stdio.h> //sssssssss

static void	push_b_to_a(t_ps *ps)
{
	t_move	best;
	t_dll	*bucket_head;
	
	bucket_head = ps->b.head->next;
	while (ps->b.size > 0)
	{
		// if (ps->bucket_sort.buckets[bucket_head->value.bucket_index].size == 0)
		// 	bucket_head = ps->b.head;
		if (ps->a.size == 0)
		{
			ps->bucket_sort.buckets[ps->b.head->value.bucket_index].size--;
			push_a(ps);
			cdll_iter(ps->b.head, indexer, NULL);
			continue ;
		}
		// dprintf(2,"head bucket index %d\n", bucket_head->value.bucket_index);
		set_cheapest_move_bucket(ps, &best, bucket_head);
		// dprintf(2, "cheap HEAD: [%d]:%d ct %d, dir %d\n", bucket_head->value.index, bucket_head->value.num, best.b_count, best.b_dir);
		// fflush(stderr);
		// print_stacks(ps);
		// getchar();
		execute_move_to_a(ps, best, &bucket_head);
		cdll_iter(ps->a.head, indexer, NULL);
		if (ps->b.size > 1)
			cdll_iter(ps->b.head, indexer, NULL);
		// print_stacks(ps);
		// dprintf(2, "HEAD: [%d]:%d \n", bucket_head->value.index, bucket_head->value.num);
		// fflush(stderr);
		// getchar();
		// bucket_head = 
		// ps->bucket_sort.buckets[ps->b.head->value.bucket_index].head
	}
	cdll_iter(ps->a.head, indexer, NULL);
	rotate_a_to_top(ps, get_min_pos(&ps->a));
	cdll_iter(ps->a.head, indexer, NULL);
	// print_stacks(ps);
	// fflush(stderr);
}


void	sort_buckets_insertion(t_ps *ps)
{
	if (brute_force(ps))
		return ;
	sort_buckets(ps);
	push_b_to_a(ps);
}
