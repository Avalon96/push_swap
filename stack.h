/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:51:11 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 18:18:57 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "dll.h"

typedef struct s_stack	t_stack;
typedef struct s_stack
{
	t_dll		*head;
	int			size;
}				t_stack;

#endif
