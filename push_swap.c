/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/18 08:49:10 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "push_swap_defs.h"
#include "stack.h"

// function compute_disorder(stack a):
// 	mistakes = 0
// 	total_pairs = 0
// 	for i from 0 to size(a)-1:
// 		for j from i+1 to size(a)-1:
// 			total_pairs += 1
// 			if a[i] > a[j]:
// 				mistakes += 1
// 	return mistakes / total_pairs

int compute_disorder(t_stack *stack, float *disorder)
{
	float mistakes = 0;
	int total_pairs = 0;
	t_dll *i = stack->head;
	t_dll *tail = stack->head->prev;
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

void	executer(t_cmd op)
{
	
}
