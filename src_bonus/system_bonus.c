/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 14:16:11 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:08:29 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	init_system(t_sys	*data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->player_data = NULL;
	data->map = NULL;
	data->player = NULL;
	data->player_rev = NULL;
	data->collectible = NULL;
	data->foe = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
	data->bg = NULL;
	data->frame_buf = NULL;
}

int	destroy_system(t_sys *data)
{
	destroy_textures(data);
	destroy_frame_buffer(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_map(data->map);
	if (data->player_data != NULL)
		free(data->player_data);
	free(data);
	exit(0);
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
		move_player(data, 0, -1);
	if (keysym == 97)
		move_player(data, -1, 0);
	if (keysym == 115)
		move_player(data, 0, 1);
	if (keysym == 100)
		move_player(data, 1, 0);
	return (0);
}
