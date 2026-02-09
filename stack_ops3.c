/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:24 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 15:52:02 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

void	swap_a(t_ps *ps)
{
	swap(&ps->a);
	ft_printf("sa\n");
}

void	swap_b(t_ps *ps)
{
	swap(&ps->b);
	ft_printf("sb\n");
}

void	swap_both(t_ps *ps)
{
	swap_a(ps);
	swap_b(ps);
	ft_printf("ss\n");
}

void	push_a(t_ps *ps)
{
	push(&ps->a, pop(&ps->b));
	ft_printf("pa\n");
}

void	push_b(t_ps *ps)
{
	push(&ps->b, pop(&ps->a));
	ft_printf("pb\n");
}
