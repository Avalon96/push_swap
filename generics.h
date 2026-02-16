#ifndef GENERICS_H
# define GENERICS_H

# include "stack.h"

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

void	go_best(t_stack *stack, size_t a_idx);

size_t	get_nearest(size_t a, size_t b, t_stack *stack);

void	clear_gap_attr(t_custom *v, int i, void *data);

#endif
