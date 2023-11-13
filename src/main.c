/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:40:45 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 13:11:36 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Compile command: cc src/*.c Libft/*.c -Lmlx_linux -lmlx_Linux -lX11 -lXext

#include "../include/map.h"
#include "../Libft/libft.h"
#include "../include/system.h"
#include "../include/error.h"
#include "../include/render.h"
#include "../include/texture.h"
#include "../mlx_linux/mlx.h"

t_sys	*init_program(char *path)
{
	t_sys	*data;
	
	data = (t_sys *)malloc(sizeof(t_sys));
	if (data == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	init_system(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	data->map = parse_map(path);
	if (data->map == NULL)
		system_error(data, ERR_MAP_GENERATE_FAILURE);
	init_player(data);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->map->line_len*(16 * TEXTURE_FACTOR), \
									data->map->column_len*(16 * TEXTURE_FACTOR), PROGRAM_NAME);
	if (data->mlx_win == NULL)
		system_error(data, ERR_SYS_MALLOC_FAILURE);
	load_textures(data);
	load_frame_buffer(data);
	return (data);
}

int	main(int argc, char *argv[])
{
	t_sys	*system;

	system = init_program(argv[1]);
	mlx_hook(system->mlx_win, ON_KEYDOWN, KEY_PRESS_MASK, handle_input, system);
	mlx_hook(system->mlx_win, ON_DESTROY, NO_EVENT_MASK, destroy_system, system);
	mlx_loop_hook(system->mlx_ptr, handle_render, system);
	mlx_loop(system->mlx_ptr);
	destroy_system(system);
	return (0);
	/* if (argc < 2)
		return (ft_printf("error"), 0);
	t_map *map = parse_map(argv[1]);		
	print_map(map);
	free(map->map);
	free(map);
	return (0); */
}
