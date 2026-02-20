/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:24 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/20 19:17:19 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

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

void	push_a_first(t_ps *ps)
{
	t_dll * const popped = pop(&ps->b);

	ps->a.head = popped;
	popped->next = popped;
	popped->prev = popped;
	ps->a.size++;
	ps->counts[PA]++;
	ps->counts[TOTAL]++;
	ft_printf("pa\n");
}

void	push_b_first(t_ps *ps)
{
	t_dll * const popped = pop(&ps->a);

	ps->b.head = popped;
	popped->next = popped;
	popped->prev = popped;
	ps->b.size++;
	ps->counts[PB]++;
	ps->counts[TOTAL]++;
	ft_printf("pb\n");
}

void	push_a_last(t_ps *ps)
{
	push(&ps->a, pop_last(&ps->b));
	ps->counts[PA]++;
	ps->counts[TOTAL]++;
	ft_printf("pa\n");
}

void	push_b_last(t_ps *ps)
{
	push(&ps->b, pop_last(&ps->a));
	ps->counts[PB]++;
	ps->counts[TOTAL]++;
	ft_printf("pb\n");
}
