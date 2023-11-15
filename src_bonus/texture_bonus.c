/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 17:29:18 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 16:53:32 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>

t_img	*create_img(t_sys *data, char *path)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	img->texture = mlx_xpm_file_to_image(data->mlx_ptr, path, \
										&img->width, &img->height);
	if (img->texture == NULL)
	{
		free(img);
		system_error(data, ERR_IMG_TEXTURE_FAILURE);
	}
	upscale_img(data, img);
	img->addr = mlx_get_data_addr(img->texture, &img->bpp, \
									&img->size_line, &img->endian);
	return (img);
}

void	free_img(t_sys *data, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->texture != NULL)
		mlx_destroy_image(data->mlx_ptr, img->texture);
	free(img);
}

void	destroy_texture_struct(t_sys *data, t_textures *ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	if (ptr->map == NULL)
	{
		free(ptr);
		return ;
	}
	i = 0;
	while (i < ptr->size)
	{
		free_img(data, ptr->map[i]);
		i++;
	}
	free(ptr->map);
	free(ptr);
}

void	destroy_player_textures(t_sys *data)
{
	destroy_texture_struct(data, data->player_idle);
	destroy_texture_struct(data, data->player_rev_idle);
	destroy_texture_struct(data, data->player_run);
	destroy_texture_struct(data, data->player_rev_run);
}

void	destroy_textures(t_sys *data)
{
	free_img(data, data->collectible);
	free_img(data, data->floor);
	free_img(data, data->wall);
	free_img(data, data->exit);
	free_img(data, data->bg);
	destroy_player_textures(data);
}

void	load_player_idle(t_sys *data)
{
	int		i;
	char	*path;
	char	*nbr;

	data->player_idle = (t_textures *)malloc(sizeof(t_textures));
	if (data->player_idle == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_idle->size = count_textures("src_bonus/resources/player/idle/");
	data->player_idle->map = (t_img **)malloc(data->player_idle->size * sizeof(t_img *));
	if (data->player_idle->map == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player_idle->size)
	{
		nbr = ft_itoa(i);
		path = build_path("src_bonus/resources/player/idle/", nbr, ".xpm");
		free(nbr);
		data->player_idle->map[i] = create_img(data, path);
		free(path);
		i++;
	}
}

void	load_player_run(t_sys *data)
{
	int		i;
	char	*path;
	char	*nbr;

	
	data->player_run = (t_textures *)malloc(sizeof(t_textures));
	if (data->player_run == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_run->size = count_textures("src_bonus/resources/player/run/");
	data->player_run->map = (t_img **)malloc(data->player_run->size * sizeof(t_img *));
	if (data->player_run->map == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player_run->size)
	{
		nbr = ft_itoa(i);
		path = build_path("src_bonus/resources/player/run/", nbr, ".xpm");
		free(nbr);
		data->player_run->map[i] = create_img(data, path);
		free(path);
		i++;
	}
}

void	load_player(t_sys *data)
{
	int	i;
	
	load_player_idle(data);
	data->player_rev_idle = (t_textures *)malloc(sizeof(t_textures));
	if (data->player_rev_idle == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_rev_idle->size = data->player_idle->size;
	data->player_rev_idle->map = (t_img **)malloc(data->player_rev_idle->size * sizeof(t_img *));
	if (data->player_rev_idle->map == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player_idle->size)
	{
		data->player_rev_idle->map[i] = reverse_img(data, data->player_idle->map[i]);
		i++;
	}
	load_player_run(data);
	data->player_rev_run = (t_textures *)malloc(sizeof(t_textures));
	if (data->player_rev_run == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->player_rev_run->size = data->player_run->size;
	data->player_rev_run->map = (t_img **)malloc(data->player_rev_run->size * sizeof(t_img *));
	if (data->player_rev_run->map == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	i = 0;
	while (i < data->player_run->size)
	{
		data->player_rev_run->map[i] = reverse_img(data, data->player_run->map[i]);
		i++;
	}
}

void	load_textures(t_sys *data)
{
	load_player(data);
	data->collectible = create_img(data, "src_bonus/resources/collectible.xpm");
	data->floor = create_img(data, "src_bonus/resources/floor.xpm");
	data->wall = create_img(data, "src_bonus/resources/wall.xpm");
	data->exit = create_img(data, "src_bonus/resources/exit.xpm");
	data->bg = (t_img *)malloc(sizeof(t_img));
	if (data->bg == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->bg->width = data->map->line_len * (16 * TEXTURE_FACTOR);
	data->bg->height = data->map->column_len * (16 * TEXTURE_FACTOR);
	data->bg->texture = mlx_new_image(data->mlx_ptr, \
											data->bg->width, \
											data->bg->height);
	if (data->bg->texture == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->bg->addr = mlx_get_data_addr(data->bg->texture, &data->bg->bpp, \
									&data->bg->size_line, &data->bg->endian);
	render_background(data, data->bg);
}
