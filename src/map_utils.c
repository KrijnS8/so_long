/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 14:32:31 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 14:31:58 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../Libft/libft.h"

char	*put_and_remove(char **dst, char *src)
{
	char	*tmp;

	if (*dst == NULL)
	{
		*dst = (char *) ft_calloc (1, sizeof(char));
		if (*dst == NULL)
			return (NULL);
	}
	tmp = ft_strjoin(*dst, src);
	if (tmp == NULL)
		return (NULL);
	free(*dst);
	*dst = tmp;
	return (tmp);
}

int	chrset(char c, const char *set)
{
	return (ft_strchr(set, c) != NULL);
}

t_map	*init_map(t_map *map)
{
	map->map = (char *)ft_calloc(1, sizeof(char));
	if (map->map == NULL)
		return (NULL);
	map->line_len = 0;
	map->column_len = 0;
	map->exit_index = -1;
	map->start_index = -1;
	map->coll_lst = NULL;
	map->coll_count = 0;
	return (map);
}

void	print_map(t_map *map)
{
	ft_printf("Map: %s\nl_len: %d\nc_len: %d\nstart_index: %d\nexit_index: %d", \
			map->map, (int)map->line_len, (int)map->column_len, map->start_index, map->exit_index);
}
