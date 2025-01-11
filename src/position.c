/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:48:31 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/07 15:07:16 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	entry(t_game *game)
{
	int	y;
	int	x;
	int	player_found;

	player_found = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == PLAYER && !player_found)
			{
				game->x_player = x * P_S;
				game->y_player = y * P_S;
				player_found = 1;
			}
			x++;
		}
		y++;
	}
	game->map_width = x * P_S;
	game->map_height = y * P_S;
}

void	find_collect(t_game *game)
{
	int	y;
	int	x;
	int	collect;

	collect = 0;
	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COINS)
				collect++;
			x++;
		}
		y++;
	}
	game->n_collec = collect;
}
