/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:34:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/26 09:13:44 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	int			result;
	int			ft_result = 0;
	const int	*ptr = &result;

	printf("\n----Test: char----\n");
	result = printf("%4c\n%%%-3c%c\n", 'A', 'b', '1');
	ft_result = ft_printf("%4c\n%%%-3c%c\n", 'A', 'b', '1');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: string----\n");
	result = printf("%4s\n%-8s%.5s%-1c", "Hello World!", "Hi", "Hello World!", '\n');
	ft_result = ft_printf("%4s\n%-8s%.5s%-1c", "Hello World!", "Hi", "Hello World!", '\n');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: int----\n");
	result = printf("%05i %%%-5d %03i\n", -123, 44, 11);
	ft_result = ft_printf("%05i %%%-5d %03i\n", -123, 44, 11);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: hex----\n");
	result = printf("%05X %-5x %#3X%%\n", -123, 44, 11);
	ft_result = ft_printf("%05X %-5x %#3X%%\n", -123, 44, 11);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
//
	printf("\n----Test: pointer----\n");
	result = printf("%17p\n%-4p\n", ptr, ptr);
	ft_result = ft_printf("%17p\n%-4p\n", ptr, ptr);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	return (0);
}
