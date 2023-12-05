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

void	ft_putnbr_u(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putchar_u(char c)
{
	write(1, &c, 1);
}

int	count_num_u(unsigned int n)
{
	int	j;

	j = 0;
	if (n == 0)
		return (j = 1);
	while (n >= 1)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	write_unsigned(va_list args)
{
	unsigned int	num;
	int				j;

	num = va_arg(args, unsigned int);
	ft_putnbr_u(num);
	j = count_num_u(num);
	return (j);
}
