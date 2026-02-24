/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:17:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/23 19:24:39 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "parse.h"
#include "utils.h"

int		medium_sort(t_ps *ps);
int		complex_sort(t_ps *ps);
int		adaptive_sort(t_ps *ps);
int		simple_sort(t_ps *ps);
void	pre_sort_benchmark(t_ps *ps);
void	post_sort_benchmark(t_ps *ps);

void	end(t_ps *ps)
{
	free(ps->cdll_malloc);
	free(ps->bucket_sort.buckets);
}

void	init_instructions(t_ps *ps)
{
	ps->instruction[SA] = &swap_a;
	ps->instruction[SB] = &swap_b;
	ps->instruction[SS] = &swap_both;
	ps->instruction[PA] = &push_a;
	ps->instruction[PB] = &push_b;
	ps->instruction[RA] = &rotate_a;
	ps->instruction[RB] = &rotate_b;
	ps->instruction[RR] = &rotate_both;
	ps->instruction[RRA] = &reverse_rotate_a;
	ps->instruction[RRB] = &reverse_rotate_b;
	ps->instruction[RRR] = &reverse_rotate_both;
}

void	strategy(t_ps *ps)
{
	if (ps->strategy == STRATEGY_SIMPLE)
		ps->err = simple_sort(ps);
	else if (ps->strategy == STRATEGY_MEDIUM)
		ps->err = medium_sort(ps);
	else if (ps->strategy == STRATEGY_COMPLEX)
		ps->err = complex_sort(ps);
	else
		ps->err = adaptive_sort(ps);
}

// ./push_swap [[--bench] strategy] numbers...
int	main(int argc, char const *argv[])
{
	t_ps *const	ps = &(t_ps){0};

	ps->err = parse_args(argc, argv, (t_ps *)ps);
	if (ps->err < 0)
		return (err(), -1);
	else if (ps->err > 0)
		return (1);
	ps->err = compute_disorder(&ps->a, &(ps->disorder));
	if (ps->err)
		return (err(), end(ps), -1);
	if (ps->bench)
		pre_sort_benchmark(ps);
	init_instructions(ps);
	cdll_iter(ps->a.head, indexer, NULL);
	strategy(ps);
	if (ps->err)
		return (err(), end(ps), -1);
	if (ps->bench)
		post_sort_benchmark(ps);
	end(ps);
	return (0);
}
