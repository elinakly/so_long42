/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:22:56 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:20 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(t_game *game, int y, int x)
{
	if (!(x < 0 || y < 0 || x >= game->map_width / P_S
			|| y >= game->map_height / P_S
			|| game->map2[y][x] == '1' || game->map2[y][x] == 'X'))
	{
		if (game->map2[y][x] == 'E')
			game->map2[y][x] = 'X';
		else
		{
			game->map2[y][x] = 'X';
			flood_map(game, y + 1, x);
			flood_map(game, y - 1, x);
			flood_map(game, y, x + 1);
			flood_map(game, y, x - 1);
		}
	}
}

int	check_flood(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == WALL || map[y][x] == FLOOR
				|| map[y][x] == 'X'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_path(t_game *game)
{
	entry(game);
	flood_map(game, game->y_player / P_S, game->x_player / P_S);
	if (!check_flood(game->map2))
	{
		ft_printf("HMM, non valid map, try better!\n");
		return (free_map(game->map2), 0);
	}
	free_map(game->map2);
	return (1);
}
