/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 16:07:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:31:13 by kschelvi      ########   odam.nl         */
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
	if (anim->textures)
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

static int	init_anim(t_anim **anim)
{
	*anim = (t_anim *)malloc(sizeof(t_anim));
	if (!*anim)
		return (0);
	(*anim)->length = 0;
	(*anim)->loop = 0;
	(*anim)->textures = NULL;
	return (1);
}

void	load_anim(t_sys *data, t_anim **anim, char *path, int loop)
{
	char	*img_path;
	char	*nbr;
	int		i;

	if (!init_anim(anim))
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	(*anim)->length = count_textures(path);
	if ((*anim)->length < 1)
		system_error(data, ERR_IMG_TEXTURE_FAILURE);
	(*anim)->textures = \
		(t_img **)malloc((*anim)->length * sizeof(t_img *));
	if (!(*anim)->textures)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < (*anim)->length)
	{
		nbr = ft_itoa(i);
		img_path = ft_build_path(path, nbr, ".xpm");
		free(nbr);
		(*anim)->textures[i] = create_img(data, img_path);
		free(img_path);
		i++;
	}
	(*anim)->loop = loop;
}
