/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:23:54 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/16 11:19:46 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h> //del

static void p_v(t_custom *v, int i, void *data){
	(void)i;
	(void)data;
	ft_printf("%d,	", v->num);
	// ft_printf("[%d]:%d, ", i++, v->num);
}

static void p_i(t_custom *v, int i, void *data){
	(void)v;
	(void)data;
	ft_printf("[%d]	", i);
}

static void p_vi_x(t_custom *v, int i, void *data){
	(void)data;
	if (i == *(int *)data)
		ft_printf(CLR_WHT CLR_DIM "[%d]:" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, v->num);
	else
		ft_printf(CLR_WHT CLR_DIM "[%d]: bucket<%d>" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, v->bucket_index, v->num);
}

static void p_vi(t_custom *v, int i, void *data){
	ft_printf(CLR_WHT CLR_DIM "[%d]" CLR_RST CLR_YEL"<%d>:" CLR_RST CLR_BLD "%s" "%d" CLR_RST ", ", v->index, v->bucket_index, ((v->attr & GAP_B)? CLR_RED"|B|" : (v->attr & GAP_A)? CLR_MAG"|A|" : CLR_GRN ), v->num);
}

static void	print_stack(t_stack *s, char *str, int mode)
{
	if (mode == 0)
	{
		ft_printf("%s	", str);
		cdll_iter(s->head, p_v, &(int){0});
		ft_printf("\n	");
		cdll_iter(s->head, p_i, &(int){0});
		ft_printf("\n");
	}
	else if (mode == 1)
	{
		if (s->size == 0)
			return ;
		ft_printf(CLR_RST CLR_BLD "%s" CLR_RED"{ ", str);
		cdll_iter(s->head, p_vi, &(int){0});
		ft_printf(CLR_RED CLR_BLD" }\n" CLR_RST);
	}
}

void	print_stacks(t_ps *ps)
{
	print_stack(&ps->a, "A = ", 1);
	print_stack(&ps->b, "B = ", 1);
}

void	print_stats(t_ps *ps)
{
	printf("\ndisorder: " CLR_BLD "%f\n" CLR_RST, ps->disorder);
	printf("operations: %zu\n", ps->ops_count);
	ft_printf(CLR_RST"strategy: ");
	if (ps->strategy == STRATEGY_SIMPLE)
		ft_printf(CLR_CYN CLR_BLD"SIMPLE");
	else if (ps->strategy == STRATEGY_MEDIUM)
		ft_printf(CLR_YEL CLR_BLD"MEDIUM");
	else if (ps->strategy == STRATEGY_COMPLEX)
		ft_printf(CLR_MAG CLR_BLD"COMPLEX");
	else if (ps->strategy == STRATEGY_ADAPTIVE)
		ft_printf(CLR_WHT CLR_BLD"ADAPTIVE");
	else
		ft_printf("UNDEFINED");
	ft_printf(CLR_RST "\n\n");
}
