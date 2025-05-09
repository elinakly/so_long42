/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:48:54 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/09 13:35:15 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nWrong number of arguments\n"), EXIT_FAILURE);
	if (!valid_file(argv[1]))
		return (EXIT_FAILURE);
	game.map = read_map(argv[1]);
	game.map2 = read_map(argv[1]);
	if (!game.map || !game.map2)
		return (ft_printf("Map reading error\n"), EXIT_FAILURE);
	if (!map_valid(&game) || !valid_path(&game))
		return (free_map(game.map), free_map(game.map2), EXIT_FAILURE);
	init_game(&game);
	return (EXIT_SUCCESS);
}
