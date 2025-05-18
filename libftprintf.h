/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:15:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/18 21:15:48 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

typedef struct	s_format
{
	bool	number;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	dot;
	bool	is_valid;
}	t_format;

#endif
