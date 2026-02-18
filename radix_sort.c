/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:02:01 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/16 11:43:04 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_stack(t_stack *stack)
{
	t_dll	*curr;
	t_dll	*compare;
	int		index;
	int		i;
	int		j;

	curr = stack->head;
	i = 0;
	while (i < stack->size)
	{
		index = 0;
		compare = stack->head;
		j = 0;
		while (j < stack->size)
		{
			if (curr->value.num > compare->value.num)
				index++;
			compare = compare->next;
			j++;
		}
		curr->value.index = index;
		curr = curr->next;
		i++;
	}
}

static int	get_max_bits(t_stack *stack)
{
	int	max_idx;
	int	max_bits;

	max_idx = stack->size - 1;
	max_bits = 0;
	while ((max_idx >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_ps *ps)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_stack(&ps->a);
	size = ps->a.size;
	max_bits = get_max_bits(&ps->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((ps->a.head->value.index >> i) & 1) == 0)
				push_b(ps);
			else
				rotate_a(ps);
			j++;
		}
		while (ps->b.size > 0)
			push_a(ps);
		i++;
	}
}
