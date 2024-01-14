/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:57:59 by jou               #+#    #+#             */
/*   Updated: 2024/01/14 20:10:10 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_checkspec(va_list args, char spec);
int	ft_printchr(char *va_arg);
int	ft_printnbr(long va_arg, int base, char *set,  int u);

#endif
