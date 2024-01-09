/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 16:07:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 13:15:31 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include <time.h>
#include <stdio.h>

void	destroy_anim(t_sys *data, t_anim *anim)
{
	int	i;

	if (!anim)
		return ;
	if (anim->textures)
	{
		i = 0;
		while (i < anim->length)
		{
			free_img(data, anim->textures[i]);
			i++;
		}
	}
	free(anim->textures);
	free(anim);
}

void	update_anim(t_anim *anim, int *index, double *last_tick)
{
	struct timespec	tv;
	double			current_time;

	if (*index == anim->length - 1 && anim->loop == 0)
		return ;
	clock_gettime(CLOCK_MONOTONIC, &tv);
	current_time = (double)tv.tv_sec + (double)tv.tv_nsec / 1000000000;
	if (current_time - *last_tick < ANIMATION_RATE)
		return ;
	*last_tick = current_time;
	if (++(*index) == anim->length)
		*index = 0;
}
