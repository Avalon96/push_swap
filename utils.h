/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:05:32 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/21 16:27:42 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

void	indexer(t_custom *v, int i, void *data);
size_t	ft_abs(ssize_t nb);
void	minmax(t_custom *v, int i, void *data);
ssize_t	ft_atol(const char *str);
int		ft_sqrt(int nb);
int		safe_sqrt(int nb);
void	err(void);

#endif
