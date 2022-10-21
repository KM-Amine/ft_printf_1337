/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:05:57 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/21 09:52:39 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putnbr(long i, int *len)
{
	if (i < 0)
	{
		ft_putchar('-', len);
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}

void	ft_puthex(unsigned int i, char *base, int *len)
{
	if (i > ft_strlen(base)-1)
		ft_puthex(i / ft_strlen(base), base, len);
	ft_putchar(base[i % ft_strlen(base)], len);
}
