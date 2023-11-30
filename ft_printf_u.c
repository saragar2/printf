/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:51:58 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/29 20:52:01 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(int n)
{
	if (n == -2147483648)
		write(1, "2147483648", 10);
	if (n < 0 && n != -2147483648)
		n = -n;
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

void	ft_putchar_u(char c)
{
	write(1, &c, 1);
}

int	countNum_u(int n)
{
	int	j;

	j = 0;
	n *= -1;
	while (n >= 1)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	writeUnsigned(va_list args)
{
	int num;
	int	j;

	num = va_arg(args, int);
	ft_putnbr(num);
	j = countNum(num);
	return (j);
}
