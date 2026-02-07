/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:56 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/07 12:14:58 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
		count += ft_print_int(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

int	ft_print_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_print_uint(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}
