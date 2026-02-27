/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:23:46 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/26 12:20:42 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bucket_sort.h"
#include "libft.h"
#include "utils.h"

int	medium_sort(t_ps *ps)
{
	t_bucket_sort *const	bucket_sort = &ps->bucket_sort;

	if (ps->disorder == 0)
		return (0);
	bucket_sort->bucket_ct = safe_sqrt(ps->a.size);
	cdll_iter(ps->a.head, minmax, &bucket_sort->minmax);
	cdll_iter(ps->a.head, indexer, NULL);
	bucket_sort->buckets = ft_calloc(bucket_sort->bucket_ct, sizeof(t_bucket));
	if (!bucket_sort->buckets)
		return (-1);
	count_buckets(&ps->a, bucket_sort);
	if (brute_force(ps))
		return (0);
	sort_buckets(ps);
	push_b_to_a(ps);
	return (0);
}

int	complex_sort(t_ps *ps)
{
	if (ps->disorder == 0)
		return (0);
	radix_sort(ps);
	return (0);
}

int	adaptive_sort(t_ps *ps)
{
	if (ps->disorder == 0)
		return (0);
	else if (ps->disorder < 20)
		simple_sort(ps);
	else if (ps->disorder < 50)
		medium_sort(ps);
	else
		complex_sort(ps);
	return (0);
}

int	simple_sort(t_ps *ps)
{
	if (ps->disorder == 0)
		return (0);
	insertion_sort(ps);
	return (0);
}
