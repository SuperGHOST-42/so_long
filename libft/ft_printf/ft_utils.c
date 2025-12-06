/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:14:18 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/18 13:11:46 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}
/*
size_t	ft_strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}*/

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb = -nb;
		len += write(1, "-", 1);
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putnbr_base(unsigned long long nbr, char format)
{
	int						count;
	char					*base_char;
	unsigned long long		base_int;

	base_int = 16;
	base_char = "0123456789abcdef";
	if (format == 'X')
		base_char = "0123456789ABCDEF";
	else if (format == 'u')
		base_int = 10;
	count = 0;
	if (nbr >= base_int)
		count += ft_putnbr_base(nbr / base_int, format);
	count += ft_putchar(base_char[nbr % base_int]);
	return (count);
}
