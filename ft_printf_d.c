/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:07:07 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/28 20:07:09 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	/*if (n == -2147483648)
		write(1, "-2147483648", 11);*/
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10 && n != -2147483648)
		ft_putchar(n + '0');
	else
	{
		if (n != -2147483648)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	countNum(int n)
{
	int	j;

	j = 0;
	while (n >= 1)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	writeDecimal(va_list args)
{
	int num;
	int	j;

	num = va_arg(args, int);
	ft_putnbr(num);
	j = countNum(num);
	return (j);
}