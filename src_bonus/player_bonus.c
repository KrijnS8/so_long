/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:54:54 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 16:10:21 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"

void	init_player(t_sys *data)
{
	data->player_data = (t_player *)malloc(sizeof(t_player));
	if (data->player_data == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_data->x = data->map->start_index % data->map->line_len;
	data->player_data->y = data->map->start_index / data->map->line_len;
	data->player_data->step_count = 0;
	data->player_data->anim = (t_anim *)malloc(sizeof(t_anim));
	if (data->player_data->anim == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_data->state = PLAYER_STATE_IDLE;	
	data->player_data->rotation = 1;
	data->player_data->anim->current_frame = 0;
	data->player_data->anim->frame_count = 4;
	data->player_data->anim->ticks_to_next = ANIMATION_TICK_RATE;
}

void	move_player(t_sys *data, int x, int y)
{
	t_lst	*node;
	int		px;
	int		py;

	if (x > 0 && data->player_data->rotation == -1 || x < 0 && data->player_data->rotation == 1)
	{
		data->player_data->rotation *= -1;
		return ;
	}
	px = data->player_data->x + x;
	py = data->player_data->y + y;
	if (data->map->map[py * data->map->line_len + px] != WALL)
	{
		data->player_data->x += x;
		data->player_data->y += y;
		data->player_data->step_count++;
		ft_printf("Move count: %d\n", data->player_data->step_count);
	}
	node = is_on_collectible(data);
	if (node != NULL)
	{
		lst_del_node(&data->map->coll_lst, node, free_collectible);
		data->map->coll_count--;
	}
	if (data->map->map[py * data->map->line_len + px] == EXIT)
	{
		if (data->map->coll_lst == NULL)
			destroy_system(data);
	}
	if (x > 0)
		data->player_data->rotation = 1;
	if (x < 0)
		data->player_data->rotation = -1;
}

void	update_player_anim(t_sys *data, t_player_state state)
{
	t_player	*p_data;

	p_data = data->player_data;
	if (state == p_data->state)
	{
		if (p_data->anim->ticks_to_next == 0)
		{
			if (p_data->anim->current_frame == p_data->anim->frame_count - 1)
				p_data->anim->current_frame = 0;
			else
				p_data->anim->current_frame++;
			p_data->anim->ticks_to_next = ANIMATION_TICK_RATE;
			return ;
		}
		p_data->anim->ticks_to_next--;
		return ;
	}
	p_data->state = state;
	p_data->anim->current_frame = 0;
	p_data->anim->frame_count = 4;
	p_data->anim->ticks_to_next = ANIMATION_TICK_RATE;
}
