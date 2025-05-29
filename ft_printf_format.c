/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:14:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 20:25:08 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_minus(char *str, int spaces_end, int len)
{
	int	i;

	ft_memmove(str, &str[spaces_end], len);
	i = len;
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char	*format_zero(char *str, bool space)
{
	int	i;

	i = 0;
	if (ft_strchr(str, '-') != NULL || ft_strchr(str, '+') != NULL || space)
	{
		if (ft_strchr(str, '-') != NULL)
			str[0] = '-';
		else if (ft_strchr(str, '+') != NULL)
			str[0] = '+';
		i = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			str[i] = '0';
		i++;
	}
	return (str);
}

char	*format_number(char *str, char type)
{
	char	*new_str;

	if (type == 'X')
		new_str = ft_strjoin("0X", str);
	else
		new_str = ft_strjoin("0x", str);
	free(str);
	str = NULL;
	return (new_str);
}

char	*format_space_plus(char *str, int *len, bool plus)
{
	char	*new_str;

	if (str[0] == '-')
		return (str);
	(*len)++;
	new_str = ft_calloc(*len + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	new_str[0] = ' ';
	if (plus)
		new_str[0] = '+';
	ft_strlcpy(&new_str[1], (const char *) str, *len + 1);
	free(str);
	str = NULL;
	return (new_str);
}

char	*format_precision(char *str, int precision, char type, int *len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (type == 's' || (type != 's' && precision == 0))
	{
		if (precision >= *len)
			return (str);
		new_str = ft_calloc(precision + 1, sizeof(char));
		ft_strlcpy(new_str, (const char *) str, precision + 1);
	}
	else
	{
		if (precision < *len || (precision == *len && str[0] != '-'))
			return (str);
		if (str[0] == '-')
			i = 1;
		new_str = ft_calloc(precision + i + 1, sizeof(char));
		new_str = ft_memset((void *) new_str, '0', precision + i);
		if (str[0] == '-')
			new_str[0] = '-';
		ft_strlcpy(&new_str[i + precision - (*len - i)], &str[i], *len - i + 1);
	}
	*len = precision + i;
	free(str);
	str = NULL;
	return (new_str);
}
