/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/10 11:29:47 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "system.h"

void	load_textures(t_sys *data);
void	destroy_textures(t_sys *data);
void	upscale_img(t_sys *data, t_img *img, int factor);

#endif