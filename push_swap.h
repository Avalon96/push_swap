/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:32:01 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/14 17:32:02 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_dll t_dll;
typedef struct s_dll
{
	int		value;
	t_dll	*next;
	t_dll	*prev;
	int		index;
}				t_dll;

typedef struct s_stack t_stack;
typedef struct s_stack
{
	t_dll	*head;
	int		size;
}				t_stack;

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_cmd;

typedef enum e_flags
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE,
	UNDEFINED
}			t_flags;

typedef struct s_ps
{
	t_stack	a;
	t_stack b;

	t_dll	*cdll_malloc;
	
	int		bench;
	t_flags	strategy;
	int 	err;
	float	disorder;
}				t_ps;

typedef struct s_move
{
	int	a_count;
	int	b_count;
	int	a_dir;
	int	b_dir;
	int	total;
}				t_move;

// Double Linked List Functions
t_dll	*ft_dllnew(int value);
void	ft_dlladd_front(t_dll **lst, t_dll *new);
int		ft_dllsize(t_dll *lst);
void	ft_dllclear(t_dll **lst);
void	ft_dlliter(t_dll *lst, void (*f)(int *v, int i, void *data), void *data);
void	cdll_iter(t_dll *lst, void (*f)(int *v, int i, void *data), void *data);
void	cdll_link(t_dll *a, t_dll *b, t_dll *c);

// Disorder
int 	compute_disorder(t_stack *a, float *disorder);
ssize_t ft_atol(const char *str);

// OPS
void	swap_a(t_ps *ps);
void	swap_b(t_ps *ps);
void	push_a(t_ps *ps);
void	push_b(t_ps *ps);
void	rotate_a(t_ps *ps);
void	rotate_b(t_ps *ps);
void	reverse_rotate_a(t_ps *ps);
void	reverse_rotate_b(t_ps *ps);
void	swap_both(t_ps *ps);
void	rotate_both(t_ps *ps);
void	reverse_rotate_both(t_ps *ps);

// OPS Helpers
void	swap(t_stack *stack);
t_dll	*pop(t_stack *stack);
void	push(t_stack *stack, t_dll *node);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);

// Insertion Sort
void	insertion_sort(t_ps *ps);

// Bucket Sort
// void	bucket_sort(t_ps *ps);

// Radix Sort
void	radix_sort(t_ps *ps);

#endif // PUSH_SWAP_H
