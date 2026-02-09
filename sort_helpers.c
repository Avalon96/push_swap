/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:49:14 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/09 14:58:20 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *s)
{
	t_dll	*curr;
	int		min;
	int		i;

	curr = s->head;
	min = curr->value;
	i = 0;
	while (i < s->size)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
		i++;
	}
	return (min);
}

int	stack_max(t_stack *s)
{
	t_dll	*curr;
	int		max;
	int		i;

	curr = s->head;
	max = curr->value;
	i = 0;
	while (i < s->size)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
		i++;
	}
	return (max);
}
