/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 14:16:11 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/07 15:19:18 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"
#include "../Libft/libft.h"
#include "../mlx_linux/mlx.h"

static t_mlx	g_program_data;

int	ft_init_program(char *title, int size_x, int size_y)
{
	g_program_data.mlx_ptr = mlx_init();
	
}

int	ft_handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Exit program");
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	ft_printf("%d\n", keysym);
	return (0);
}
