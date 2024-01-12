/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:19:17 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

void	render_background(t_sys *data, t_img *buf)
{
	int		y;
	int		x;
	int		size;
	t_map	*map;

	map = data->map;
	y = 0;
	size = data->wall->width;
	while (y < (int)map->column_len)
	{
		x = 0;
		while (x < (int)map->line_len)
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

void	draw_background(t_sys *data, t_img *buf)
{
	put_img_to_img(buf, data->bg, 0, 0);
}

int	handle_render(t_sys *data)
{
	t_img	*buf;

	buf = data->frame_buf;
	draw_background(data, buf);
	draw_collectibles(data, buf);
	draw_foe(data, buf);
	draw_player(data, buf);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, buf->texture, 0, 0);
	return (1);
}
