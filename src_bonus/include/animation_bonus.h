/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:56:06 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 17:59:16 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H
# define ANIMATION_RATE 0.17

# include "system_bonus.h"

typedef struct s_anim
{
	t_img	**textures;
	int		length;
	double	last_tick;
	int		loop;
}	t_anim;

void	destroy_anim(t_sys *data, t_anim *anim);
void	update_anim(t_anim *anim, int *index);

#endif
