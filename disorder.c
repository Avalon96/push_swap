/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/21 16:19:23 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_defs.h"
#include "stack.h"

int	compute_disorder(t_stack *stack, float *disorder)
{
	float	mistakes;
	int		total_pairs;
	t_dll	*i;
	t_dll	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack->head;
	while (i != stack->head->prev)
	{
		j = i->next;
		while (j != stack->head)
		{
			total_pairs++;
			if (i->value.num > j->value.num)
				mistakes++;
			if (i->value.num == j->value.num)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	*disorder = (mistakes * 100) / total_pairs;
	return (0);
}
