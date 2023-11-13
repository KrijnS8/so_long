/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 12:24:19 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 13:16:30 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/system.h"
#include "../include/texture.h"
#include "../mlx_linux/mlx.h"

void	load_frame_buffer(t_sys *data)
{
    data->frame_buf = (t_img *)malloc(sizeof(t_img));
    if (data->frame_buf == NULL)
        system_error(data, ERR_SYS_MALLOC_FAILURE);
    data->frame_buf->width = data->map->line_len * (16 * TEXTURE_FACTOR);
    data->frame_buf->height = data->map->column_len * (16 * TEXTURE_FACTOR);
    data->frame_buf->texture = mlx_new_image(data->mlx_ptr, data->frame_buf->width, data->frame_buf->height);
    if (data->frame_buf->texture == NULL)
        system_error(data, ERR_SYS_MALLOC_FAILURE);
    data->frame_buf->addr = mlx_get_data_addr(data->frame_buf->texture, &data->frame_buf->bpp, &data->frame_buf->size_line, &data->frame_buf->endian);
}

void	destroy_frame_buffer(t_sys *data)
{
	if (data->frame_buf == NULL)
		return ;
	if (data->frame_buf->texture != NULL)
		mlx_destroy_image(data->mlx_ptr, data->frame_buf->texture);
	free(data->frame_buf);
}
