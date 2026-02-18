/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:43:56 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/16 15:24:01 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "insertion_sort.h"

int	find_target_in_a(t_stack *a, int val)
{
	t_dll	*curr;
	int		i;

	if (val < stack_min(a) || val > stack_max(a))
		return (get_min_pos(a));
	curr = a->head;
	i = 0;
	while (i < a->size)
	{
		if (curr->value.num > val && curr->prev->value.num < val)
			return (i);
		curr = curr->next;
		i++;
	}
	return (0);
}

int	find_target_in_b(t_stack *b, int val)
{
	t_dll	*curr;
	int		i;

	if (val < stack_min(b) || val > stack_max(b))
		return (get_max_pos(b));
	curr = b->head;
	i = 0;
	while (i < b->size)
	{
		if (curr->value.num > val && curr->next->value.num < val)
			return (i + 1);
		curr = curr->next;
		i++;
	}
	return (0);
}

void	execute_move(t_ps *ps, t_move m)
{
	while (m.a_dir == m.b_dir && m.a_count > 0 && m.b_count > 0)
	{
		if (m.a_dir == 1)
			rotate_both(ps);
		else
			reverse_rotate_both(ps);
		m.a_count--;
		m.b_count--;
	}
	while (m.a_count-- > 0)
	{
		if (m.a_dir == 1)
			rotate_a(ps);
		else
			reverse_rotate_a(ps);
	}
	while (m.b_count-- > 0)
	{
		if (m.b_dir == 1)
			rotate_b(ps);
		else
			reverse_rotate_b(ps);
	}
	push_b(ps);
}

void	sort_three_a(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a.head->value.num;
	second = ps->a.head->next->value.num;
	third = ps->a.head->prev->value.num;
	if (first > second && second < third && first < third)
		swap_a(ps);
	else if (first > second && second > third)
	{
		swap_a(ps);
		reverse_rotate_a(ps);
	}
	else if (first > second && second < third && first > third)
		rotate_a(ps);
	else if (first < second && second > third && first < third)
	{
		swap_a(ps);
		rotate_a(ps);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(ps);
}

void	rotate_a_to_top(t_ps *ps, int pos)
{
	int	size;

	size = ps->a.size;
	if (pos <= size / 2)
		while (pos--)
			rotate_a(ps);
	else
	{
		pos = size - pos;
		while (pos--)
			reverse_rotate_a(ps);
	}
}
