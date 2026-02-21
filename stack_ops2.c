/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:02:28 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 17:02:57 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	rotate_down(t_stack *stack)
{
	stack->head = stack->head->prev;
}
