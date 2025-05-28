/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:34:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 17:55:16 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int			result;
	int			ft_result = 0;
	const int	*ptr = &result;
	const char	*null_ptr = NULL;

	printf("\n----Test: char----\n");
	result = printf(" %c %c %c ",'0', 0, '1');
	printf("\n");
	ft_result = ft_printf(" %c %c %c ",'0', 0, '1');
	printf("\n");
//	result = printf("|%4c%%%-3c\\zero: %c number: %c|\n", 'A', 'b', 0, 55);
//	ft_result = ft_printf("|%4c%%%-3c\\zero: %c number: %c|\n", 'A', 'b', 0, 55);
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
	printf("\n----Test: unsigned int----\n");
	result = printf("|%05u %%%-5u %03u %07.3u %-5.3u|\n", -123, 22, 11, 12, -1);
	ft_result = ft_printf("|%05u %%%-5u %03u %07.3u %-5.3u|\n", -123, 22, 11, 12, -1);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: hex----\n");
	result = printf("|%05X %-5x %#3X%%|\n", -123, 44, 11);
	ft_result = ft_printf("|%05X %-5x %#3X%%|\n", -123, 44, 11);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: pointer----\n");
	result = printf("|%17p %-6p %4p|\n", ptr, NULL, ptr);
	ft_result = ft_printf("|%17p %-6p %4p|\n", ptr, NULL, ptr);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	return (0);
}
