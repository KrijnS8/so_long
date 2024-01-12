/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   foe_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 14:16:08 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:06:02 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include <stdlib.h>

void	draw_foe(t_sys *data, t_img *buf)
{
	t_lst	*ptr;
	t_foe	*content;
	int		x;
	int		y;
	int		size;

	ptr = data->map->foe_lst;
	while (ptr != NULL)
	{
		content = (t_foe *)ptr->content;
		x = content->x;
		y = content->y;
		update_anim(data->foe, &content->anim_index, &content->last_tick);
		size = data->foe->textures[content->anim_index]->width;
		put_img_to_img(buf, data->foe->textures[content->anim_index], \
						x * size, (y - 0.5) * size);
		ptr = ptr->next;
	}
}

t_foe	*new_foe(int x, int y)
{
	t_foe	*new;

	new = (t_foe *)malloc(sizeof(t_foe));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->anim_index = 0;
	new->last_tick = 0;
	return (new);
}

void	free_foe(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

t_lst	*is_on_foe(t_sys *data)
{
	t_player	*p_ptr;
	t_lst		*l_ptr;
	t_foe		*f_ptr;

	p_ptr = data->player_data;
	l_ptr = data->map->foe_lst;
	while (l_ptr != NULL)
	{
		f_ptr = (t_foe *)l_ptr->content;
		if (p_ptr->x == f_ptr->x && p_ptr->y == f_ptr->y)
			return (l_ptr);
		l_ptr = l_ptr->next;
	}
	return (NULL);
}

void	load_foe(t_sys *data)
{
	load_anim(data, &data->foe, F_TEXTURE_PATH, 1);
}
