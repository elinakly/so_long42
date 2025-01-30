/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:32:19 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/05 17:22:10 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_map(t_game *game)
{
	if (game->map[0])
		return (1);
	else
		return (0);
}

int	ifexit(t_game *game)
{
	if (game->n_collec == 0)
	{
		ft_printf("You won!\n");
		mlx_close_window(game->mlx);
		return (0);
	}
	else
		return (0);
	return (1);
}

void	close_window(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window(game->mlx);
}

int	map_valid(t_game *game)
{
	if (!empty_map(game))
		return (printf("Create a map!\n"), 0);
	if (!invalid_char(game))
	{
		ft_printf("Open your eyes!! Map containce invalid object.\n");
		return (0);
	}
	if (!form_map(game))
	{
		ft_printf("Did you skip geometry classes? Map must be rectangular!\n");
		return (0);
	}
	if (!char_counter(game))
	{
		ft_printf("Dude, how do you suppose to play without thingy??\n");
		return (0);
	}
	if (!ifwalls(game))
	{
		ft_printf("My lake is leaking, HEELP!!\n");
		return (0);
	}
	return (1);
}

int	init_game(t_game *game)
{
	t_textures	textures;
	t_images	images;

	game->move_count = 0;
	game->collected = 0;
	find_collect(game);
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	get_textures(&textures);
	get_images(game, &images, &textures);
	draw_map(game, &images);
	draw_game(game, &images);
	mlx_key_hook(game->mlx, keyhook, game);
	mlx_close_hook(game->mlx, close_window, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	return (1);
}
