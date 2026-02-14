/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/13 14:20:19 by ahmbasar         ###   ########.fr       */
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
	t_dll *i = a->head;
	t_dll *tail = a->head->prev;
	t_dll *j;

	while (i != tail)
	{
		j = i->next;
		while (j != tail->next)
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
