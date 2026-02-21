/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:32:01 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:23:21 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "bucket_sort.h"
# include "dll.h"
# include "push_swap_defs.h"
# include "stack.h"
# include <unistd.h>

# define MSG_ERROR "Error\n"

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	t_dll			*cdll_malloc;
	t_bucket_sort	bucket_sort;
	int				bench;
	t_flags			strategy;
	int				err;
	float			disorder;
	unsigned int	counts[12];
	void			(*instruction[11])(t_ps *ps);
}				t_ps;

typedef struct s_move
{
	int	a_count;
	int	b_count;
	int	a_dir;
	int	b_dir;
	int	total;
}				t_move;

void	swap(t_stack *stack);
t_dll	*pop(t_stack *stack);
t_dll	*pop_last(t_stack *stack);
void	push(t_stack *stack, t_dll *node);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);

void	swap_a(t_ps *ps);
void	swap_b(t_ps *ps);
void	swap_both(t_ps *ps);
void	push_a(t_ps *ps);
void	push_b(t_ps *ps);
void	push_a_first(t_ps *ps);
void	push_b_first(t_ps *ps);
void	push_a_last(t_ps *ps);
void	push_b_last(t_ps *ps);
void	rotate_a(t_ps *ps);
void	rotate_b(t_ps *ps);
void	rotate_both(t_ps *ps);
void	reverse_rotate_a(t_ps *ps);
void	reverse_rotate_b(t_ps *ps);
void	reverse_rotate_both(t_ps *ps);

int		compute_disorder(t_stack *a, float *disorder);
void	insertion_sort(t_ps *ps);
void	radix_sort(t_ps *ps);
int		complex_sort(t_ps *ps);
int		adaptive_sort(t_ps *ps);
int		simple_sort(t_ps *ps);
int		medium_sort(t_ps *ps);

#endif
