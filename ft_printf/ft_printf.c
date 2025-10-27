/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:08:46 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/26 14:13:35 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_funcs(const char *s, va_list args, int *count)
{
	if (s[0] == 'c')
		check_char(args, count);
	else if (s[0] == 'd')
		check_intd(args, count);
	else if (s[0] == 'i')
		check_inti(args, count);
	else if (s[0] == 's')
		check_string(args, count);
	else if (s[0] == 'u')
		check_unsign_int(args, count);
	else if (s[0] == 'x')
		check_hexa_lower(args, count);
	else if (s[0] == 'X')
		check_hexa_upper(args, count);
	else if (s[0] == '%')
		check_percent(count);
	else if (s[0] == 'p')
		check_pointer(args, count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			check_funcs(&s[++i], args, &count);
		else if (count < 0)
			return (-1);
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
