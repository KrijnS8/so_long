/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:59:46 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 17:52:05 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"

void	draw_player(t_sys *data, t_img *buf)
{
	t_img	*img;
	int		x;
	int		y;
	int		size;

	update_anim(data->player, &data->player_data->anim_index);
	if (data->player_data->reverse == 0)
		img = data->player->textures[data->player_data->anim_index];
	else
		img = data->player_rev->textures[data->player_data->anim_index];
	x = data->player_data->x;
	y = data->player_data->y;
	size = data->player->textures[0]->width;
	put_img_to_img(buf, img, x * size, (y - 0.5) * size);
}

void	init_player(t_sys *data)
{
	data->player_data = (t_player *)malloc(sizeof(t_player));
	if (data->player_data == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_data->x = data->map->start_index % data->map->line_len;
	data->player_data->y = data->map->start_index / data->map->line_len;
	data->player_data->step_count = 0;
	data->player_data->anim_index = 0;
	data->player_data->reverse = 0;
}

static int	update_rotation(t_sys *data, int x)
{
	if (data->player_data->reverse == 0 && x < 0)
	{
		data->player_data->reverse = 1;
		return (1);
	}
	if (data->player_data->reverse == 1 && x > 0)
	{
		data->player_data->reverse = 0;
		return (1);
	}
	return (0);
}

void	move_player(t_sys *data, int x, int y)
{
	int		px;
	int		py;

	if (update_rotation(data, x))
		return ;
	px = data->player_data->x + x;
	py = data->player_data->y + y;
	if (data->map->map[py * data->map->line_len + px] != WALL)
	{
		data->player_data->x += x;
		data->player_data->y += y;
		data->player_data->step_count++;
		ft_printf("Move count: %d\n", data->player_data->step_count);
	}
	check_collision(data);
}

void	load_player(t_sys *data)
{
	char	*path;
	char	*nbr;
	int		i;

	data->player = (t_anim *)malloc(sizeof(t_anim));
	if (!data->player)
		system_error(data, ERR_IMG_TEXTURE_FAILURE);
	data->player->length = count_textures("./src_bonus/resources/player/idle/");
	data->player->textures = \
		(t_img **)malloc(data->player->length * sizeof(t_img *));
	if (!data->player->textures)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player->length)
	{
		nbr = ft_itoa(i);
		path = ft_build_path("src_bonus/resources/player/idle/", nbr, ".xpm");
		free(nbr);
		data->player->textures[i] = create_img(data, path);
		free(path);
		i++;
	}
	data->player->last_tick = 0;
	load_player_rev(data);
}
