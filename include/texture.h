/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 12:40:13 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "system.h"
# ifndef TEXTURE_FACTOR
#  define TEXTURE_FACTOR 4
# endif

void			load_textures(t_sys *data);
void			destroy_textures(t_sys *data);
void			upscale_img(t_sys *data, t_img *img);

#endif