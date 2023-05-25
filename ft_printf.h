/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:46:05 by escastel          #+#    #+#             */
/*   Updated: 2023/05/25 12:29:26 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_count_nb(int nb);
int	ft_putnbr(int nb);
int	ft_putunsignbr(unsigned int nb);
int	ft_puthexa(unsigned long long nb, char c);
int	ft_putptr(unsigned long long ptr);

#endif