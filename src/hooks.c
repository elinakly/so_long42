/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:22:56 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/05 17:22:28 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_instance_index(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->images->collec->count)
	{
		if (game->images->collec->instances[i].x == x
			&& game->images->collec->instances[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

void	disable_fly(t_game *game, int new_x, int new_y)
{
	int	index;

	index = get_instance_index(game, new_x, new_y);
	if (index > -1)
		game->images->collec->instances[index].enabled = 0;
}

void	update_actor_pos(t_game *game, int new_x, int new_y)
{
	game->x_player = new_x;
	game->y_player = new_y;
	game->images->actor->instances[0].x = new_x;
	game->images->actor->instances[0].y = new_y;
	game->map[new_y / P_S][new_x / P_S] = PLAYER;
	game->move_count++;
}

int	move_plz(t_game *game, int x, int y)
{
	int	new_y;
	int	new_x;

	new_y = game->y_player + y;
	new_x = game->x_player + x;
	if (game->map[new_y / P_S][new_x / P_S] != WALL)
	{
		if (game->map[new_y / P_S][new_x / P_S] == COINS)
		{
			disable_fly(game, new_x, new_y);
			game->n_collec--;
			game->collected++;
		}
		if (game->map[new_y / P_S][new_x / P_S] == MAP_EXIT)
			return (ifexit(game));
		if (game->map[new_y / P_S][new_x / P_S] != MAP_EXIT)
			game->map[game->y_player / P_S][game->x_player / P_S] = FLOOR;
		update_actor_pos(game, new_x, new_y);
		return (1);
	}
	return (0);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		move;

	move = 0;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move = move_plz(game, 0, -P_S);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move = move_plz(game, 0, P_S);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move = move_plz(game, -P_S, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move = move_plz(game, P_S, 0);
	}
	if (move)
		ft_printf("Moves: %d\n", game->move_count);
}
