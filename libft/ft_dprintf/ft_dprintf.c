/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:52:21 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/20 18:57:56 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_flag(int fd, va_list *args, const char flag)
{
	if (flag == 'c')
		return (ft_dprint_char(fd, va_arg(*args, int)));
	else if (flag == 's')
		return (ft_dprint_str(fd, va_arg(*args, char *)));
	else if (flag == 'p')
		return (ft_dprint_ptr(fd, va_arg(*args, void *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_dprint_int(fd, va_arg(*args, int)));
	else if (flag == 'u')
		return (ft_dprint_uint(fd, va_arg(*args, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return (ft_dprint_hex(fd, va_arg(*args, unsigned int), flag));
	else if (flag == '%')
		return (ft_dprint_char(fd, '%'));
	return (-2);
}

static void	norme_helper(const char *s, t_dprintf *d)
{
	int	flag;

	if (!s[d->i + 1])
		d->count = -1;
	else
	{
		flag = has_flag(d->fd, &d->args, s[++d->i]);
		if (flag == -2)
		{
			d->count += ft_dprint_char(d->fd, '%');
			d->count += ft_dprint_char(d->fd, s[d->i]);
		}
		else
			d->count += flag;
	}
}

int	ft_dprintf(int fd, const char *str, ...)
{
	t_dprintf	dprintf;

	dprintf.fd = fd;
	dprintf.i = -1;
	dprintf.count = 0;
	if (!str)
		return (-1);
	va_start(dprintf.args, str);
	while (str[++dprintf.i] && dprintf.count != -1)
	{
		if (str[dprintf.i] == '%')
			norme_helper(str, &dprintf);
		else
			dprintf.count += ft_dprint_char(fd, str[dprintf.i]);
	}
	va_end(dprintf.args);
	return (dprintf.count);
}
