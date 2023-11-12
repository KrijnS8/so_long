/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 14:53:13 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../include/texture.h"
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

int transparent_render(t_sys *data, t_img *img, int x, int y)
{
    unsigned int    *img_data;
    int             img_x;
    int             img_y;
    unsigned int    pixel;

    img_data = get_ui_img_data(img->texture);
    img_x = 0;
    img_y = 0;
    pixel = 0;
    while (img_y < img->height)
    {
        while (img_x < img->width)
        {
            pixel = img_data[img_y * img->width + img_x];
            if (pixel == 0x00000000)
            {
                img_x++;
                continue ;
            }
            printf("Printing pixel at x:%d y:%d\n", x + img_x, y + img_y);
            mlx_pixel_put(data->mlx_ptr, data->mlx_win, x + img_x, y + img_y, pixel);
            img_x++;
        }
        img_y++;
    }
}

int render_player(t_sys *data)
{
    int x;
    int y;
    int size;

    x = data->player_data->x;
    y = data->player_data->y;
    size = data->wall->width;
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
            }
            render_player(system);
            x++;
	    }
        y++;
    }
	return (0);
}
