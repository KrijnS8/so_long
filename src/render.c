/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 20:39:18 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../include/texture.h"
#include "../mlx_linux/mlx.h"

/* int transparent_render(t_sys *data, t_img *img, int x, int y)
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
} */

unsigned int    get_pixel_color(t_img *img, int x, int y)
{
    // unsigned int *data = (unsigned int *)img->addr;
    return (*(unsigned int *)((img->addr + (y * img->size_line) + (x * img->bpp / 8))));
}

void    put_pixel_to_img(t_img *img, int x, int y, int color)
{
    unsigned int    *dst;

    if (color == (int)0x00000000)
		return ;

    if (x >= 0 && y >= 0 && x < img->width && y < img->height)
    {
        dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void    put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
    int dy;
    int dx;

    dy = 0;
    while(dy < src->height)
    {
        dx = 0;
        while (dx < src->width)
        {
            put_pixel_to_img(dst, x + dx, y + dy, get_pixel_color(src, dx, dy));
            dx++;
        }
        dy++;
    }
}

void    render_background(t_sys *data, t_img *buf)
{
    int     y;
    int     x;
    int     size;
    t_map   *map;
    
    map = data->map;
    y = 0;
    size = data->wall->width;
    while (y < map->column_len)
    {
        x = 0;
        while (x < map->line_len)
        {
            if (map->map[y * map->line_len + x] == WALL)
                put_img_to_img(buf, data->wall, x * size, y * size);
            else if (map->map[y * map->line_len + x] == EXIT)
                put_img_to_img(buf, data->exit, x * size, y * size);
            else
                put_img_to_img(buf, data->floor, x * size, y * size);
            x++;
        }
        y++;
    }
}

void    draw_background(t_sys *data, t_img *buf)
{
    put_img_to_img(buf, data->background, 0, 0);
}

void    draw_objectives(t_sys *data, t_img *buf)
{
    int x;
    int y;
    int i;
    int size;
    
    size = data->collectible->width;
    i = 0;
    while (i < data->map->coll_count)
    {
        x = data->map->coll_arr[i] % data->map->line_len;
        y = data->map->coll_arr[i] / data->map->line_len;
        put_img_to_img(buf, data->collectible, x * size, y * size);
        i++;
    }
}

void    draw_player(t_sys *data, t_img *buf)
{
    int x;
    int y;
    int size;

    x = data->player_data->x;
    y = data->player_data->y;
    size = data->player->width;
    put_img_to_img(buf, data->player, x * size, (y - 0.5) * size);
}

// TODO: animation struct in linked list that updates every frame
int handle_render(t_sys *data)
{
    t_img   *buf;

    buf = (t_img *)malloc(sizeof(t_img));
    if (buf == NULL)
        system_error(data, ERR_SYS_MALLOC_FAILURE);
    buf->width = data->map->line_len * (16 * TEXTURE_FACTOR);
    buf->height = data->map->column_len * (16 * TEXTURE_FACTOR);
    buf->texture = mlx_new_image(data->mlx_ptr, buf->width, buf->height);
    if (buf->texture == NULL)
        system_error(data, ERR_SYS_MALLOC_FAILURE);
    buf->addr = mlx_get_data_addr(buf->texture, &buf->bpp, &buf->size_line, &buf->endian);
    draw_background(data, buf);
    //mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background->texture, 0, 0);
    draw_objectives(data, buf);
    draw_player(data, buf);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, buf->texture, 0, 0);
    mlx_destroy_image(data->mlx_ptr, buf->texture);
    free(buf);
}

/* int	handle_render(t_sys *system)
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
} */
