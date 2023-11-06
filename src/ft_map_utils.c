/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 14:32:31 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/06 16:41:02 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../Libft/libft.h"

char	*ft_put_and_remove(char **dst, char *src)
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

int	ft_chrset(char c, const char *set)
{
	return (ft_strchr(set, c) != NULL);
}

t_map	*ft_init_map(t_map *map)
{
	map->map = (char *)ft_calloc(1, sizeof(char));
	if (map->map == NULL)
		return (NULL);
	map->line_len = 0;
	map->colon_len = 0;
	map->exit_index = -1;
	map->start_index = -1;
	return (map);
}

void	ft_map_error(t_error error, t_map *map)
{
	ft_print_error(error);
	if (map->map != NULL)
		free(map->map);
	if (map != NULL)
		free(map);
	exit(1);
}
