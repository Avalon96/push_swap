/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:07:37 by aunverdi          #+#    #+#             */
/*   Updated: 2026/01/09 12:33:51 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	joint = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		joint[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		joint[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	joint[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (joint);
}
