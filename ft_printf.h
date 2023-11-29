/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:14:05 by saragar2          #+#    #+#             */
/*   Updated: 2023/11/28 19:14:08 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
#include <stdarg.h>

int ft_printf(char const *str, ...);
int whichArgs(char letter, va_list args);
int writeChar(va_list args);
int writeString(va_list args);
int	writeDecimal(va_list args);
int	writeInt(va_list args);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		countNum(int n);

#endif
