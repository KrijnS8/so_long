/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:18 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 19:41:30 by krijn         ########   odam.nl         */
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
	upscale_img(data, img, TEXTURE_FACTOR);
	img->addr = mlx_get_data_addr(img->texture, &img->bpp, &img->size_line, &img->endian);
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
	free_img(data, data->background);
}

void	load_textures(t_sys *data)
{
	data->player = create_img(data, "resources/xpm/player.xpm");
	data->collectible = create_img(data, "resources/xpm/collectible.xpm");
	data->floor = create_img(data, "resources/xpm/floor.xpm");
	data->wall = create_img(data, "resources/xpm/wall.xpm");
	data->exit = create_img(data, "resources/xpm/exit.xpm");
	data->background = (t_img *)malloc(sizeof(t_img));
	if (data->background == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->background->width = data->map->line_len * (16 * TEXTURE_FACTOR);
    data->background->height = data->map->column_len * (16 * TEXTURE_FACTOR);
	data->background->texture = mlx_new_image(data->mlx_ptr, data->background->width, data->background->height);
	if (data->background->texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->background->addr = mlx_get_data_addr(data->background->texture, &data->background->bpp, \
												&data->background->size_line, &data->background->endian);
	//printf("%s\n", (char *)data->background->addr);
	render_background(data, data->background);
}
