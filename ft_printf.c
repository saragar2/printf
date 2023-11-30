/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:26 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/28 18:33:42 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int whichArgs(char letter, va_list args)
{
	int j;

	j = 0;
	if (letter == 'c')
		return (j = writeChar(args));
	if (letter == 's')
		return (j = writeString(args));
	if (letter == 'p')
		return (j = PorxorX(args, letter));
	if (letter == 'd')
		return (j = writeDecimal(args));
	if (letter == 'i')
		return (j = writeDecimal(args));
	if (letter == 'u')
		return (j = writeUnsigned(args));
	if (letter == 'x')
		return (j = PorxorX(args, letter));
	if (letter == 'X')
		return (j = PorxorX(args, letter));
	if (letter == '%')
		return (j = writePercent());
	else
		return (-1);
}

int ft_printf(char const *str, ...)
{
	int     i;
	int     j;
	va_list args;

	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		while (*str != '\0' && *str != '%')
		{
			write(1, str++, 1);
			i++;
		}
		if (*str == '%')
		{
			str++;
			while (*str == ' ')
				str++;
			j = whichArgs(*str, args);
			i = i + j;
			str++;
		}
	}
	va_end(args);
	return (i);
}

int main()
{
	int     n;
	//--------------%c---------------
    //char    letter = 'k';
	//n = ft_printf("Hola%cp", letter);
	//--------------%s---------------
	// char    *str = "Hola";
    // n = ft_printf("Hola%sp", str);
	//--------------%d---------------
	int	num = -1;
    n = ft_printf("Hola%dp", num);
	//--------------%i---------------
	//int	num = 1234;
    //n = ft_printf("Hola%ip", num);
	//--------------%u---------------
	//int	num = -1234;
    //n = ft_printf("Hola%up", num);
	//--------------%%---------------
    //n = ft_printf("Hola%%p");
	//--------------%p---------------
	//int num = 1234;
    //n = ft_printf("Hola%pp", &num);
	//printf("\nhola%pp", &num);
	//--------------%x---------------
	//int num = 1234;
    //n = ft_printf("Hola%xp", num);
    printf("\nn = %i", n);
    return (0);
}
