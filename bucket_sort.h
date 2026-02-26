/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:37:16 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/26 12:30:08 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCKET_SORT_H
# define BUCKET_SORT_H

# include "dll.h"
# include "bucket_sort_utils.h"
# include "stack.h"
# include <stddef.h>
# include <unistd.h>

typedef struct s_bucket
{
	size_t		size;
	t_dll		*head;
}				t_bucket;

typedef struct s_bucket_sort
{
	size_t		pushing_remaining;
	size_t		pushing_bucket;
	size_t		bucket_ct;
	int			minmax[2];
	t_bucket	*buckets;
	t_find_gap	*fg;
	t_collector	*ctor;
}				t_bucket_sort;

void	set_bucket(t_custom *v, int i, void *data);
void	count_buckets(t_stack *a, t_bucket_sort *bucket_sort);
int		bucket_selective(t_custom *v, int i, void *data);
void	sort_buckets(t_ps *ps);
void	rotator(t_ps *ps, ssize_t idx, char c);
void	push_first_number_of_first_bucket(t_ps *ps);
void	push_last_bucket(t_ps *ps);
void	push_bucket(t_ps *ps);
void	push_b_to_a(t_ps *ps);

#endif
