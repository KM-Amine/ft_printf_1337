/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:06:03 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/30 10:02:53 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsubaddr(unsigned long i, char *base, int *len)
{
	if (i > ft_strlen(base)-1)
		ft_putsubaddr(i / ft_strlen(base), base, len);
	ft_putchar(base[i % ft_strlen(base)], len);
}

void	ft_putaddr(void *p, char *base, int *len)
{
	ft_putstr("0x", len);
	ft_putsubaddr((unsigned long)p, base, len);
}

void	ft_putuns(unsigned int i, int *len)
{
	if (i > 9)
		ft_putuns(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}

void	ft_parser(char c, va_list pntr, int *len)
{
	char	*tmp;

	if (c == 'c')
		ft_putchar(va_arg(pntr, int), len);
	else if (c == 's')
	{
		tmp = va_arg(pntr, char *);
		if (tmp == 0)
			ft_putstr("(null)", len);
		else
			ft_putstr(tmp, len);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(pntr, int), len);
	else if (c == 'u')
		ft_putuns(va_arg(pntr, unsigned int), len);
	else if (c == 'p')
		ft_putaddr(va_arg(pntr, void *), HEX_LOW, len);
	else if (c == 'x')
		ft_puthex(va_arg(pntr, unsigned int), HEX_LOW, len);
	else if (c == 'X')
		ft_puthex(va_arg(pntr, unsigned int), HEX_UPP, len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *s, ...)
{
	va_list	pntr;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	va_start(pntr, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i], &len);
		}
		else
		{
			i++;
			ft_parser(s[i], pntr, &len);
		}
		i++;
	}
	va_end(pntr);
	return (len);
}
