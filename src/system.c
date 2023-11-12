/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 14:16:11 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 12:18:35 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/system.h"
#include "../include/map.h"
#include "../Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../include/texture.h"
#include <stdio.h>

void	init_system(t_sys	*data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->player_data = NULL;
	data->map = NULL;
	data->player = NULL;
	data->collectible = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
}

void	init_player(t_sys *data)
{
	data->player_data = (t_player *)malloc(sizeof(t_player));
	if (data->player_data == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_data->x = data->map->start_index % data->map->line_len;
	data->player_data->y = data->map->start_index / data->map->line_len;
	data->player_data->step_count = 0;
}

int destroy_system(t_sys *data)
{
	destroy_textures(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map != NULL)
	{
		if (data->map->map != NULL)
			free(data->map->map);
		if (data->map->coll_arr != NULL)
			free(data->map->coll_arr);
		free(data->map);
	}
	if (data->player_data != NULL)
		free(data->player_data);
	free(data);
	exit(1);
	return (0);
}

void	system_error(t_sys *data, t_error error)
{
	print_error(error);
	destroy_system(data);
}

int	handle_input(int keysym, t_sys *data)
{
	if (keysym == XK_Escape)
	{
		destroy_system(data);
	}
	if (keysym == 119)
	{
		if (data->map->map[(data->player_data->y - 1) * data->map->line_len + data->player_data->x] != WALL)
			data->player_data->y--;
	}
	if (keysym == 97)
	{
		if (data->map->map[data->player_data->y * data->map->line_len + (data->player_data->x - 1)] != WALL)
			data->player_data->x--;
	}
	if (keysym == 115)
	{
		if (data->map->map[(data->player_data->y + 1) * data->map->line_len + data->player_data->x] != WALL)
			data->player_data->y++;
	}
	if (keysym == 100)
	{
		if (data->map->map[data->player_data->y * data->map->line_len + (data->player_data->x + 1)] != WALL)
			data->player_data->x++;
	}
	return (0);
}
