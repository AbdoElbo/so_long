/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:00 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:50 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count_ptr(unsigned long long num)
{
	int		count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static char	*ft_itoa_ptr(unsigned long long num)
{
	int			space_needed;
	char		*str;
	const char	*base;

	base = "0123456789abcdef";
	space_needed = digit_count_ptr(num);
	str = malloc(sizeof(char) * (space_needed + 1));
	if (!str)
		return (NULL);
	str[space_needed] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		space_needed--;
		str[space_needed] = base[num % 16];
		num /= 16;
	}
	return (str);
}

void	check_pointer(va_list args, int *count)
{
	unsigned long long	num;
	int					len;
	char				*hex_str;

	num = (unsigned long long)va_arg(args, void *);
	if (!num)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
		return ;
	}
	hex_str = ft_itoa_ptr(num);
	if (!hex_str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_str, 1);
	len = ft_strlen(hex_str);
	*count += len + 2;
	free(hex_str);
}
