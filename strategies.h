/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:21:29 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 16:12:32 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRATEGIES_H
# define STRATEGIES_H
# include "push_swap_defs.h"
# include "stack.h"

int		medium_sort(t_ps *ps);
int		complex_sort(t_ps *ps);
int		adaptive_sort(t_ps *ps);
int		simple_sort(t_ps *ps);
void	pre_sort_benchmark(t_ps *ps);
void	post_sort_benchmark(t_ps *ps);
int		compute_disorder(t_stack *stack, float *disorder);

#endif