/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:30:59 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/14 17:31:00 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTION_SORT_H
# define INSERTION_SORT_H

int		stack_min(t_stack *s);
int		stack_max(t_stack *s);
int		get_min_pos(t_stack *s);
int		get_max_pos(t_stack *s);
int		find_target_in_b(t_stack *b, int val);
int		find_target_in_a(t_stack *a, int val);
void	execute_move(t_ps *ps, t_move m);
void	sort_three_a(t_ps *ps);
int		find_target_in_a(t_stack *a, int val);
int		find_target_in_b(t_stack *b, int val);
void	execute_move(t_ps *ps, t_move m);
void	sort_three_a(t_ps *ps);
void	rotate_a_to_top(t_ps *ps, int pos);

#endif
