/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:34:37 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 19:52:48 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_char(va_list args, int *count)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	(*count)++;
}
