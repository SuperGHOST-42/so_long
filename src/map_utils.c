/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:41 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:48 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen_no_nl(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}
