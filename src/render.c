/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/11 13:39:00 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../mlx_linux/mlx.h"

int in_int_arr(int *arr, size_t size, int to_find)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == to_find)
            return (1);
    }
    return (0);
}

int render_player(t_sys *data)
{
    int x;
    int y;
    int size;

    x = data->player_data->x;
    y = data->player_data->y;
    size = data->wall->width;
    //printf("%d", y);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player->texture, x * size, (y - 0.5) * size);
}

int	handle_render(t_sys *system)
{
	int 	y;
	int		x;
    int     size;
	t_map	*map;

	map = system->map;
	y = 0;
    size = system->wall->width;
    while (y < map->column_len)
    {
        x = 0;
        while (x < map->line_len)
	    {
            if (map->map[y * map->line_len + x] == WALL)
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->wall->texture, x * size, y * size);
            else if (map->map[y * map->line_len + x] == EXIT)
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->exit->texture, x * size, y * size);
            else if (map->map[y * map->line_len + x] == COLLECTIBLE)
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->collectible->texture, x * size, y * size);
            else
            {
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->floor->texture, x * size, y * size);
                render_player(system);
            }
            x++;
	    }
        y++;
    }
	return (0);
}
