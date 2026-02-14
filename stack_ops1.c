/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:38:07 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/14 17:40:39 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_dll	* const first = stack->head;
	t_dll	* const second = first->next;

	second->next->prev = first;
	second->prev = first->prev;
	first->next = second->next;
	first->prev->next = second;

	first->prev = second;
	second->next = first;

	stack->head = second;
}

t_dll	*pop_last(t_stack *stack)
{
	t_dll * const popped = stack->head;

	stack->head = NULL;
	stack->size = 0;
	return popped;
}


t_dll	*pop(t_stack *stack)
{
	t_dll	* const top = stack->head;

	stack->head->next->prev = stack->head->prev;
	stack->head->prev->next = stack->head->next;
	stack->head = stack->head->next;
	stack->size--;
	return (top);
}

void	push(t_stack *stack, t_dll *node)
{
	node->next = stack->head;
	node->prev = stack->head->prev;
	stack->head->prev->next = node;
	stack->head->prev = node;
	stack->head = node;
	stack->size++;
}

void	rotate_down(t_stack *stack)
{
	stack->head = stack->head->prev;
}

void	rotate_up(t_stack *stack)
{
	stack->head = stack->head->next;
}

