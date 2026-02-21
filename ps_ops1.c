/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:19 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/20 19:16:51 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

void	rotate_a(t_ps *ps)
{
	rotate_up(&ps->a);
	ps->counts[RA]++;
	ps->counts[TOTAL]++;
	ft_printf("ra\n");
}

void	rotate_b(t_ps *ps)
{
	rotate_up(&ps->b);
	ps->counts[RB]++;
	ps->counts[TOTAL]++;
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_ps *ps)
{
	rotate_down(&ps->a);
	ps->counts[RRA]++;
	ps->counts[TOTAL]++;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_ps *ps)
{
	rotate_down(&ps->b);
	ps->counts[RRB]++;
	ps->counts[TOTAL]++;
	ft_printf("rrb\n");
}
