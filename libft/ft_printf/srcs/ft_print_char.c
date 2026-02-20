/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:49 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/20 18:22:41 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}
