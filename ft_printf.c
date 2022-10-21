/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:06:03 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/21 10:56:20 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putsubaddr(unsigned long long i, char *base, int *len)
{
	if (i > ft_strlen(base)-1)
		ft_putsubaddr(i / ft_strlen(base), base, len);
	ft_putchar(base[i % ft_strlen(base)], len);
}

void	ft_putaddr(void *p, char *base, int *len)
{
	ft_putstr("0x", len);
	ft_putsubaddr((unsigned long long)p, base, len);
}

void	ft_putuns(unsigned int i, int *len)
{
	if (i > 9)
		ft_putuns(i / 10, len);
	ft_putchar(i % 10 + '0', len);
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
			if (s[i] == 'c')
				ft_putchar(va_arg(pntr, int), &len);
			if (s[i] == 's')
				ft_putstr(va_arg(pntr, char *), &len);
			if (s[i] == 'd' || s[i] == 'i')
				ft_putnbr(va_arg(pntr, int), &len);
			if (s[i] == 'u')
				ft_putuns(va_arg(pntr, unsigned int), &len);
			if (s[i] == 'p')
				ft_putaddr(va_arg(pntr, void *), HEX_LOW, &len);
			if (s[i] == 'x')
				ft_puthex(va_arg(pntr, unsigned int), HEX_LOW, &len);
			if (s[i] == 'X')
				ft_puthex(va_arg(pntr, unsigned int), HEX_UPP, &len);
			if (s[i] == '%')
				ft_putchar('%', &len);
		}
		i++;
	}
	va_end(pntr);
	return (len);
}

int main (void)
{
	int	i;

	i = 0;
	printf("%d\n", printf("hello%c",'t'));
	printf("%d", ft_printf("hello%c",'t'));
}
