/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:52:29 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 15:46:29 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "dll.h"

int	atol_err(const char *str, ssize_t *i)
{
	*i = ft_atol(str);
	if ((*i == 0 && str[0] != '0') || *i < -2147483648 || *i > 2147483647)
		return (-1);
	return (0);
}

static int	parse_numbers_helper(int i, int *j, const char *argv[], t_ps *ps)
{
	while (i > *j)
	{
		if (atol_err(argv[*j], &ps->cdll_malloc[*j].value.num) < 0)
			return (-1);
		cdll_link(&ps->cdll_malloc[*j - 1], &ps->cdll_malloc[*j],
			&ps->cdll_malloc[*j + 1]);
		(*j)++;
	}
	return (0);
}

int	parse_numbers(int i, const char *argv[], t_ps *ps)
{
	int	j;

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
	if (parse_numbers_helper(i, &j, argv, ps) < 0)
		return (free(ps->cdll_malloc), -1);
	if (atol_err(argv[j], &ps->cdll_malloc[j].value.num) < 0)
		return (free(ps->cdll_malloc), -1);
	ps->cdll_malloc[j].prev = &ps->cdll_malloc[j - 1];
	ps->cdll_malloc[j].value.this = ps->cdll_malloc + j;
	ps->cdll_malloc[j].next = ps->a.head;
	return (0);
}

t_flags	parse_strategy(const char *arg)
{
	const char	*strategies[4] = {"--simple", "--medium", "--complex",
		"--adaptive"};
	int			i;

	i = -1;
	while (++i < 4)
		if (ft_strncmp(arg, strategies[i], ft_strlen(strategies[i])) == 0)
			return (i);
	return (UNDEFINED);
}

int	parse_args(int argc, const char *argv[], t_ps *ps)
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
