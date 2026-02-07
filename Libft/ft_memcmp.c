/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:31 by aunverdi          #+#    #+#             */
/*   Updated: 2026/01/05 12:06:52 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;
	size_t				i;

	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return ((unsigned char)tmp_s1[i] - (unsigned char)tmp_s2[i]);
		i++;
	}
	return (0);
}
