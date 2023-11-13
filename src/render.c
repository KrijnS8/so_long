/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 14:45:46 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../include/texture.h"
#include "../include/collectible.h"
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
	int 			x;
	int 			y;
	t_lst			*ptr;
	t_collectible	*content;
	int 			size;
	
	size = data->collectible->width;
	ptr = data->map->coll_lst;
	while (ptr != NULL)
	{
		content = (t_collectible *)ptr->content;
		x = content->x;
		y = content->y;
		put_img_to_img(buf, data->collectible, x * size, y * size);
		ptr = ptr->next;
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

	buf = data->frame_buf;
	draw_background(data, buf);
	draw_objectives(data, buf);
	draw_player(data, buf);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, buf->texture, 0, 0);
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
