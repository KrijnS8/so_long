/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:35:27 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 16:32:21 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/dfs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

static t_map	*generate_map(char *path, t_map *dst)
{
	char	*line;
	int		fd;
	char	*ptr;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (close(fd), NULL);
	line = ft_get_next_line(fd);
	if (line == NULL)
		return (close(fd), NULL);
	dst->line_len = ft_strlen(line) - 1;
	while (line != NULL)
	{
		dst->column_len++;
		ptr = ft_strchr(line, '\n');
		if (ptr != NULL)
			*ptr = '\0';
		if (ft_strlen(line) != dst->line_len)
			return (free(line), close(fd), NULL);
		if (put_and_remove(&(dst->map), line) == NULL)
			return (free(line), close(fd), NULL);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (close(fd), dst);
}

static bool	check_walls(t_map *map)
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

static bool	check_chars(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->map_len)
	{
		if (!chrset(map->map[i], CHARSET))
			return (false);
		if (!check_special_chars(map, i))
			return (false);
		i++;
	}
	if (map->exit_index == -1 || map->start_index == -1)
		return (false);
	if (map->coll_count < 1)
		return (false);
	return (true);
}

static t_map	*validate_map(t_map *map)
{
	if (!check_walls(map))
		return (NULL);
	if (!check_chars(map))
		return (NULL);
	if (dfs(map) <= 0)
		return (NULL);
	return (map);
}

t_map	*parse_map(char *path)
{
	t_map	*new_map;
	char	*ptr;

	ptr = path;
	while (*ptr != '\0')
	{
		if (*ptr == '.' && ft_strcmp(ptr, ".ber") != 0)
			return (NULL);
		ptr++;
	}
	new_map = (t_map *) malloc(sizeof(t_map));
	if (new_map == NULL)
		return (NULL);
	if (init_map(new_map) == NULL)
		return (free_map(new_map), NULL);
	if (generate_map(path, new_map) == NULL)
		return (free_map(new_map), NULL);
	if (validate_map(new_map) == NULL)
		return (free_map(new_map), NULL);
	return (new_map);
}
