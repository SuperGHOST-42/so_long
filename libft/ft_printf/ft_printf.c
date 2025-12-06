/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:49 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/18 13:03:14 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	print_format(char format, va_list *args)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x")
			+ ft_putnbr_base((unsigned long long)ptr, format));
	}
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), format));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), format));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (-1);
	__builtin_va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += print_format(str[++i], &args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	__builtin_va_end(args);
	return (len);
}
/* 
int	main(void)
{
    char    *s = NULL;
	int len = 0;
	
    len = printf("Real: %s",s);
	printf("\nlen: %i\n", len);

    len = ft_printf("Mine: %s",s);
	printf("\nlen: %i\n", len);
	
    return (0);
} */
