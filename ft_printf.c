/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:06:03 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/21 09:52:23 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// int	ft_printf(const char *s, ...);
// {
	
// }

int main (void)
{
	int	i;

	i = 0;
	printf("%x\n",-1);
	ft_puthex(-1,"0123456789abcdef",&i);
	//ft_putnbr(12,&i);
}
