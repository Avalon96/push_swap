/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:56 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/20 18:18:45 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_int(int fd, int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += ft_dprint_char(fd, '-');
		n *= -1;
	}
	if (n > 9)
		count += ft_dprint_int(fd, n / 10);
	count += ft_dprint_char(fd, n % 10 + '0');
	return (count);
}

int	ft_dprint_uint(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_dprint_uint(fd, n / 10);
	count += ft_dprint_char(fd, n % 10 + '0');
	return (count);
}
