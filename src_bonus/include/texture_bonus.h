/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 15:25:44 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H
# include "system_bonus.h"
# ifndef TEXTURE_FACTOR
#  define TEXTURE_FACTOR 4
# endif

void	load_textures(t_sys *data);
void	destroy_textures(t_sys *data);
void	upscale_img(t_sys *data, t_img *img);
int		count_textures(char *path);
char	*build_path(char *folder, char *file, char *extention);
t_img	*reverse_img(t_sys *data, t_img *img);

#endif
