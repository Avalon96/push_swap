/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:53 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/20 17:59:34 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_hex(int fd, size_t n, const char flag)
{
	char	*hex;
	int		count;

	if (flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_dprint_hex(fd, n / 16, flag);
	count += ft_dprint_char(fd, hex[n % 16]);
	return (count);
}

int	ft_dprint_ptr(int fd, void *ptr)
{
	size_t	address;
	int		count;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	address = (size_t)ptr;
	count = write(fd, "0x", 2);
	count += ft_dprint_hex(fd, address, 'x');
	return (count);
}
