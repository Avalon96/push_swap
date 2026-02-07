/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:17:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/07 19:08:21 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdlib.h> //del
#include <stdio.h> //del

int	parse_numbers(int argc, const char *argv[], t_ps *ps)
{
	int	i;
	ssize_t num;

	i = argc - 1;
	while (i >= 0)
	{
		num = ft_atol(argv[i]);
		if ((num == 0 && argv[i][0] != '0') || \
			num < -2147483648 || \
			num > 2147483647)
			return (-1);
		ft_lldadd_front(&(ps->a.top), ft_lldnew((int)num));
		i--;
	}
	return (0);
}

t_flags	parse_strategy(const char *arg)
{
	const char	*strategies[4] =
		{"--simple", "--medium", "--complex", "--adaptive"};
	int i;

	i = -1;
	while (++i < 4)
		if (ft_strncmp(arg, strategies[i], ft_strlen(strategies[i])) == 0)
			return (i);
	return (UNDEFINED);
}

int parse_args(int argc, const char *argv[], t_ps *ps)
{
	int	i;

	i = 1;
	if (i >= argc)
		return (-1);
	if (ft_strncmp(argv[i], "--bench", 7) != 0)
		ps->bench = 0;
	else
		ps->bench = i++;
	ps->strategy = parse_strategy(argv[i]);
	if (ps->strategy != UNDEFINED)
		i++;
	else
		ps->strategy = STRATEGY_ADAPTIVE;
	if (parse_numbers(argc - i, argv + i, ps) < 0)
		return (-1);
	return (0);
}

static void p_v(int *a, int i){
	(void)i;
	ft_printf("%d,	", *a);
	// ft_printf("[%d]:%d, ", i++, *a);
}

static void p_i(int *a, int i){
	(void)a;
	ft_printf("[%d]	", i);
}

void print_stack(t_stack *s, char *str, char *str2)
{
	ft_printf("%s	", str);
	ft_llditer(s->top, p_v);
	// ft_printf("\n		");
	ft_printf("\n  %s	", str2);
	ft_llditer(s->top, p_i);
	ft_printf("\n");
}

void print_stacks(t_ps *ps)
{
	print_stack(&ps->a, "Stack", "A");
	print_stack(&ps->b, "Stack", "B");
}

// ./push_swap [[--bench] strategy] numbers...
int main(int argc, char const *argv[])
{
	t_ps * const ps = &(t_ps){0};
	if (parse_args(argc, argv, (t_ps *)ps) < 0)
		return (write(2, MSG_ERROR, sizeof(MSG_ERROR) - 1), -1);
	print_stacks(ps);
	printf("err %d\n", compute_disorder(&ps->a, &(ps->disorder)));
	printf("disorder: %f\n", ps->disorder);
	ft_lldclear(&(ps->a.top));
	(void)argc;
	(void)argv;
	return 0;
}
