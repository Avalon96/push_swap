/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:52:21 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/07 12:15:39 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	has_flag(va_list *args, const char flag)
{
	if (flag == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (flag == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (flag == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_print_int(va_arg(*args, int)));
	else if (flag == 'u')
		return (ft_print_uint(va_arg(*args, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), flag));
	else if (flag == '%')
		return (ft_print_char('%'));
	return (-2);
}

static void	norme_helper(const char *str, int *i, va_list *args, int *count)
{
	int	flag;

	if (!str[*i + 1])
		*count = -1;
	else
	{
		flag = has_flag(args, str[++(*i)]);
		if (flag == -2)
			*count += ft_print_char('%') + ft_print_char(str[*i]);
		else
			*count += flag;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++i] && count != -1)
	{
		if (str[i] == '%')
			norme_helper(str, &i, &args, &count);
		else
			count += ft_print_char(str[i]);
	}
	va_end(args);
	return (count);
}
