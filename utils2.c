/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:59:17 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 16:59:29 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write(2, MSG_ERROR, sizeof(MSG_ERROR) - 1);
}

void	indexer(t_custom *v, int i, void *data)
{
	(void)data;
	v->index = i;
}
