/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:02:54 by escastel          #+#    #+#             */
/*   Updated: 2023/05/25 11:05:37 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long nb, char c)
{
	int		count;

	count = 0;
	if (nb < 16)
	{
		if (c == 'X')
			ft_putchar("0123456789ABCDEF"[nb % 16]);
			count++;
		if (c == 'x')
			ft_putchar("0123456789abcdef"[nb % 16]);
			count++;
	}
	else
		ft_puthexa(nb / 16, 'x');
	return (count);
}
