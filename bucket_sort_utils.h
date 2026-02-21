/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:08:05 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 16:08:06 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCKET_SORT_UTILS_H
# define BUCKET_SORT_UTILS_H

# include "push_swap_defs.h"
# include "stack.h"

typedef struct s_collector
{
	t_ps	*ps;
	t_cmd	shift_cmd;
	size_t	limit;
	void	(*collect_fun)(t_ps *ps);
	void	*data;
}			t_collector;

typedef struct s_find_gap
{
	t_stack	*stack;
	t_dll	*duo[2];
	t_dll	*prev;
	void	*data;
	int		(*filter)(t_custom *v, int i, void *data);
}			t_find_gap;

void	get_biggest_gap(t_find_gap *fg);
int		get_nearest_node(t_stack *stack, int (*filter)(t_custom *v, int i,
				void *data), void *data);
size_t	get_nearest(size_t a, size_t b, t_stack *stack);

#endif
