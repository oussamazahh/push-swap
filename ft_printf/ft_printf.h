/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:29:58 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/22 13:42:50 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char const *s);
void	ft_putnbr_fd(int n, int fd);
int	ft_putnbr(int n);
int	ft_putchar(int c);
int	ft_putu(unsigned int n);
int	ft_putadd(unsigned long nb);
int	ft_puthex(unsigned int nb, char c);

#endif