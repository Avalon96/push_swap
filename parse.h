/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:26:39 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:19:00 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "push_swap_defs.h"
# include <unistd.h>

int		atol_err(const char *str, ssize_t *i);
int		parse_numbers(int i, const char *argv[], t_ps *ps);
t_flags	parse_strategy(const char *arg);
int		parse_args(int argc, const char *argv[], t_ps *ps);

#endif
