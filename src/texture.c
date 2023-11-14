/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:18 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 12:39:12 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/texture.h"
#include "../include/render.h"
#include "../include/error.h"
#include "../mlx_linux/mlx.h"

t_img	*create_img(t_sys *data, char *path)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	img->texture = mlx_xpm_file_to_image(data->mlx_ptr, path, \
										&img->width, &img->height);
	if (img->texture == NULL)
	{
		free(img);
		system_error(data, ERR_IMG_TEXTURE_FAILURE);
	}
	upscale_img(data, img);
	img->addr = mlx_get_data_addr(img->texture, &img->bpp, \
									&img->size_line, &img->endian);
	return (img);
}

void	free_img(t_sys *data, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->texture != NULL)
		mlx_destroy_image(data->mlx_ptr, img->texture);
	free(img);
}

void	destroy_textures(t_sys *data)
{
	free_img(data, data->player);
	free_img(data, data->collectible);
	free_img(data, data->floor);
	free_img(data, data->wall);
	free_img(data, data->exit);
	free_img(data, data->bg);
}

void	load_textures(t_sys *data)
{
	data->player = create_img(data, "resources/xpm/player.xpm");
	data->collectible = create_img(data, "resources/xpm/collectible.xpm");
	data->floor = create_img(data, "resources/xpm/floor.xpm");
	data->wall = create_img(data, "resources/xpm/wall.xpm");
	data->exit = create_img(data, "resources/xpm/exit.xpm");
	data->bg = (t_img *)malloc(sizeof(t_img));
	if (data->bg == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->bg->width = data->map->line_len * (16 * TEXTURE_FACTOR);
	data->bg->height = data->map->column_len * (16 * TEXTURE_FACTOR);
	data->bg->texture = mlx_new_image(data->mlx_ptr, \
											data->bg->width, \
											data->bg->height);
	if (data->bg->texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->bg->addr = mlx_get_data_addr(data->bg->texture, &data->bg->bpp, \
									&data->bg->size_line, &data->bg->endian);
	render_background(data, data->bg);
}
