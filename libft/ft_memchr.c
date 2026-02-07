/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:27 by aunverdi          #+#    #+#             */
/*   Updated: 2026/01/05 12:04:03 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s;
	unsigned char		tmp_c;

	tmp_s = (const unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (n--)
	{
		if (*tmp_s == tmp_c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
