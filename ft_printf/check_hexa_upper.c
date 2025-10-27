/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:16 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:44 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count_hex(unsigned int num)
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

static char	*ft_itoa_hex(unsigned int num, const char *base)
{
	int			space_needed;
	char		*str;

	space_needed = digit_count_hex(num);
	str = malloc(sizeof(char) * (space_needed + 1));
	if (str == NULL)
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

void	check_hexa_upper(va_list args, int *count)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_hex(nbr, "0123456789ABCDEF");
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
