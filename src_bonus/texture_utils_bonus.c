/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_utils_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: krijn <krijn@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:28:03 by krijn         #+#    #+#                 */
/*   Updated: 2023/11/15 16:54:27 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	update_pixels(char *odata, char *udata, \
							int new_width, int new_height)
{
	int	x;
	int	y;
	int	original_offset;
	int	upscaled_offset;
	int	factor;

	y = 0;
	factor = TEXTURE_FACTOR;
	while (y < new_height)
	{
		x = 0;
		while (x < new_width)
		{
			original_offset = ((y / factor) * \
								(new_width / factor) + (x / factor)) * 4;
			upscaled_offset = (y * new_width + x) * 4;
			udata[upscaled_offset] = odata[original_offset];
			udata[upscaled_offset + 1] = odata[original_offset + 1];
			udata[upscaled_offset + 2] = odata[original_offset + 2];
			udata[upscaled_offset + 3] = odata[original_offset + 3];
			udata[upscaled_offset + 4] = odata[original_offset + 4];
			x++;
		}
		y++;
	}
}

static char	*get_char_img_data(void *texture)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;

	data = mlx_get_data_addr(texture, &bits_per_pixel, &size_line, &endian);
	return (data);
}

void	upscale_img(t_sys *data, t_img *img)
{
	int		new_width;
	int		new_height;
	void	*new_texture;
	char	*odata;
	char	*udata;

	new_width = img->width * TEXTURE_FACTOR;
	new_height = img->height * TEXTURE_FACTOR;
	new_texture = mlx_new_image(data->mlx_ptr, new_width, new_height);
	if (new_texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	odata = get_char_img_data(img->texture);
	udata = get_char_img_data(new_texture);
	if (odata == NULL || udata == NULL)
	{
		mlx_destroy_image(data->mlx_ptr, new_texture);
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	}
	update_pixels(odata, udata, new_width, new_height);
	mlx_destroy_image(data->mlx_ptr, img->texture);
	img->texture = new_texture;
	img->width = new_width;
	img->height = new_height;
}

char	*build_path(char *folder, char *file, char *extention)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(folder, file);
	path = ft_strjoin(temp, extention);
	free(temp);
	return (path);
}

int	count_textures(char *path)
{
	int		fd;
	int		count;
	char	*nbr;
	char	*file;

	count = 0;
	nbr = ft_itoa(count);
	file = build_path(path, nbr, ".xpm");
	fd = open(file, O_RDONLY);
	free(file);
	free(nbr);
	while (fd != -1)
	{
		count++;
		nbr = ft_itoa(count);
		file = build_path(path, nbr, ".xpm");
		close(fd);
		fd = open(file, O_RDONLY);
		free(file);
		free(nbr);
	}
	return (count);
}
