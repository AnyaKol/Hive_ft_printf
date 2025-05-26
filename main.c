/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:34:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/26 17:34:30 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	int			result;
	int			ft_result = 0;
	const int	*ptr = &result;
	const char	*null_ptr = NULL;

	printf("\n----Test: char----\n");
	result = printf("%4c%%%-3c\\%c\n", 'A', 'b', '1');
	ft_result = ft_printf("%4c%%%-3c\\%c\n", 'A', 'b', '1');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: string----\n");
	result = printf("|%4s%-8s%8.5s%-10s|%-1c", "Hello World!", "Hi", "Hello World!", null_ptr, '\n');
	ft_result = ft_printf("|%4s%-8s%8.5s%-10s|%-1c", "Hello World!", "Hi", "Hello World!", null_ptr, '\n');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: int----\n");
	result = printf("|%05i %%%-5d %03i %0 4d % 04d %+04i %07.3d %-5.3i|\n", -123, 22, 11, 444, -444, 42, 12, -1);
	ft_result = ft_printf("|%05i %%%-5d %03i %0 4d % 04d %+04i %07.3d %-5.3i|\n", -123, 22, 11, 444, -444, 42, 12, -1);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: hex----\n");
	result = printf("|%05X %-5x %#3X%%|\n", -123, 44, 11);
	ft_result = ft_printf("|%05X %-5x %#3X%%|\n", -123, 44, 11);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: pointer----\n");
	result = printf("|%17p %-6p|\n", ptr, NULL);
	ft_result = ft_printf("|%17p %-6p|\n", ptr, NULL);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	return (0);
}
