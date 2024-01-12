/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 16:22:07 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:43:53 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./include/so_long.h"

const char	*g_error_map[] = {
[ERR_MAP_INNIT_FAILURE] = "An error occured while allocating memory",
[ERR_MAP_GENERATE_FAILURE] = "Please enter a valid .ber file!",
[ERR_MAP_VALIDATE_FAILURE] = "An error occured while validating the .ber file!",
[ERR_SYS_MALLOC_FAILURE] = "Malloc error",
[ERR_IMG_TEXTURE_FAILURE] = "Failed to load texture"
};

void	print_error(t_error error)
{
	char	*error_msg;

	error_msg = (char *)g_error_map[error];
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
