/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:17:33 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 14:07:01 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

#include <stdlib.h> //del
// #include <stdio.h> //del

void print_stacks(t_ps *ps);
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
	ps->cdll_malloc = malloc(sizeof(t_dll) * i);
	ps->a.size = i--;
	if (!ps->cdll_malloc)
		return (-1);
	ps->a.head = &ps->cdll_malloc[j];
	ps->a.head->prev = &ps->cdll_malloc[i];
	ps->a.head->next = &ps->cdll_malloc[j + 1];
	if (atol_err(argv[j], &ps->cdll_malloc[j].value) < 0)
		return (-1);
	j++;
	while (i > j)
	{
		if (atol_err(argv[j], &ps->cdll_malloc[j].value) < 0)
			return (-1);
		cdll_link(&ps->cdll_malloc[j - 1], &ps->cdll_malloc[j], &ps->cdll_malloc[j + 1]);
		j++;
	}
	if (atol_err(argv[j], &ps->cdll_malloc[j].value) < 0)
		return (-1);
	ps->cdll_malloc[j].prev = &ps->cdll_malloc[j - 1];
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


// ./push_swap [[--bench] strategy] numbers...
int main(int argc, char const *argv[])
{
	t_ps * const ps = &(t_ps){0};
	if (parse_args(argc, argv, (t_ps *)ps) < 0)
		return (err(), end(ps), -1);
	// ps->err = compute_disorder(&ps->a, &(ps->disorder));
	if (ps->err)
		return (err(), end(ps), -1);
	// print_stats(ps);
	print_stacks(ps);
	pop(&ps->a);
	print_stacks(ps);
	pop(&ps->a);
	print_stacks(ps);
	pop(&ps->a);
	print_stacks(ps);
	pop(&ps->a);
	print_stacks(ps);

	// cdll_clear(&(ps->a.head));
	(void)argc;
	(void)argv;
	return 0;
}
