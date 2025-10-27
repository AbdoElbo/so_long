/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:59:00 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:32 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
void	check_char(va_list args, int *count);
void	check_intd(va_list args, int *count);
void	check_inti(va_list args, int *count);
void	check_string(va_list args, int *count);
void	check_pointer(va_list args, int *count);
void	check_hexa_upper(va_list args, int *count);
void	check_hexa_lower(va_list args, int *count);
void	check_unsign_int(va_list args, int *count);
void	check_percent(int *count);

#endif
