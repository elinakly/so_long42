/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:46:09 by eklymova          #+#    #+#             */
/*   Updated: 2024/11/06 17:23:43 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	lenth;

// 	lenth = 0;
// 	while (s[lenth] != '\0')
// 	{
// 		lenth++;
// 	}
// 	return (lenth);
// }

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return (i);
}
