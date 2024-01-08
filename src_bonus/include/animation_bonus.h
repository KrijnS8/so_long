/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:56:06 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 15:21:53 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

typedef struct s_img	t_img;

typedef struct s_anim
{
	t_img	**textures;
	int		length;
}	t_anim;

#endif
