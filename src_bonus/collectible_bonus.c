/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:26:50 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/17 15:09:53 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include <stdlib.h>

t_collectible	*new_collectible(int x, int y)
{
	t_collectible	*new;

	new = (t_collectible *)malloc(sizeof(t_collectible));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->opened = 0;
	new->anim = NULL;
	return (new);
}

t_lst	*is_on_collectible(t_sys *data)
{
	t_player		*p_ptr;
	t_lst			*l_ptr;
	t_collectible	*c_ptr;

	p_ptr = data->player_data;
	l_ptr = data->map->coll_lst;
	while (l_ptr != NULL)
	{
		c_ptr = (t_collectible *)l_ptr->content;
		if (p_ptr->x == c_ptr->x && p_ptr->y == c_ptr->y)
			return (l_ptr);
		l_ptr = l_ptr->next;
	}
	return (NULL);
}

void	free_collectible(void *ptr)
{
	t_collectible	*coll;

	coll = (t_collectible *)ptr;
	if (coll->anim != NULL)
		free(coll->anim);
	if (coll != NULL)
		free(coll);
}

void	start_collectible_anim(t_sys *data, t_collectible *coll)
{
	coll->opened = 1;
	coll->anim = (t_anim *)malloc(sizeof(t_anim));
	if (coll->anim == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	coll->anim->current_frame = 0;
	coll->anim->frame_count = data->collectible->size;
	coll->anim->ticks_to_next = ANIMATION_TICK_RATE;
}

void	update_collectible_anim(t_sys *data)
{
	t_lst			*node;
	t_lst			*next_node;
	t_collectible	*content;

	node = data->map->coll_lst;
	while (node != NULL)
	{
		content = (t_collectible *)node->content;
		if (content->anim == NULL)
		{
			node = node->next;
			continue ;
		}
		if (content->anim->ticks_to_next == 0)
		{
			if (content->anim->current_frame < content->anim->frame_count - 1)
			{
				content->anim->current_frame++;
				content->anim->ticks_to_next = ANIMATION_TICK_RATE;
			}
			else
			{
				next_node = node->next;
				//lst_del_node(&data->map->coll_lst, node, free_collectible);
				node = next_node;
				continue ;
			}
		}
		else
			content->anim->ticks_to_next--;
		node = node->next;
	}
}
