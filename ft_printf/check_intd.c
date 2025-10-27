/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:38:51 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:56:35 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count_int(int a)
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

void	check_intd(va_list args, int *count)
{
	int	num;

	num = (int)va_arg(args, int);
	ft_putnbr_fd(num, 1);
	*count += digit_count_int(num);
}
