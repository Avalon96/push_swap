/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:24 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 13:23:22 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
