/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_utils_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: krijn <krijn@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:28:03 by krijn         #+#    #+#                 */
/*   Updated: 2024/01/08 17:56:09 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

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

static void	reverse_copy(t_img *dst, t_img *src)
{
	char	*odata;
	char	*rdata;
	int		y;
	int		x;
	int		j;

	odata = (char *)src->addr;
	rdata = (char *)dst->addr;
	y = 0;
	while (y < dst->height)
	{
		x = 0;
		while (x < dst->width * (src->bpp / 8))
		{
			j = 0;
			while (j < src->bpp / 8)
			{
				rdata[(y * dst->size_line + (dst->width - 1) * (src->bpp / 8)) \
						- x + j] = odata[y * src->size_line + x + j];
				j++;
			}
			x += src->bpp / 8;
		}
		y++;
	}
}

t_img	*reverse_img(t_sys *data, t_img *img)
{
	t_img	*new_img;

	new_img = (t_img *)malloc(sizeof(t_img));
	if (new_img == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	new_img->texture = mlx_new_image(data->mlx_ptr, img->width, img->height);
	new_img->width = img->width;
	new_img->height = img->height;
	new_img->addr = mlx_get_data_addr(new_img->texture, &new_img->bpp, \
								&new_img->size_line, &new_img->endian);
	reverse_copy(new_img, img);
	return (new_img);
}
