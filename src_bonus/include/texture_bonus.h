/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 15:31:15 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# ifndef TEXTURE_FACTOR
#  define TEXTURE_FACTOR 4
# endif

# include "system_bonus.h"

void			load_textures(t_sys *data);
void			destroy_textures(t_sys *data);
void			upscale_img(t_sys *data, t_img *img);

#endif