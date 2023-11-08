/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:39:49 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/08 17:38:29 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"
#include "../mlx_linux/mlx.h"

int	handle_render(t_sys *system)
{
	mlx_string_put(system->mlx_ptr, system->mlx_win, 100, 100, 0xff0000, "Hello World");
	return (0);
}
