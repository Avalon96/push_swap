/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:49:16 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 10:42:56 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "push_swap.h"

ssize_t	ft_atol(const char *str)
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
		str++;
	}
	return (result * sign);
}

void end(t_ps *ps)
{
	// ft_lldclear(&(ps->a.top));
	// ft_lldclear(&(ps->b.top));
}

void err(void)
{
	write(2, MSG_ERROR, sizeof(MSG_ERROR) - 1);
}
