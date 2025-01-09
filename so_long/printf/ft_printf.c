/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:05:22 by eklymova          #+#    #+#             */
/*   Updated: 2024/11/06 21:23:03 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	input_function(const char *input, va_list args)
{
	if (*input == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*input == '%')
		return (ft_putchar('%'));
	else if (*input == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*input == 'd' || *input == 'i')
		return (number((va_arg(args, int))));
	else if (*input == 'x')
		return (ft_heximal(va_arg(args, int), "0123456789abcdef"));
	else if (*input == 'X')
		return (ft_heximal(va_arg(args, int), "0123456789ABCDEF"));
	else if (*input == 'u')
		return (un_number(va_arg(args, unsigned int)));
	else if (*input == 'p')
		return (ft_pointer(va_arg(args, void *), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char	*input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start (args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += input_function(input, args);
		}
		else
		{
			ft_putchar(*input);
			i++;
		}
		input++;
	}
	va_end(args);
	return (i);
}

// int	main(void)
// {
// // 	// void *s = NULL;
// // int a = INT_MAX;
// // int b = INT_MIN;
// // // ft_printf("my : %c\n", 'f');
// // // printf("orig : %c\n", 'f');
// // // ft_printf("my : %%\n");
// // // printf("orig : %%\n");
// // // ft_printf("my : NULL %s NULL ", s);
// // // printf("or : NULL %s NULL ", (char *)s);
// ft_printf("\nmy did: %d\n", -2147483648);
// printf("\norig did: %ld\n", -2147483648);
// // // ft_printf("my : %i\n", 3243);
// // // printf("orig : %i\n", 3243);
// // // ft_printf("my : %x\n", 2);
// // // printf("orig : %x\n", 2);
// // // ft_printf("my : %X\n", 3);
// // // printf("orig : %X\n", 3);
// // ft_printf("\nmy : %u\n", -1);
// // printf("\norig : %u\n", -1);
// // // ft_printf("my : %p %p ", 0, 0);
// // // size_t n = 0;
// // // printf("orig : %p %p ", (void *)n,(void *)n);
// }
