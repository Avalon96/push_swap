/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:30:49 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/20 18:01:14 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprint_char(int fd, int c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_dprint_str(int fd, char *s)
{
	int	count;

	if (!s)
		return (write(fd, "(null)", 6));
	count = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (count);
}
