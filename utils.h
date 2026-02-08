/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:05:32 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/09 02:28:40 by ahmbasar         ###   ########.fr       */
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

# define MSG_ERROR "Error\n"

void err(void);
void end(t_ps *ps);

#endif
