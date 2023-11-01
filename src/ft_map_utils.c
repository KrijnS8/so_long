/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 14:32:31 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/01 16:56:11 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../Libft/libft.h"

int	ft_count_alnum(char *str, size_t len)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isalnum(str[i]))
			c++;
		i++;
	}
	return (c);
}

void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->l_len = 0;
	map->exit_index = -1;
	map->start_index = -1;
}
