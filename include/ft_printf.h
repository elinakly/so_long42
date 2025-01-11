/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:55 by eklymova          #+#    #+#             */
/*   Updated: 2024/11/06 21:11:07 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int				ft_printf(const char	*input, ...);
int				ft_putchar(int c);
int				ft_putstr(char *s);
int				un_number(unsigned int n);
unsigned int	ft_heximal(unsigned int n, char *hex);
int				ft_pointer(void *nb, char *hex);
int				number(int n);

#endif