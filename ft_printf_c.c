/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:55 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/28 18:34:00 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(va_list args)
{
	char	letter;
	int		j;

	letter = va_arg(args, int);
	write(1, &letter, 1);
	j = 1;
	return (j);
}
