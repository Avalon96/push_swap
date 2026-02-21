/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:07:13 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/21 15:09:09 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include "dll_config.h"

typedef struct s_dll	t_dll;
typedef struct s_dll
{
	t_dll		*prev;
	t_custom	value;
	t_dll		*next;
}				t_dll;

void	cdll_iter(t_dll *lst, void (*f)(t_custom *v, int i,
				void *data), void *data);
t_dll	*cdll_find(t_dll *lst, int (*f)(t_custom *v, int i,
				void *data), void *data);
int		cdll_some(t_dll *lst, int (*f)(t_custom *v, int i,
				void *data), void *data);
int		cdll_every(t_dll *lst, int (*f)(t_custom *v, int i,
				void *data), void *data);
void	cdll_link(t_dll *a, t_dll *b, t_dll *c);

#endif // DLL_H
