/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:18 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/10 13:34:30 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/texture.h"
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
}

void	load_textures(t_sys *data)
{
	data->player = create_img(data, "resources/player.xpm");
	data->collectible = create_img(data, "resources/collectible.xpm");
	data->floor = create_img(data, "resources/floor.xpm");
	data->wall = create_img(data, "resources/wall.xpm");
	data->exit = create_img(data, "resources/exit.xpm");
}
