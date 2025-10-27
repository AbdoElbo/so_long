/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unsign_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:00 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:57 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count_unsigned_int(unsigned int a)
{
	int		count;
	long	num;

	count = 0;
	num = a;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

static void	ft_putnbr_int(unsigned int n, int fd)
{
	char	a;
	long	nb;

	nb = n;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	a = (nb % 10) + '0';
	ft_putchar_fd(a, fd);
}

void	check_unsign_int(va_list args, int *count)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_putnbr_int(num, 1);
	*count += digit_count_unsigned_int(num);
}
