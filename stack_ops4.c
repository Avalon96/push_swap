/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:43:48 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/16 11:46:32 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_both(t_ps *ps)
{
	// rotate_up(&ps->a);
	// rotate_up(&ps->b);
	ps->a.head = ps->a.head->next;
	ps->b.head = ps->b.head->next;
	ps->ops_count++;
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_ps *ps)
{
	// rotate_down(&ps->a);
	// rotate_down(&ps->a);
	ps->a.head = ps->a.head->prev;
	ps->b.head = ps->b.head->prev;
	ps->ops_count++;
	ft_printf("rrr\n");
}
