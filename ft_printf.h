/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:48:25 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/21 10:52:36 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"

size_t	ft_strlen(char *s);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(long i, int *len);
void	ft_puthex(unsigned int i, char *base, int *len);
void	ft_putsubaddr(unsigned long long i, char *base, int *len);
void	ft_putaddr(void *p, char *base, int *len);
void	ft_putuns(unsigned int i, int *len);
int		ft_printf(const char *s, ...);

#endif
