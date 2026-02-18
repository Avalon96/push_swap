/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:19 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/16 11:29:07 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

void	rotate_a(t_ps *ps)
{
	rotate_up(&ps->a);
	ps->ops_count++;
	ft_printf("ra\n");
}

void	rotate_b(t_ps *ps)
{
	rotate_up(&ps->b);
	ps->ops_count++;
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_ps *ps)
{
	rotate_down(&ps->a);
	ps->ops_count++;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_ps *ps)
{
	rotate_down(&ps->b);
	ps->ops_count++;
	ft_printf("rrb\n");
}
