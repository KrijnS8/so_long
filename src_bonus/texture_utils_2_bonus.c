/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_utils_2_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 15:08:18 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 15:43:11 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

static void reverse_copy(t_img *dst, t_img *src)
{
    char	*odata = (char *)src->addr;
    char	*rdata = (char *)dst->addr;
	int		y;
	int		x;
	int		j;
	y = 0;
	while (y < dst->height)
	{
		x = 0;
		while (x < dst->width * (src->bpp / 8))
		{
			j = 0;
			while (j < src->bpp / 8)
			{
				rdata[(y * dst->size_line + (dst->width - 1) * (src->bpp / 8)) - x + j] = odata[y * src->size_line + x + j];
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
	new_img->addr = mlx_get_data_addr(new_img->texture, &new_img->bpp, &new_img->size_line, &new_img->endian);
	reverse_copy(new_img, img);
	return (new_img);
}
