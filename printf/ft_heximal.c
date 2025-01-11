/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heximal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:22:10 by eklymova          #+#    #+#             */
/*   Updated: 2024/11/06 17:56:06 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(char	*hex_value)
{
	int	len;

	len = 0;
	while (hex_value[len] != '\0')
		len++;
	return (len);
}

int	ft_heximal_pointer(uintptr_t n, char *hex)
{
	char			hex_value[20];
	int				i;
	unsigned int	h;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		h = n % 16;
		hex_value[i++] = hex[h];
		n = n / 16;
	}
	hex_value[i] = '\0';
	while (i - 1 >= 0)
	{
		ft_putchar(hex_value[i - 1]);
		i--;
	}
	return (ft_hexlen(hex_value));
}

int	ft_pointer(void *nb, char *hex)
{
	uintptr_t	n;

	n = (uintptr_t) nb;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_heximal_pointer(n, hex) + 2);
}

unsigned int	ft_heximal(unsigned int n, char *hex)
{
	char			hex_value[20];
	int				i;
	unsigned int	h;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		h = n % 16;
		hex_value[i++] = hex[h];
		n = n / 16;
	}
	hex_value[i] = '\0';
	while (i - 1 >= 0)
	{
		ft_putchar(hex_value[i - 1]);
		i--;
	}
	return (ft_hexlen(hex_value));
}
