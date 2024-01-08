/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 14:59:46 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 15:48:52 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include <fcntl.h>

void	draw_player(t_sys *data, t_img *buf)
{
	int	x;
	int	y;
	int	size;

	x = data->player_data->x;
	y = data->player_data->y;
	size = data->player->width;
	put_img_to_img(buf, data->player, x * size, (y - 0.5) * size);
}

void	init_player(t_sys *data)
{
	data->player_data = (t_player *)malloc(sizeof(t_player));
	if (data->player_data == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_data->x = data->map->start_index % data->map->line_len;
	data->player_data->y = data->map->start_index / data->map->line_len;
	data->player_data->step_count = 0;
}

void	move_player(t_sys *data, int x, int y)
{
	t_lst	*node;
	int		px;
	int		py;

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
}

char	*build_path(char *folder, char *file, char *extention)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(folder, file);
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, extention);
	free(temp);
	return (path);
}

int	count_textures(char *path)
{
	int		fd;
	int		count;
	char	*nbr;
	char	*file;

	count = 0;
	nbr = ft_itoa(count);
	file = build_path(path, nbr, ".xpm");
	fd = open(file, O_RDONLY);
	free(file);
	free(nbr);
	while (fd != -1)
	{
		count++;
		nbr = ft_itoa(count);
		file = build_path(path, nbr, ".xpm");
		close(fd);
		fd = open(file, O_RDONLY);
		free(file);
		free(nbr);
	}
	return (count);
}

void	load_player(t_sys *data)
{
	char	*path;
	
	data->player = (t_anim *)malloc(sizeof(t_anim));
}
