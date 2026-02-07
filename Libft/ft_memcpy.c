/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:33 by aunverdi          #+#    #+#             */
/*   Updated: 2026/01/29 14:23:53 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dst = (unsigned char *)dest;
	tmp_src = (const unsigned char *)src;
	while (n--)
		*tmp_dst++ = *tmp_src++;
	return (dest);
}
