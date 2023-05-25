/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:06:36 by escastel          #+#    #+#             */
/*   Updated: 2023/05/25 14:10:23 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignbr(unsigned int nb)
{
	int	count;

	count = ft_count_unsignb(nb);
	if (nb >= 0 && nb <= 9)
	{
		nb += '0';
		write(1, &nb, 1);
	}
	else
	{
		ft_putunsignbr(nb / 10);
		ft_putunsignbr(nb % 10);
	}
	return (count);
}
