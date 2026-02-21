/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:26:48 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:28:50 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "bucket_sort_utils.h"
#include "libft.h"
#include "stack.h"
#include "utils.h"

void	check_gap(t_custom *v, int i, void *data)
{
	size_t				odiff;
	size_t				ndiff;
	t_find_gap *const	fg = data;
	t_dll *const		cur = v->this;

	if (!fg->filter(v, i, fg->data))
		return ;
	odiff = ft_abs(fg->duo[0]->value.index - fg->duo[1]->value.index);
	ndiff = ft_abs(fg->prev->value.index - cur->value.index);
	update_gap(fg, ndiff, odiff, cur);
}

void	check_rgap(t_custom *v, int i, void *data)
{
	size_t				odiff;
	size_t				ndiff;
	t_find_gap *const	fg = data;
	t_dll *const		cur = v->this;

	if (!fg->filter(v, i, fg->data))
		return ;
	odiff = ft_abs(fg->duo[0]->value.index - fg->duo[1]->value.index);
	ndiff = fg->stack->size - ft_abs(fg->prev->value.index - cur->value.index);
	update_gap(fg, ndiff, odiff, cur);
}

void	get_biggest_gap(t_find_gap *fg)
{
	t_dll *const	first = cdll_find(fg->stack->head, fg->filter, fg->data);

	fg->prev = first;
	fg->duo[0] = first;
	fg->duo[1] = first;
	cdll_iter(fg->stack->head, check_gap, fg);
	check_rgap(&first->value, 0, fg);
}

void	rotator(t_ps *ps, ssize_t idx, char c)
{
	t_stack	*stack;

	if (c == 'b')
		stack = &ps->b;
	else if (c == 'a')
		stack = &ps->a;
	if (idx > 0)
	{
		while (idx-- > 0)
		{
			rotate_up(stack);
			ps->counts[TOTAL]++;
			ft_printf("r%c\n", c);
		}
	}
	else if (idx < 0)
	{
		while (idx++ < 0)
		{
			rotate_down(stack);
			ps->counts[TOTAL]++;
			ft_printf("rr%c\n", c);
		}
	}
}

size_t	get_nearest(size_t a, size_t b, t_stack *stack)
{
	const size_t	r_a = get_relative_index(a, stack->size);
	const size_t	r_b = get_relative_index(b, stack->size);
	const size_t	ra_a = ft_abs(r_a);
	const size_t	ra_b = ft_abs(r_b);

	if (ra_a < ra_b)
		return (r_a);
	else
		return (r_b);
}
