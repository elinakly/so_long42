/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:48:57 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:54 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>

# define WIDTH 424
# define HEIGHT 265

# define P_S 53

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*actor;
	mlx_texture_t	*exit;
}				t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collec;
	mlx_image_t	*actor;
	mlx_image_t	*exit;
}			t_images;

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*images;
	mlx_t				*mlx;
	char				**map;
	char				**map2;
	int					map_width;
	int					map_height;
	int					collected;
	int					n_collec;
	int					move_count;
	int					x_player;
	int					y_player;
}			t_game;

void	get_textures(t_textures *textures);
void	get_images(t_game *game, t_images *images, t_textures *textures);
void	draw_map(t_game *game, t_images *img);
void	draw_game(t_game *game, t_images *img);
void	close_window(void *param);
void	keyhook(mlx_key_data_t keydata, void *param);

char	**read_map(char *map_script);

int		init_game(t_game *game);
int		map_valid(t_game *game);
void	find_collect(t_game *game);
int		ifwalls(t_game *game);
int		char_counter(t_game *game);
int		form_map(t_game *game);
int		invalid_char(t_game *game);
int		valid_file(char *map_path);
int		valid_path(t_game *game);

void	entry(t_game *game);
void	free_map(char **map);
#endif