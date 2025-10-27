/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:23:40 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:17:36 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_string(va_list args, int *count)
{
	char	*string;

	string = (char *)va_arg(args, char *);
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	ft_putstr_fd(string, 1);
	*count += (int)ft_strlen(string);
}
