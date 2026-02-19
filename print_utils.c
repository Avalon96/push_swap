/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:23:54 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/19 01:54:18 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h> //del

static void p_v(t_custom *v, int i, void *data){
	(void)i;
	(void)data;
	dprintf(2, "%d,	", v->num);
	// ft_printf("[%d]:%d, ", i++, v->num);
}

static void p_i(t_custom *v, int i, void *data){
	(void)v;
	(void)data;
	dprintf(2, "[%d]	", i);
}

void p_vi_x(t_custom *v, int i, void *data){
	(void)data;
	if (i == *(int *)data)
		dprintf(2, CLR_WHT CLR_DIM "[%d]:" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, v->num);
	else
		dprintf(2, CLR_WHT CLR_DIM "[%d]: bucket<%d>" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, v->bucket_index, v->num);
}

static void p_vi(t_custom *v, int i, void *data){
	(void)i;
	(void)data;
	dprintf(2, CLR_WHT CLR_DIM "[%d]" CLR_RST CLR_YEL"<%d>:" CLR_RST CLR_BLD "%s" "%d" CLR_RST ", ", v->index, v->bucket_index, ((v->attr & GAP_B)? CLR_RED"|B|" : (v->attr & GAP_A)? CLR_MAG"|A|" : CLR_GRN ), v->num);
}

static void	print_stack(t_stack *s, char *str, int mode)
{
	if (mode == 0)
	{
		dprintf(2, "%s	", str);
		cdll_iter(s->head, p_v, &(int){0});
		dprintf(2, "\n	");
		cdll_iter(s->head, p_i, &(int){0});
		dprintf(2, "\n");
	}
	else if (mode == 1)
	{
		if (s->size == 0)
			return ;
		dprintf(2, CLR_RST CLR_BLD "%s" CLR_RED"{ ", str);
		cdll_iter(s->head, p_vi, &(int){0});
		dprintf(2, CLR_RED CLR_BLD" }\n" CLR_RST);
	}
}

void	print_stacks(t_ps *ps)
{
	print_stack(&ps->a, "A = ", 1);
	print_stack(&ps->b, "B = ", 1);
}

void	print_stats(t_ps *ps)
{
	dprintf(2, "\ndisorder: " CLR_BLD "%f\n" CLR_RST, ps->disorder);
	dprintf(2, "operations: %zu\n", ps->ops_count);
	dprintf(2, CLR_RST"strategy: ");
	if (ps->strategy == STRATEGY_SIMPLE)
		dprintf(2, CLR_CYN CLR_BLD"SIMPLE");
	else if (ps->strategy == STRATEGY_MEDIUM)
		dprintf(2, CLR_YEL CLR_BLD"MEDIUM");
	else if (ps->strategy == STRATEGY_COMPLEX)
		dprintf(2, CLR_MAG CLR_BLD"COMPLEX");
	else if (ps->strategy == STRATEGY_ADAPTIVE)
		dprintf(2, CLR_WHT CLR_BLD"ADAPTIVE");
	else
		dprintf(2, "UNDEFINED");
	dprintf(2, CLR_RST "\n\n");
}
