/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:14:25 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/28 19:14:27 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writeString(va_list args)
{
	char	*string;
	int		j;

	j = 0;
	string = va_arg(args, char *);
	if (!string)
	{
		write(1, "(null)", 6);
		return (j = 6);
	}
	while(*string != '\0')
	{
		write(1, string, 1);
		string++;
		j++;
	}
	return (j);
}
