/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_utils_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 17:38:40 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:14:50 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"

int	is_on_exit(t_sys *data)
{
	int	x;
	int	y;

	x = data->player_data->x;
	y = data->player_data->y;
	return (data->map->map[y * data->map->line_len + x] == EXIT);
}

void	check_collision(t_sys *data)
{
	t_lst	*node;

	node = is_on_collectible(data);
	if (node != NULL && ((t_collectible *)(node->content))->collected == 0)
	{
		((t_collectible *)(node->content))->collected = 1;
		data->map->coll_count--;
	}
	if (is_on_foe(data))
	{
		ft_printf("%sYou Lose!%s\n", RED, RESET);
		destroy_system(data);
	}
	if (is_on_exit(data))
	{
		if (data->map->coll_count == 0)
		{
			ft_printf("%sSuccess in %d steps%s\n", GREEN, \
						data->player_data->step_count, RESET);
			destroy_system(data);
		}
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
