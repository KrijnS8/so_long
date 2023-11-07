/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:35:27 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/07 12:41:18 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

static t_map	*ft_generate_map(char *path, t_map *dst)
{
	char	*line;
	int		fd;
	char	*ptr;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = ft_get_next_line(fd);
	if (line == NULL)
		return (NULL);
	dst->line_len = ft_strlen(line) - 1;
	while (line != NULL)
	{
		dst->column_len++;
		ptr = ft_strchr(line, '\n');
		if (ptr != NULL)
			*ptr = '\0';
		if (ft_strlen(line) != dst->line_len)
			return (free(line), NULL);
		if (ft_put_and_remove(&(dst->map), line) == NULL)
			return (free(line), NULL);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (dst);
}

static bool	ft_check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	map->map_len = ft_strlen(map->map);
	if (map->map_len != map->column_len * map->line_len)
		return (NULL);
	while (i < map->map_len)
	{
		if (i < map->line_len && map->map[i] != WALL)
			return (false);
		if (i % map->line_len == 0 && map->map[i] != WALL)
			return (false);
		if (i % map->line_len == map->line_len - 1 && map->map[i] != WALL)
			return (false);
		if (i > map->line_len * (map->column_len - 1) && map->map[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_chars(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->map_len)
	{
		if (!ft_chrset(map->map[i], CHARSET))
			return (false);
		if (map->map[i] == EXIT)
		{
			if (map->exit_index != -1)
				return (false);
			map->exit_index = i;
		}
		if (map->map[i] == START)
		{
			if (map->start_index != -1)
				return (false);
			map->start_index = i;
		}
		i++;
	}
	if (map->exit_index == -1 || map->start_index == -1)
		return (false);
	return (true);
}

static t_map	*ft_validate_map(t_map *map)
{
	if (!ft_check_walls(map))
		return (NULL);
	if (!ft_check_chars(map))
		return (NULL);
	return (map);
}

t_map	*ft_parse_map(char *path)
{
	t_map	*new_map;

	new_map = (t_map *) malloc(sizeof(t_map));
	if (new_map == NULL)
		ft_map_error(ERR_MAP_INNIT_FAILURE, new_map);
	if (ft_init_map(new_map) == NULL)
		ft_map_error(ERR_MAP_INNIT_FAILURE, new_map);
	if (ft_generate_map(path, new_map) == NULL)
		ft_map_error(ERR_MAP_GENERATE_FAILURE, new_map);
	if (ft_validate_map(new_map) == NULL)
		ft_map_error(ERR_MAP_VALIDATE_FAILURE, new_map);
	return (new_map);
}
