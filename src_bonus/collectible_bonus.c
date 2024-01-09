/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:26:50 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 13:25:18 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include <stdlib.h>

void	draw_collectibles(t_sys *data, t_img *buf)
{
	int				x;
	int				y;
	t_lst			*ptr;
	t_collectible	*content;
	int				size;

	size = data->collectible->textures[0]->width;
	ptr = data->map->coll_lst;
	while (ptr != NULL)
	{
		content = (t_collectible *)ptr->content;
		x = content->x;
		y = content->y;
		if (content->collected == 1)
			update_anim(data->collectible, &content->anim_index, \
							&content->last_tick);
		put_img_to_img(buf, data->collectible->textures[content->anim_index], \
						x * size, y * size);
		ptr = ptr->next;
	}
}

t_collectible	*new_collectible(int x, int y)
{
	t_collectible	*new;

	new = (t_collectible *)malloc(sizeof(t_collectible));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->collected = 0;
	new->anim_index = 0;
	new->last_tick = 0;
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
	if (ptr != NULL)
		free(ptr);
}

void	load_collectible(t_sys *data)
{
	char	*path;
	char	*nbr;
	int		i;

	data->collectible = (t_anim *)malloc(sizeof(t_anim));
	if (!data->collectible)
		system_error(data, ERR_IMG_TEXTURE_FAILURE);
	data->collectible->length = count_textures(C_TEXTURE_PATH);
	data->collectible->textures = \
		(t_img **)malloc(data->collectible->length * sizeof(t_img *));
	if (!data->collectible->textures)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->collectible->length)
	{
		nbr = ft_itoa(i);
		path = ft_build_path(C_TEXTURE_PATH, nbr, ".xpm");
		free(nbr);
		data->collectible->textures[i] = create_img(data, path);
		free(path);
		i++;
	}
	data->collectible->loop = 0;
}
