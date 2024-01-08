/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:41:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 18:00:39 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "system_bonus.h"

int				handle_render(t_sys *system);
void			render_background(t_sys *data, t_img *buf);
unsigned int	get_pixel_color(t_img *img, int x, int y);
void			put_pixel_to_img(t_img *img, int x, int y, int color);
void			put_img_to_img(t_img *dst, t_img *src, int x, int y);

#endif