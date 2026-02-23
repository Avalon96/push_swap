/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:49:16 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/23 13:40:44 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

ssize_t	ft_atol(const char *str, char **endptr)
{
	ssize_t	result;
	ssize_t	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483647 && sign == 1)
			return (result);
		if (result > 2147483648 && sign == -1)
			return (result);
		str++;
	}
	if (*str != '\0')
		return (*endptr = (char *)str, result * sign);
	return (*endptr = NULL, result * sign);
}

int	ft_sqrt(int nb)
{
	int	test;

	test = 2;
	while (test <= (nb / test))
	{
		if ((test * test) == nb)
			return (test);
		test++;
	}
	return (--test);
}

int	safe_sqrt(int nb)
{
	if (nb < 3)
		return (1);
	return (ft_sqrt(nb));
}

size_t	ft_abs(ssize_t nb)
{
	if (nb < 0)
		return ((size_t)(-nb));
	return ((size_t)nb);
}

void	minmax(t_custom *v, int i, void *data)
{
	int	(*minmax)[2];

	(void)i;
	minmax = data;
	if (v->num < (*minmax)[0])
		(*minmax)[0] = v->num;
	if (v->num > (*minmax)[1])
		(*minmax)[1] = v->num;
}
