/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 14:16:11 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/08 17:53:07 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/system.h"
#include "../include/map.h"
#include "../Libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../include/texture.h"
#include <stdio.h>

void	init_system(t_sys	*data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->map = NULL;
	data->player = NULL;
	data->collectible = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
}

int destroy_system(t_sys *data)
{
	destroy_textures(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map != NULL)
	{
		if (data->map->map != NULL)
			free(data->map->map);
		free(data->map);
	}
	free(data);
	exit(1);
	return (0);
}

void	system_error(t_sys *data, t_error error)
{
	print_error(error);
	destroy_system(data);
}

int	handle_input(int keysym, t_sys *data)
{
	if (keysym == XK_Escape)
	{
		destroy_system(data);
	}
	ft_printf("%d\n", keysym);
	return (0);
}