/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/14 17:57:53 by aunverdi         ###   ########.tr       */
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

int	compute_disorder(t_stack *a, float *disorder)
{
	float	mistakes;
	int		total_pairs;
	t_dll	*bottom;
	t_dll	*i;
	t_dll	*j;

	mistakes = 0;
	total_pairs = 0;
	bottom = a->head->prev;
	i = a->head;
	while (i != bottom)
	{
		j = i->next;
		while (j != bottom->next)
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
