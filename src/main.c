/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:40:45 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/07 14:56:47 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Compile command: cc src/*.c Libft/*.c -Lmlx_linux -lmlx_Linux -lX11 -lXext

#include "../include/ft_map.h"
#include "../Libft/libft.h"
#include "../include/ft_window.h"
#include "../mlx_linux/mlx.h"
#define HEIGHT 400
#define WIDTH 400

int	main(int argc, char *argv[])
{
	t_mlx	mlx_data;

	mlx_data.mlx_ptr = mlx_init();
	if (mlx_data.mlx_ptr == NULL)
		return (1);
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx_ptr, WIDTH, HEIGHT, "Program");
	if (mlx_data.mlx_win == NULL)
	{
		mlx_destroy_display(mlx_data.mlx_ptr);
		free(mlx_data.mlx_ptr);
		return (1);
	}
	mlx_hook(mlx_data.mlx_win, ON_KEYDOWN, KEY_PRESS_MASK, ft_handle_input, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	mlx_destroy_window(mlx_data.mlx_ptr, mlx_data.mlx_win);
	mlx_destroy_display(mlx_data.mlx_ptr);
	free(mlx_data.mlx_ptr);
	return (0);
	/* if (argc < 2)
		return (ft_printf("error"), 0);
	t_map *map = ft_parse_map(argv[1]);		
	ft_print_map(map);
	free(map->map);
	free(map);
	return (0); */
}
