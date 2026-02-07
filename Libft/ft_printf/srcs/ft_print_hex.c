/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:53 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/07 12:15:04 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(size_t n, const char flag)
{
	char	*hex;
	int		count;

	if (flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_print_hex(n / 16, flag);
	count += ft_print_char(hex[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	size_t	address;
	int		count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (size_t)ptr;
	count = write(1, "0x", 2);
	count += ft_print_hex(address, 'x');
	return (count);
}
