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
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		which_args(char letter, va_list args);
int		write_char(va_list args);
int		write_string(va_list args);
int		write_decimal(va_list args);
int		write_unsigned(va_list args);
int		write_percent(void);
int		write_minus_hex(unsigned int num);
int		write_mayus_hex(unsigned int num);
int		write_void_hex(size_t num);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		count_num(int n);
void	ft_putnbr_u(unsigned int n);
void	ft_putchar_u(char c);
int		count_num_u(unsigned int n);
int		p_or_x_or_mx(va_list args, char letter);

#endif