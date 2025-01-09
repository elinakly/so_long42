/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:28:14 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/05 17:18:04 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	valid_file(char *name)
{
	char	*find;

	find = ft_strrchr(name, '.');
	if (find == name || !find)
		return (0);
	if (ft_strncmp(find, ".ber", ft_strlen(name)) != 0)
	{
		ft_printf("Wrong file name\n");
		return (0);
	}
	return (1);
}

char	*read_map_str(int fd)
{
	char	*temp;
	char	*map_str;
	char	*new_map_str;

	map_str = ft_strdup("");
	if (!map_str)
		return (NULL);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (temp[0] == '\n')
			return (free(temp), free(map_str), NULL);
		new_map_str = ft_strjoin(map_str, temp);
		free(map_str);
		free(temp);
		if (!new_map_str)
			return (NULL);
		map_str = new_map_str;
	}
	return (map_str);
}

char	**read_map(char *map_script)
{
	int		fd;
	char	*map_str;
	char	**map_array;

	fd = open(map_script, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_str = read_map_str(fd);
	close(fd);
	if (!map_str)
		return (NULL);
	map_array = ft_split(map_str, '\n');
	free(map_str);
	if (!map_array)
		return (NULL);
	return (map_array);
}
