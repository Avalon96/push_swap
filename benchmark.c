/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:23:54 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/22 11:48:54 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	print_positive_int(int n)
{
	if (n > 9)
		print_positive_int(n / 10);
	ft_putchar_fd(n % 10 + '0', 2);
}

static void	print_bench(const char *str, int d, int n)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == 'u')
		{
			if (d >= 0)
			{
				print_positive_int(d);
				ft_putchar_fd('.', 2);
				print_positive_int(n);
				ft_putchar_fd('%', 2);
			}
			else
				print_positive_int(n);
			i++;
		}
		else
			ft_putchar_fd(str[i], 2);
	}
}

void	pre_sort_benchmark(t_ps *ps)
{
	float	disorder;
	int		decimal;

	disorder = ps->disorder;
	decimal = (int)(disorder * 100) % 100;
	print_bench("[bench] disorder: %u\n", (int)disorder, decimal);
	print_bench("[bench] strategy: ", -1, 0);
	if (ps->strategy == STRATEGY_SIMPLE)
		print_bench("Simple / O(n²)", -1, 0);
	else if (ps->strategy == STRATEGY_MEDIUM)
		print_bench("Medium / O(n√n)", -1, 0);
	else if (ps->strategy == STRATEGY_COMPLEX)
		print_bench("Complex / O(n log n)", -1, 0);
	else if (ps->strategy == STRATEGY_ADAPTIVE)
	{
		if (disorder < 20)
			print_bench("Adaptive / O(n²)", -1, 0);
		else if (disorder < 50)
			print_bench("Adaptive / O(n√n)", -1, 0);
		else
			print_bench("Adaptive / O(n log n)", -1, 0);
	}
	else
		print_bench("UNDEFINED", -1, 0);
	print_bench("\n", -1, 0);
}

void	post_sort_benchmark(t_ps *ps)
{
	print_bench("[bench] operations: %u\n", -1, ps->counts[TOTAL]);
	print_bench("[bench] sa: %u\n", -1, ps->counts[SA]);
	print_bench("[bench] sb: %u\n", -1, ps->counts[SB]);
	print_bench("[bench] ss: %u\n", -1, ps->counts[SS]);
	print_bench("[bench] pa: %u\n", -1, ps->counts[PA]);
	print_bench("[bench] pb: %u\n", -1, ps->counts[PB]);
	print_bench("[bench] ra: %u\n", -1, ps->counts[RA]);
	print_bench("[bench] rb: %u\n", -1, ps->counts[RB]);
	print_bench("[bench] rr: %u\n", -1, ps->counts[RR]);
	print_bench("[bench] rra: %u\n", -1, ps->counts[RRA]);
	print_bench("[bench] rrb: %u\n", -1, ps->counts[RRB]);
	print_bench("[bench] rrr: %u\n", -1, ps->counts[RRR]);
}
