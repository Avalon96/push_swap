/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:19 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/10 13:42:39 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

void	rotate_a(t_ps *ps)
{
	// rotate_up(&ps->a);
	rotate_down(&ps->a);
	ft_printf("ra\n");
}

void	rotate_b(t_ps *ps)
{
	// rotate_up(&ps->b);
	rotate_down(&ps->b);
	ft_printf("rb\n");
}

void	rotate_both(t_ps *ps)
{
	ps->a.head = ps->a.head->next;
	ps->b.head = ps->b.head->next;
	ft_printf("rr\n");
}

void	reverse_rotate_a(t_ps *ps)
{
	// rotate_down(&ps->a);
	rotate_up(&ps->a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_ps *ps)
{
	// rotate_down(&ps->b);
	rotate_up(&ps->b);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_ps *ps)
{
	ps->a.head = ps->a.head->prev;
	ps->b.head = ps->b.head->prev;
	ft_printf("rrr\n");
}
