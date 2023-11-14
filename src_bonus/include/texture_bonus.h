/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 15:56:57 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H
# include "system_bonus.h"
# ifndef TEXTURE_FACTOR
#  define TEXTURE_FACTOR 4
# endif

void			load_textures(t_sys *data);
void			destroy_textures(t_sys *data);
void			upscale_img(t_sys *data, t_img *img);

#endif
