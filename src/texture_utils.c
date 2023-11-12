/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krijn <krijn@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:28:03 by krijn         #+#    #+#                 */
/*   Updated: 2023/11/12 11:49:09 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/texture.h"
#include "../include/error.h"
#include "../mlx_linux/mlx.h"

static void	update_pixels(char *original_data, char *upscaled_data, int new_width, int new_height, int factor)
{
	int	x;
	int	y;
	int original_offset;
	int upscaled_offset;

	y = 0;
	while (y < new_height)
	{
		x = 0;
		while (x < new_width)
		{
			original_offset = ((y / factor) * (new_width / factor) + (x / factor)) * 4;
			upscaled_offset = (y * new_width + x) * 4;
			upscaled_data[upscaled_offset] = original_data[original_offset];
			upscaled_data[upscaled_offset + 1] = original_data[original_offset + 1];
			upscaled_data[upscaled_offset + 2] = original_data[original_offset + 2];
			upscaled_data[upscaled_offset + 3] = original_data[original_offset + 3];
			upscaled_data[upscaled_offset + 4] = original_data[original_offset + 4];
			x++;
		}
		y++;
	}
}

static char	*get_char_img_data(void *texture)
{
	int	    bits_per_pixel;
	int	    size_line;
	int     endian;
	char	*data;

	data = mlx_get_data_addr(texture, &bits_per_pixel, &size_line, &endian);
	return (data);
}

unsigned int	*get_ui_img_data(void *texture)
{
	int	    		bits_per_pixel;
	int	    		size_line;
	int     		endian;
	unsigned int	*data;

	data = (unsigned int *)mlx_get_data_addr(texture, &bits_per_pixel, &size_line, &endian);
	return (data);
}

void	upscale_img(t_sys *data, t_img *img, int factor)
{
	int		new_width;
	int		new_height;
	void	*new_texture;
	char	*original_data;
	char	*upscaled_data;

	new_width = img->width * factor;
	new_height = img->height * factor;
	new_texture = mlx_new_image(data->mlx_ptr, new_width, new_height);
	if (new_texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	original_data = get_char_img_data(img->texture);
	upscaled_data = get_char_img_data(new_texture);
    if (original_data == NULL || upscaled_data == NULL)
    {
        mlx_destroy_image(data->mlx_ptr, new_texture);
        system_error(data, ERR_SYS_MALLOC_FAILURE);
    }
	update_pixels(original_data, upscaled_data, new_width, new_height, factor);
	mlx_destroy_image(data->mlx_ptr, img->texture);
	img->texture = new_texture;
	img->width = new_width;
	img->height = new_height;
}

// TODO: make own renderfunction that only prints non transparent pixels
void	update_transparency(t_sys *data, t_img *img)
{
	unsigned int	*img_data;
	int				i;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	img_data = get_ui_img_data(img->texture);
	i = 0;
	while (i < img->width * img->height)
	{
		color = img_data[i];
		r = (color >> 16) & 0xFF;
		g = (color >> 8) & 0xFF;
		b = color & 0xFF;
		if (r == 0 && g == 0 && b == 0)
			img_data[i] &= 0x00FFFFFF;
		i++;
	}
}
