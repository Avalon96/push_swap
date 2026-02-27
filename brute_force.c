/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:27:19 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/25 13:25:01 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"
#include "push_swap.h"

int	brute_force(t_ps *ps)
{
	float	disorder;
	int		remaining_b;

	if (ps->a.size > 5)
		return (0);
	remaining_b = ps->a.size - 3;
	while (ps->a.size > 3)
	{
		rotate_a_to_top(ps, get_min_pos(&ps->a));
		push_b(ps);
	}
	sort_three_a(ps);
	if (remaining_b == 2)
	{
		push_a(ps);
		remaining_b--;
	}
	if (remaining_b == 1)
		push_a_last(ps);
	compute_disorder(&ps->a, &disorder);
	if (disorder != 0)
		rotate_a_to_top(ps, get_min_pos(&ps->a));
	return (1);
}
