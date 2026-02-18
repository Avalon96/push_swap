#include "stack.h"
#include "dll.h"
#include "generics.h"
#include "utils.h"
#include "libft.h"

int	get_relative_index(int index, int size)
{
	const int half_size = size / 2;
	
	if (index < half_size)
		return (index);
	else
		return -(ft_abs(size - index));
}

void	clear_gap_attr(t_custom *v, int i, void *data)
{
	v->this->value.attr &= ~(GAP_B | GAP_A);
}

void	update_gap(t_find_gap *fg, size_t ndiff, size_t odiff, t_dll *cur)
{
	if (ndiff > odiff)
	{
		// printf("new biggest gap: %zu %zu\n", ndiff, odiff);
		fg->duo[0]->value.attr &= ~(GAP_B | GAP_A);
		fg->duo[1]->value.attr &= ~(GAP_B | GAP_A);
		fg->duo[0] = fg->prev;
		fg->duo[1] = cur;
		fg->duo[0]->value.attr |= GAP_A;
		fg->duo[1]->value.attr |= GAP_B;
		fg->prev = cur;
	}
	else
	{
		// printf("no new biggest gap: %zu %zu\n", ndiff, odiff);
		fg->prev = cur;
	}
}

void	check_gap(t_custom *v, int i, void *data)
{
	t_find_gap * const	fg = data;
	t_dll * const		cur = v->this;
	size_t				odiff;
	size_t				ndiff;

	if (!fg->filter(v, i, fg->data))
		return ;
	odiff = ft_abs(fg->duo[0]->value.index - fg->duo[1]->value.index);
	ndiff = ft_abs(fg->prev->value.index - cur->value.index);
	// printf("a: %zu, b: %zu\n", fg->prev->value.index, cur->value.index);
	update_gap(fg, ndiff, odiff, cur);
}

void	check_rgap(t_custom *v, int i, void *data)
{
	t_find_gap * const	fg = data;
	t_dll * const		cur = v->this;
	size_t				odiff;
	size_t				ndiff;

	if (!fg->filter(v, i, fg->data))
		return ;
	odiff = ft_abs(fg->duo[0]->value.index - fg->duo[1]->value.index);
	ndiff = fg->stack->size - ft_abs(fg->prev->value.index - cur->value.index);
	// printf("a: %zu, b: %zu\n", fg->prev->value.index, cur->value.index);
	update_gap(fg, ndiff, odiff, cur);
}

void	get_biggest_gap(t_find_gap *fg)
{
	t_dll * const first = cdll_find(fg->stack->head, fg->filter, fg->data);
	// printf("first: %zu, head: %zu\n", first->value.index, fg->stack->head->value.index);
	fg->prev = first;
	fg->duo[0] = first;
	fg->duo[1] = first;
	first->value.attr |= GAP_A | GAP_B;
	cdll_iter(fg->stack->head, check_gap, fg);
	check_rgap(&first->value, 0, fg);
}

int	get_nearest_node(t_stack *stack, int (*filter)(t_custom *v, int i, void *data), void *data)
{
	t_dll	*forward;
	t_dll	*backward;
	t_dll	*cur;
	size_t	dist;

	forward = NULL;
	backward = NULL;
	cur = stack->head;
	dist = 0;
	while (dist < stack->size)
	{
		if (filter(&cur->value, dist, data))
		{
			forward = cur;
			break ;
		}
		cur = cur->next;
		dist++;
	}
	cur = stack->head->prev;
	dist = 1;
	while (dist < stack->size)
	{
		if (filter(&cur->value, dist, data))
		{
			backward = cur;
			break ;
		}
		cur = cur->prev;
		dist++;
	}
	if (!forward && backward)
		return (get_relative_index(backward->value.index, stack->size));
	if (!backward && forward)
		return (get_relative_index(forward->value.index, stack->size));
	if (ft_abs(get_relative_index(forward->value.index, stack->size)) <= 
		ft_abs(get_relative_index(backward->value.index, stack->size)))
		return (get_relative_index(forward->value.index, stack->size));
	return (get_relative_index(backward->value.index, stack->size));
}


/**
 * does not update index
 */
void	rotator(t_ps *ps, ssize_t idx, char c)
{
	t_stack *stack;

	if (c == 'b')
		stack = &ps->b;
	else if (c == 'a')
		stack = &ps->a;
	if (idx > 0)
	{
		while (idx-- > 0)
		{
			rotate_up(stack);
			ps->ops_count++;
			ft_printf("r%c\n", c);
		}
	}
	else if (idx < 0)
	{
		while (idx++ < 0)
		{
			rotate_down(stack);
			ps->ops_count++;
			ft_printf("rr%c\n", c);
		}
	}
}

// void	go_best(t_stack *stack, size_t a_idx)
// {
// 	const ssize_t r_idx = get_relative_index(a_idx, stack->size);
	
// 	printf("go_best: a_idx = %zu, r_idx = %zd\n", a_idx, r_idx);
// 	rotator(stack, r_idx);
// }

size_t	get_nearest(size_t a, size_t b, t_stack *stack)
{
	const size_t	r_a = get_relative_index(a, stack->size);
	const size_t	r_b = get_relative_index(b, stack->size);
	const size_t	ra_a = ft_abs(r_a);
	const size_t	ra_b = ft_abs(r_b);

	// printf("get_nearest: a = %zu, b = %zu, a_a = %zu, b_a = %zu\n", a, b, ra_a, ra_b);
	if (ra_a < ra_b)
		return (r_a);
	else
		return (r_b);
}
