/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:37:32 by arpereir          #+#    #+#             */
/*   Updated: 2025/12/02 14:37:33 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(t_game *game, char *msg)
{
	if (game)
		free_all(game);
	ft_printf("%s\n", msg);
	exit(1);
}
