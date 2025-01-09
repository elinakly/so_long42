/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:13:44 by eklymova          #+#    #+#             */
/*   Updated: 2024/11/06 20:00:38 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	un_nbr_len(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		return (10);
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_undecimal(unsigned int n)
{
	if (n > 9)
		number(n / 10);
	ft_putchar((n % 10) + '0');
}

int	un_number(unsigned int n)
{
	ft_undecimal(n);
	return (un_nbr_len(n));
}
