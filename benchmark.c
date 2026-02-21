/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:23:54 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/21 19:09:58 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
// Change dprints
void	pre_sort_benchmark(t_ps *ps)
{
	float	disorder;
	int		decimal;

	disorder = ps->disorder;
	decimal = (int)(disorder * 100) % 100;
	dprintf(2, "[bench] disorder: %d.%d%%\n", (int)disorder, decimal);
	dprintf(2, "[bench] strategy: ");
	if (ps->strategy == STRATEGY_SIMPLE)
		dprintf(2, "Simple / O(n²)");
	else if (ps->strategy == STRATEGY_MEDIUM)
		dprintf(2, "Medium / O(n√n)");
	else if (ps->strategy == STRATEGY_COMPLEX)
		dprintf(2, "Complex / O(n log n)");
	else if (ps->strategy == STRATEGY_ADAPTIVE)
	{
		if (disorder < 20)
			dprintf(2, "Adaptive / O(n²)");
		else if (disorder < 50)
			dprintf(2, "Adaptive / O(n√n)");
		else
			dprintf(2, "Adaptive / O(n log n)");
	}
	else
		dprintf(2, "UNDEFINED");
	dprintf(2, "\n");
}

void	post_sort_benchmark(t_ps *ps)
{
	dprintf(2, "[bench] operations: %u\n", ps->counts[TOTAL]);
	dprintf(2, "[bench] sa: %u\n", ps->counts[SA]);
	dprintf(2, "[bench] sb: %u\n", ps->counts[SB]);
	dprintf(2, "[bench] ss: %u\n", ps->counts[SS]);
	dprintf(2, "[bench] pa: %u\n", ps->counts[PA]);
	dprintf(2, "[bench] pb: %u\n", ps->counts[PB]);
	dprintf(2, "[bench] ra: %u\n", ps->counts[RA]);
	dprintf(2, "[bench] rb: %u\n", ps->counts[RB]);
	dprintf(2, "[bench] rr: %u\n", ps->counts[RR]);
	dprintf(2, "[bench] rra: %u\n", ps->counts[RRA]);
	dprintf(2, "[bench] rrb: %u\n", ps->counts[RRB]);
	dprintf(2, "[bench] rrr: %u\n", ps->counts[RRR]);
}
