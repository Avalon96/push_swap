/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:58:41 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/22 11:50:07 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bucket_sort_utils.h"
#include "utils.h"

int	get_relative_index(int index, int size)
{
	const int	half_size = size / 2;

	if (index < half_size)
		return (index);
	else
		return (-(ft_abs(size - index)));
}

void	update_gap(t_find_gap *fg, size_t ndiff, size_t odiff, t_dll *cur)
{
	if (ndiff > odiff)
	{
		fg->duo[0] = fg->prev;
		fg->duo[1] = cur;
		fg->prev = cur;
	}
	else
	{
		fg->prev = cur;
	}
}
