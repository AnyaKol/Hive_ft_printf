/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:34:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/06/02 13:38:48 by akolupae         ###   ########.fr       */
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

	printf("\n----Test: %%----\n");
	result = printf("|%% %5% %-3% %%|\n");
	ft_result = ft_printf("|%% %5% %-3% %%|\n");
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: char----\n");
	result = printf("|%4c%%%-3c\\zero: %c number: %c|%c", 'A', 'b', 0, 55, '\n');
	ft_result = ft_printf("|%4c%%%-3c\\zero: %c number: %c|%c", 'A', 'b', 0, 55, '\n');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: string----\n");
	result = printf("|%4s%-8s%8.5s%-10s|\n", "Hello World!", "", "Hello World!", null_ptr);
	ft_result = ft_printf("|%4s%-8s%8.5s%-10s|\n", "Hello World!", "", "Hello World!", null_ptr);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
//	printf("\n----Test: empty string----\n");
//	result = printf("|% s,% s|\n", NULL, null_ptr);
//	ft_result = ft_printf("|% s|\n", "");
//	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: int----\n");
	result = printf("|%05i %%%-5d %03i %0 4d % 04d %+04i %7.3d %-5.3i|\n", -123, 22, 0, 444, -444, 42, 12, -1);
	ft_result = ft_printf("|%05i %%%-5d %03i %0 4d % 04d %+04i %7.3d %-5.3i|\n", -123, 22, 0, 444, -444, 42, 12, -1);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: unsigned int----\n");
	result = printf("|%05u %%%-5u %03u %7.3u %-5.3u|\n", -123, 22, 0, 12, -1);
	ft_result = ft_printf("|%05u %%%-5u %03u %7.3u %-5.3u|\n", -123, 22, 0, 12, -1);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: hex----\n");
	result = printf("|%05X %-5x %#X%%%#x|\n", -123, 44, 0, 5757575);
	ft_result = ft_printf("|%05X %-5x %#X%%%#x|\n", -123, 44, 0, 5757575);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: pointer----\n");
	result = printf("|%17p %-6p %4p %p|\n", ptr, NULL, ptr, (void *) 0);
	ft_result = ft_printf("|%17p %-6p %4p %p|\n", ptr, NULL, ptr, (void *) 0);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	return (0);
}
