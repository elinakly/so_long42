/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:32:19 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/05 18:43:02 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_textures *textures)
{
	textures->floor = mlx_load_png("./textures/water.png");
	textures->wall = mlx_load_png("./textures/Grass.png");
	textures->collect = mlx_load_png("./textures/fly.png");
	textures->actor = mlx_load_png("./textures/frog_right.png");
	textures->exit = mlx_load_png("./textures/lily_closed.png");
	if (!textures->floor || !textures->wall || !textures->collect
		|| !textures->actor || !textures->exit)
	{
		ft_printf("Error\nFailed to load textures\n");
		exit(1);
	}
}

void	get_images(t_game *game, t_images *images, t_textures *textures)
{
	game->images = images;
	game->textures = textures;
	images->floor = mlx_texture_to_image(game->mlx, textures->floor);
	images->wall = mlx_texture_to_image(game->mlx, textures->wall);
	images->collec = mlx_texture_to_image(game->mlx, textures->collect);
	images->actor = mlx_texture_to_image(game->mlx, textures->actor);
	images->exit = mlx_texture_to_image(game->mlx, textures->exit);
	if (!images->floor || !images->wall || !images->collec
		|| !images->actor || !images->exit)
	{
		ft_printf("Error\nFailed to load images\n");
		exit(1);
	}
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collect);
	mlx_delete_texture(textures->actor);
	mlx_delete_texture(textures->exit);
}

void	draw_map(t_game *game, t_images *img)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, img->wall, x * P_S, y * P_S);
			else if (game->map[y][x] == FLOOR
				|| game->map[y][x] == COINS || game->map[y][x] == PLAYER
					|| game->map[y][x] == MAP_EXIT)
				mlx_image_to_window(game->mlx, img->floor, x * P_S, y * P_S);
			x++;
		}
		y++;
	}
}

void	draw_game(t_game *game, t_images *img)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COINS)
				mlx_image_to_window(game->mlx, img->collec, x * P_S, y * P_S);
			else if (game->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, img->actor, x * P_S, y * P_S);
			else if (game->map[y][x] == MAP_EXIT)
				mlx_image_to_window(game->mlx, img->exit, x * P_S, y * P_S);
			x++;
		}
		y++;
	}
}
