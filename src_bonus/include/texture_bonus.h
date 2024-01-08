/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 18:00:57 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H
# ifndef TEXTURE_FACTOR
#  define TEXTURE_FACTOR 4
# endif

# include "system_bonus.h"

t_img			*create_img(t_sys *data, char *path);
void			free_img(t_sys *data, t_img *img);
void			load_textures(t_sys *data);
void			destroy_textures(t_sys *data);
void			upscale_img(t_sys *data, t_img *img);
t_img			*reverse_img(t_sys *data, t_img *img);
int				count_textures(char *path);

#endif