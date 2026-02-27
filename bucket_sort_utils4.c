/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:51:16 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/23 15:52:54 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bucket_sort.h"

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
	ps->bucket_sort.ctor = &(t_collector){
		.ps = ps,
		.data = &ps->bucket_sort,
	};
	ps->bucket_sort.fg = &(t_find_gap){.stack = &ps->a,
		.filter = bucket_selective, .data = &ps->bucket_sort.pushing_bucket};
	ps->bucket_sort.pushing_bucket = get_first_bucket(ps);
	ps->bucket_sort.pushing_remaining
		= ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
	push_first_number_of_first_bucket(ps);
	ps->bucket_sort.ctor->collect_fun = &push_b;
	while (ps->bucket_sort.pushing_bucket < ps->bucket_sort.bucket_ct - 1)
	{
		push_bucket(ps);
		ps->bucket_sort.pushing_bucket++;
		if (ps->bucket_sort.pushing_bucket >= ps->bucket_sort.bucket_ct)
			break ;
		ps->bucket_sort.pushing_remaining
			= ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
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

void	set_bucket(t_custom *v, int i, void *data)
{
	size_t					bucket_index;
	t_bucket_sort *const	bucket_sort = data;

	(void)i;
	bucket_index = bucket_sort->bucket_ct * ((ssize_t)v->num
			- (ssize_t)bucket_sort->minmax[0])
		/ ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0]
			+ 1);
	v->bucket_index = bucket_index;
	bucket_sort->buckets[bucket_index].size++;
}
