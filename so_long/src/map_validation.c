/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:10:23 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/05 17:17:52 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COINS || game->map[y][x] == MAP_EXIT
				|| game->map[y][x] == PLAYER
					|| game->map[y][x] == WALL || game->map[y][x] == FLOOR)
				x++;
			else
				return (0);
		}
		y++;
	}
	return (1);
}

int	form_map(t_game *game)
{
	int	y;
	int	x;
	int	size;

	size = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		size += x;
		y++;
	}
	if (size % y == 0)
		return (1);
	return (0);
}

int	counter(char **map, char c)
{
	int	y;
	int	x;
	int	counter;

	counter = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

int	char_counter(t_game *game)
{
	if (counter(game->map, 'P') != 1 || counter(game->map, 'E') != 1
		|| counter(game->map, 'C') < 1)
		return (0);
	return (1);
}

int	ifwalls(t_game *game)
{
	int		x;
	int		y;
	int		width;
	int		height;
	char	**map;

	map = game->map;
	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	x = 0;
	while (x < width)
		if (map[0][x] != '1' || map[height - 1][x++] != '1')
			return (0);
	y = 0;
	while (y < height)
		if (map[y][0] != '1' || map[y++][width - 1] != '1')
			return (0);
	return (1);
}
