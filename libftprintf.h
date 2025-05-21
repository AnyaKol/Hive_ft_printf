/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:15:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/21 18:15:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef	struct s_flags
{
	bool	number;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	dot;
	bool	is_valid;
	char	type;
	size_t	width;
}	t_flags;

int		ft_printf(const char *format, ...);
bool	format_is_valid(const char *format, int *format_i);
void	fill_flags(t_flags *flags, const char *format);
void	check_flags(t_flags *flags);
char	*print_char(int c);

#endif
