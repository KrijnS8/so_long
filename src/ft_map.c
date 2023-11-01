/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:35:27 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/01 16:52:49 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 64

static size_t	ft_map_size(char *path)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	size_t	size;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (close(fd), 0);
	buffer[BUFFER_SIZE] = '\0';
	while (bytes_read > 0)
	{
		size += ft_count_alnum(buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
	}
	if (bytes_read < 0)
		return (close(fd), 0);
	return (close(fd), size);
}

static t_map	ft_generate_map(int fd, size_t size)
{
	t_map	new_map;
	char	*line;
	int		i;
	
	ft_init_map(&new_map);
	new_map.map = (char *)ft_calloc(size + 1, sizeof(char));
	if (new_map.map == NULL)
		return (new_map);
	line = ft_get_next_line(fd);
	if (line == NULL)
		return (free(new_map.map), new_map.map = NULL, new_map);
	new_map.l_len = ft_strlen(line) - 1;
	i = 1;
	while (line != NULL)
	{
		// if (ft_strlen(line) -1 != new_map.l_len)
		// 	return (free(new_map.map), free(line), new_map.map = NULL, new_map);
		if(line[new_map.l_len] == '\n')
			line[new_map.l_len] = '\0';
		ft_strlcat(new_map.map, line, new_map.l_len * i + ft_strlen(line));
		free(line);
		line = ft_get_next_line(fd);
		i++;
	}
	free(line);
	return (new_map);
}

t_map	ft_parse_map(char *path)
{
	t_map	new_map;
	size_t	m_size;
	int		fd;
	int		i;

	m_size = ft_map_size(path);
	if (m_size == 0)
		return (new_map.map = NULL, new_map);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (new_map.map = NULL, new_map);
	new_map = ft_generate_map(fd, m_size);
	if (new_map.map == NULL)
		return (new_map);
	i = 0;
	while (new_map.map[i] != '\0')
	{
		if (new_map.map[i] == 'P')
		{
			if (new_map.start_index != -1)
				return (close(fd), free(new_map.map), new_map.map = NULL, new_map);
			new_map.start_index = i;
		}
		if (new_map.map[i] == 'E')
		{
			if (new_map.exit_index != -1)
				return (close(fd), free(new_map.map), new_map.map = NULL, new_map);
			new_map.exit_index = i;
		}
		i++;
	}
	close(fd);
	return (new_map);
}

#include <stdio.h>

void	ft_print_map(t_map map)
{
	printf("Map: %s\nl_len: %zu\nstart_index: %d\nexit_index: %d", map.map, map.l_len, map.start_index, map.exit_index);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (printf("error"), 0);
	t_map map = ft_parse_map(argv[1]);

	ft_print_map(map);
	free(map.map);
	return (0);
}
