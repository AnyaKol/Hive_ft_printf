/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:34:42 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/18 19:13:11 by akolupae         ###   ########.fr       */
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
	result = printf("%c\n%c %c\n", 'A', 'b', '1');
	ft_result = ft_printf("%c\n%c %c\n", 'A', 'b', '1');
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	//
	printf("\n----Test: string----\n");
	result = printf("%s\n", "Hello World!");
	ft_result = ft_printf("%s\n", "Hello World!");
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	//
	printf("\n----Test: int----\n");
	result = printf("%i\n", 1234567);
	//ft_result = ft_printf("%i\n", 1234567);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	//
	printf("\n----Test: pointer----\n");
	result = printf("%p\n", ptr);
	//ft_result = ft_printf("%p\n", ptr);
	printf("Printf: %i\nMy fun: %i\n", result, ft_result);
	return (0);
}
