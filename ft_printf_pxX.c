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

int	writeMinusHex(unsigned int num)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (num < 16)
		j += write(1, base + num, 1);
	else
	{
		j += writeMinusHex(num / 16);
		j += write(1, base + (num % 16), 1);
	}
	return (j);
}

int	writeMayusHex(unsigned int num)
{
	char	*base;
	int		j;

	base = "0123456789ABCDEF";
	j = 0;
	if (num < 16)
		j += write(1, base + num, 1);
	else
	{
		j += writeMayusHex(num / 16);
		j += write(1, base + (num % 16), 1);
	}
	return (j);
}

int	writeVoidHex(size_t num)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (num < 16)
		j += write(1, base + num, 1);
	else
	{
		j += writeMinusHex(num / 16);
		j += write(1, base + (num % 16), 1);
	}
	return (j);
}

int	PorxorX(va_list args, char letter)
{
	int	num;
	int j;

	if (letter == 'x')
	{
		num = va_arg(args, unsigned int);
		return (j = writeMinusHex(num));
	}
	if (letter == 'X')
	{
		num = va_arg(args, unsigned int);
		return (j = writeMayusHex(num));
	}
	if (letter == 'p')
	{
		num = va_arg(args, size_t);
		write(1, "0x", 2);
		return (j = writeVoidHex(num));
	}
	else
		return (-1);
}
