/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:17:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/18 04:54:14 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

#include <stdlib.h> //del
#include <stdio.h> //del

int	medium_sort(t_ps *ps);
int complex_sort(t_ps *ps);
int adaptive_sort(t_ps *ps);
int simple_sort(t_ps *ps);

void	print_stacks(t_ps *ps);
void	print_stats(t_ps *ps);

int	atol_err(const char *str, int *i) {
	*i = ft_atol(str);
	if ((*i == 0 && str[0] != '0') || \
		*i < -2147483648 || \
		*i > 2147483647)
		return (-1);
	return (0);
}

int	parse_numbers(int i, const char *argv[], t_ps *ps)
{
	int j;
	
	j = 0;
	ps->cdll_malloc = ft_calloc(i, sizeof(t_dll));
	ps->a.size = i--;
	if (!ps->cdll_malloc)
		return (-1);
	ps->a.head = &ps->cdll_malloc[j];
	ps->a.head->prev = &ps->cdll_malloc[i];
	ps->cdll_malloc[j].value.this = ps->cdll_malloc + j;
	ps->a.head->next = &ps->cdll_malloc[j + 1];
	if (atol_err(argv[j], &ps->cdll_malloc[j].value.num) < 0)
		return (free(ps->cdll_malloc), -1);
	j++;
	while (i > j)
	{
		if (atol_err(argv[j], &ps->cdll_malloc[j].value.num) < 0)
			return (free(ps->cdll_malloc), -1);
		cdll_link(&ps->cdll_malloc[j - 1], &ps->cdll_malloc[j], &ps->cdll_malloc[j + 1]);
		j++;
	}
	if (atol_err(argv[j], &ps->cdll_malloc[j].value.num) < 0)
		return (free(ps->cdll_malloc), -1);
	ps->cdll_malloc[j].prev = &ps->cdll_malloc[j - 1];
	ps->cdll_malloc[j].value.this = ps->cdll_malloc + j;
	ps->cdll_malloc[j].next = ps->a.head;
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
	if (argc <= 1)
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
	if (argc - i <= 1)
		return (-1);
	if (parse_numbers(argc - i, argv + i, ps) < 0)
		return (-1);
	return (0);
}

void end(t_ps *ps)
{
	free(ps->cdll_malloc);
	free(ps->bucket_sort.buckets);
}

void	init_instructions(t_ps *ps)
{
	ps->instruction[SA] = &swap_a;
	ps->instruction[SB] = &swap_b;
	ps->instruction[SS] = &swap_both;
	ps->instruction[PA] = &push_a;
	ps->instruction[PB] = &push_b;
	ps->instruction[RA] = &rotate_a;
	ps->instruction[RB] = &rotate_b;
	ps->instruction[RR] = &rotate_both;
	ps->instruction[RRA] = &reverse_rotate_a;
	ps->instruction[RRB] = &reverse_rotate_b;
	ps->instruction[RRR] = &reverse_rotate_both;
}

// ./push_swap [[--bench] strategy] numbers...
int main(int argc, char const *argv[])
{
	t_ps * const ps = &(t_ps){0};
	if (parse_args(argc, argv, (t_ps *)ps) < 0)
		return (err(), end(ps), -1);
	ps->err = compute_disorder(&ps->a, &(ps->disorder));
	// printf("disorder: " CLR_BLD "%f\n" CLR_RST, ps->disorder);
	if (ps->err)
		return (err(), end(ps), -1);
	init_instructions(ps);
	print_stats(ps);
	fflush(stdout);
	print_stacks(ps);
	// printf("strategy: %d\n", ps->strategy);
	if (ps->strategy == STRATEGY_SIMPLE)
		ps->err = simple_sort(ps);
	else if (ps->strategy == STRATEGY_MEDIUM)
		ps->err = medium_sort(ps);
	else if (ps->strategy == STRATEGY_COMPLEX)
		ps->err = complex_sort(ps);
	else
		ps->err = adaptive_sort(ps);
	if (ps->err)
		return (err(), end(ps), -1);
	ps->err = compute_disorder(&ps->a, &(ps->disorder));
	print_stats(ps);
	fflush(stdout);
	print_stacks(ps);

	end(ps);
	// pop(&ps->a);
	// print_stacks(ps);
	// pop(&ps->a);
	// print_stacks(ps);
	// pop(&ps->a);
	// print_stacks(ps);
	// pop(&ps->a);
	// print_stacks(ps);

	// cdll_clear(&(ps->a.head));
	return 0;
}
