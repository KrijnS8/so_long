/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_utils_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/14 12:24:07 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/17 12:51:48 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/render_bonus.h"

unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + \
							(y * img->size_line) + (x * img->bpp / 8))));
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	unsigned int	*dst;

	if (color == (int)0x00000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < src->height)
	{
		dx = 0;
		while (dx < src->width)
		{
			put_pixel_to_img(dst, x + dx, y + dy, get_pixel_color(src, dx, dy));
			dx++;
		}
		dy++;
	}
}
