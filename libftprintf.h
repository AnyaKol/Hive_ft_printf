/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:15:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/20 19:13:54 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

typedef struct	s_flags
{
	bool	number;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	dot;
	bool	is_valid;
	char	type;
	int		width;
}	t_flags;

#endif
