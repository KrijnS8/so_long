/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 12:24:19 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 13:12:24 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"

void	load_frame_buffer(t_sys *data)
{
	data->frame_buf = (t_img *)malloc(sizeof(t_img));
	if (data->frame_buf == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->frame_buf->width = data->map->line_len * (16 * TEXTURE_FACTOR);
	data->frame_buf->height = data->map->column_len * (16 * TEXTURE_FACTOR);
	data->frame_buf->texture = mlx_new_image(data->mlx_ptr, \
							data->frame_buf->width, data->frame_buf->height);
	if (data->frame_buf->texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->frame_buf->addr = mlx_get_data_addr(data->frame_buf->texture, \
						&data->frame_buf->bpp, &data->frame_buf->size_line, \
						&data->frame_buf->endian);
}

void	destroy_frame_buffer(t_sys *data)
{
	if (data->frame_buf == NULL)
		return ;
	if (data->frame_buf->texture != NULL)
		mlx_destroy_image(data->mlx_ptr, data->frame_buf->texture);
	free(data->frame_buf);
}

void	move_player(t_sys *data, int x, int y)
{
	t_lst	*node;
	int		px;
	int		py;

	px = data->player_data->x + x;
	py = data->player_data->y + y;
	if (data->map->map[py * data->map->line_len + px] != WALL)
	{
		data->player_data->x += x;
		data->player_data->y += y;
		data->player_data->step_count++;
		ft_printf("Move count: %d\n", data->player_data->step_count);
	}
	node = is_on_collectible(data);
	if (node != NULL)
	{
		lst_del_node(&data->map->coll_lst, node, free_collectible);
		data->map->coll_count--;
	}
	if (data->map->map[py * data->map->line_len + px] == EXIT)
	{
		if (data->map->coll_lst == NULL)
			destroy_system(data);
	}
}
