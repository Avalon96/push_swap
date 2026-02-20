/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:05:32 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/20 16:25:02 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

#define CLR_RED "\x1b[31m"
#define CLR_GRN "\x1b[32m"
#define CLR_YEL "\x1b[33m"
#define CLR_BLU "\x1b[34m"
#define CLR_MAG "\x1b[35m"
#define CLR_CYN "\x1b[36m"
#define CLR_RST "\x1b[0m"
#define CLR_BLD "\x1b[1m"
#define CLR_UND "\x1b[4m"
#define CLR_BLK "\x1b[30m"
#define CLR_WHT "\x1b[37m"
#define CLR_BLD "\x1b[1m"
#define CLR_DIM "\x1b[2m"

void	indexer(t_custom *v, int i, void *data);
size_t ft_abs(ssize_t nb);
void	minmax(t_custom *v, int i, void *data);
ssize_t	ft_atol(const char *str);
int	ft_sqrt(int nb);
void err(void);
int safe_sqrt(int nb);
void	print_stacks(t_ps *ps);
void	pre_sort_benchmark(t_ps *ps);
void	post_sort_benchmark(t_ps *ps);

#endif
