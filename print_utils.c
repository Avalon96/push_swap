/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:23:54 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 02:41:37 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h> //del

static void p_v(int *a, int i, void *data){
	(void)i;
	(void)data;
	ft_printf("%d,	", *a);
	// ft_printf("[%d]:%d, ", i++, *a);
}

static void p_i(int *a, int i, void *data){
	(void)a;
	(void)data;
	ft_printf("[%d]	", i);
}

static void p_vi(int *a, int i, void *data){
	(void)data;
	if (i == *(int *)data)
		ft_printf(CLR_WHT CLR_DIM "[%d]:" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, *a);
	else
		ft_printf(CLR_WHT CLR_DIM "[%d]:" CLR_RST CLR_BLD CLR_GRN "%d" CLR_RST ", ", i, *a);
}

static void print_stack(t_stack *s, char *str, int mode)
{
	if (mode == 0)
	{
		ft_printf("%s	", str);
		ft_llditer(s->top, p_v, &(int){0});
		ft_printf("\n	");
		ft_llditer(s->top, p_i, &(int){0});
		ft_printf("\n");
	}
	else if (mode == 1)
	{
		ft_printf(CLR_RST CLR_BLD "%s" CLR_RED"{ ", str);
		ft_llditer(s->top, p_vi, &(int){0});
		ft_printf(CLR_RED CLR_BLD" }\n" CLR_RST);
	}
}

void print_stacks(t_ps *ps)
{
	print_stack(&ps->a, "A = ", 1);
	print_stack(&ps->b, "B = ", 1);
}

void	print_stats(t_ps *ps)
{
	printf("\ndisorder: " CLR_BLD "%f\n" CLR_RST, ps->disorder);
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
