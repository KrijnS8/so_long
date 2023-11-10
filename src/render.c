/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/10 13:10:42 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../mlx_linux/mlx.h"

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
            if (map->map[y * map->line_len + x] == '1')
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->wall->texture, x * size, y * size);
            else
                mlx_put_image_to_window(system->mlx_ptr, system->mlx_win, system->floor->texture, x * size, y * size);
            x++;
	    }
        y++;
    }
	return (0);
}
