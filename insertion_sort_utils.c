/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:35:21 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/14 17:02:51 by aunverdi         ###   ########.tr       */
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

int	get_min_pos(t_stack *s)
{
	t_dll	*curr;
	int		min_val;
	int		min_pos;
	int		i;

	curr = s->head;
	min_val = curr->value;
	min_pos = 0;
	i = 0;
	while (i < s->size)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *s)
{
	t_dll	*curr;
	int		max_val;
	int		max_pos;
	int		i;

	curr = s->head;
	max_val = curr->value;
	max_pos = 0;
	i = 0;
	while (i < s->size)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}
