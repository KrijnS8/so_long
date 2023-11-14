/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 12:50:13 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../include/texture.h"
#include "../include/collectible.h"
#include "../mlx_linux/mlx.h"

void	render_background(t_sys *data, t_img *buf)
{
	int		y;
	int		x;
	int		size;
	t_map	*map;

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

void	draw_background(t_sys *data, t_img *buf)
{
	put_img_to_img(buf, data->bg, 0, 0);
}

void	draw_objectives(t_sys *data, t_img *buf)
{
	int				x;
	int				y;
	t_lst			*ptr;
	t_collectible	*content;
	int				size;

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

void	draw_player(t_sys *data, t_img *buf)
{
	int	x;
	int	y;
	int	size;

	x = data->player_data->x;
	y = data->player_data->y;
	size = data->player->width;
	put_img_to_img(buf, data->player, x * size, (y - 0.5) * size);
}

// TODO: animation struct in linked list that updates every frame
int	handle_render(t_sys *data)
{
	t_img	*buf;

	buf = data->frame_buf;
	draw_background(data, buf);
	draw_objectives(data, buf);
	draw_player(data, buf);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, buf->texture, 0, 0);
	return (1);
}
