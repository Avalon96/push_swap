/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:32:12 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:19:19 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_defs.h"
#include "libft.h"

void	rotate_both(t_ps *ps)
{
	ps->a.head = ps->a.head->next;
	ps->b.head = ps->b.head->next;
	ps->counts[RR]++;
	ps->counts[TOTAL]++;
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_ps *ps)
{
	ps->a.head = ps->a.head->prev;
	ps->b.head = ps->b.head->prev;
	ps->counts[RRR]++;
	ps->counts[TOTAL]++;
	ft_printf("rrr\n");
}
