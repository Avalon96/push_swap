/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmbasar <ahmbasar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:41:18 by ahmbasar          #+#    #+#             */
/*   Updated: 2026/02/07 17:41:19 by ahmbasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

t_lld	*ft_lldnew(int value)
{
	t_lld *const	l = malloc(sizeof(t_lld));

	if (!l)
		return (NULL);
	l->value = value;
	l->next = NULL;
	l->prev = NULL;
	return (l);
}

void	ft_lldadd_front(t_lld **lst, t_lld *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = new;
	*lst = new;
}

int	ft_lldsize(t_lld *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lldclear(t_lld **lst)
{
	t_lld	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_llditer(t_lld *lst, void (*f)(int *v, int i))
{
	int i;
	
	i = 0;
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(&lst->value, i++);
		lst = lst->next;
	}
}
