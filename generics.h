#ifndef GENERICS_H
# define GENERICS_H

# include "stack.h"
# include "push_swap_defs.h"

/**
 * push_swap number collector.
 */
typedef struct	s_collector
{
	t_ps	*ps;
	t_cmd	shift_cmd;
	size_t	limit;
	void	(*collect_fun)(t_ps *ps);
	void	*data;
}	t_collector;

typedef struct	s_find_gap
{
	t_stack	*stack;
	t_dll	*duo[2];
	t_dll	*prev;
	void	*data;
	int		(*filter)(t_custom *v, int i, void *data);
}	t_find_gap;

/**
 * finds biggest gap 
 */
void	get_biggest_gap(t_find_gap *fg);

int	get_nearest_node(t_stack *stack, int (*filter)(t_custom *v, int i, void *data), void *data);

void	go_best(t_stack *stack, size_t a_idx);

size_t	get_nearest(size_t a, size_t b, t_stack *stack);

void	clear_gap_attr(t_custom *v, int i, void *data);

#endif
