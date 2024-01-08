/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_utils_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 17:38:40 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 17:58:46 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"

void	check_collision(t_sys *data)
{
	t_lst	*node;
	int		x;
	int		y;

	node = is_on_collectible(data);
	if (node != NULL)
	{
		lst_del_node(&data->map->coll_lst, node, free_collectible);
		data->map->coll_count--;
	}
	x = data->player_data->x;
	y = data->player_data->y;
	if (data->map->map[y * data->map->line_len + x] == EXIT)
	{
		if (data->map->coll_lst == NULL)
			destroy_system(data);
	}
}

void	load_player_rev(t_sys *data)
{
	int	i;

	data->player_rev = (t_anim *)malloc(sizeof(t_anim));
	if (!data->player_rev)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_rev->length = data->player->length;
	data->player_rev->textures = (t_img **)malloc(data->player_rev->length * \
													sizeof(t_img *));
	if (!data->player_rev->textures)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player_rev->length)
	{
		data->player_rev->textures[i] = reverse_img(data, \
											data->player->textures[i]);
		i++;
	}
}