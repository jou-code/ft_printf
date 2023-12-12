/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:57:59 by jou               #+#    #+#             */
/*   Updated: 2023/12/02 21:59:07 by jou              ###   ########.fr       */
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
