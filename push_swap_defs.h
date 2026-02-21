/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:36:18 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:18:44 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEFS_H
# define PUSH_SWAP_DEFS_H

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TOTAL
}				t_cmd;

typedef enum e_flags
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE,
	UNDEFINED
}			t_flags;

typedef struct s_ps	t_ps;

#endif
