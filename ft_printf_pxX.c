/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:16:50 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/30 18:16:53 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_minus_hex(unsigned int num)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (num < 16)
		j += write(1, base + num, 1);
	else
	{
		j += write_minus_hex(num / 16);
		j += write(1, base + (num % 16), 1);
	}
	return (j);
}

int	write_mayus_hex(unsigned int num)
{
	char	*base;
	int		j;

	base = "0123456789ABCDEF";
	j = 0;
	if (num < 16)
		j += write(1, base + num, 1);
	else
	{
		j += write_mayus_hex(num / 16);
		j += write(1, base + (num % 16), 1);
	}
	return (j);
}

int	write_void_hex(size_t forp)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (forp < 16)
		j += write(1, base + forp, 1);
	else
	{
		j += write_void_hex(forp / 16);
		j += write(1, base + (forp % 16), 1);
	}
	return (j);
}

int	p_or_x_or_mx(va_list args, char letter)
{
	int		num;
	size_t	forp;
	int		j;

	if (letter == 'x')
	{
		num = va_arg(args, unsigned int);
		return (j = write_minus_hex(num));
	}
	if (letter == 'X')
	{
		num = va_arg(args, unsigned int);
		return (j = write_mayus_hex(num));
	}
	if (letter == 'p')
	{
		forp = va_arg(args, size_t);
		write(1, "0x", 2);
		return (j = write_void_hex(forp) + 2);
	}
	else
		return (-1);
}
