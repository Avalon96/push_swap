/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunverdi <aunverdi@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:06:22 by aunverdi          #+#    #+#             */
/*   Updated: 2026/02/22 12:00:00 by aunverdi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_CONFIG_H
# define DLL_CONFIG_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_dll	t_dll;

typedef struct s_custom
{
	int			num;
	size_t		index;
	size_t		bucket_index;
	t_dll		*this;
}				t_custom;

#endif
