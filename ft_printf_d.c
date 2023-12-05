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
	if (n == -2147483648)
		write(1, "-2147483648", 11);
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

int	count_num(int n)
{
	int	j;

	j = 0;
	if (n == 0)
		return (j = 1);
	if (n == -2147483648)
		return (j = 11);
	if (n < 0)
	{
		j = 1;
		n *= -1;
	}
	while (n >= 1)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	write_decimal(va_list args)
{
	int	num;
	int	j;

	num = va_arg(args, int);
	ft_putnbr(num);
	j = count_num(num);
	return (j);
}
