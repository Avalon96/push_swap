/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:43:48 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 17:03:57 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push_a_first(t_ps *ps)
{
	t_dll *const	popped = pop(&ps->b);

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
	t_dll *const	popped = pop(&ps->a);

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
