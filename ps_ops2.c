/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:24 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/22 12:04:11 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_a(t_ps *ps)
{
	swap(&ps->a);
	ps->counts[SA]++;
	ps->counts[TOTAL]++;
	ft_printf("sa\n");
}

void	swap_b(t_ps *ps)
{
	swap(&ps->b);
	ps->counts[SB]++;
	ps->counts[TOTAL]++;
	ft_printf("sb\n");
}

void	swap_both(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	ps->counts[SS]++;
	ps->counts[TOTAL]++;
	ft_printf("ss\n");
}

void	push_a(t_ps *ps)
{
	push(&ps->a, pop(&ps->b));
	ps->counts[PA]++;
	ps->counts[TOTAL]++;
	ft_printf("pa\n");
}

void	push_b(t_ps *ps)
{
	push(&ps->b, pop(&ps->a));
	ps->counts[PB]++;
	ps->counts[TOTAL]++;
	ft_printf("pb\n");
}
