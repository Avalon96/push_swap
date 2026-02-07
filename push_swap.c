/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/07 17:32:02 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function compute_disorder(stack a):
// 	mistakes = 0
// 	total_pairs = 0
// 	for i from 0 to size(a)-1:
// 		for j from i+1 to size(a)-1:
// 			total_pairs += 1
// 			if a[i] > a[j]:
// 				mistakes += 1
// 	return mistakes / total_pairs

int compute_disorder(t_stack *a, float *disorder)
{
	float mistakes = 0;
	int total_pairs = 0;
	t_lld *i = a->top;
	t_lld *j;

	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			if (i->value == j->value)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	*disorder = (mistakes * 100) / total_pairs;
	return (0);
}
