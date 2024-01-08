/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 16:21:14 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 17:59:53 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

typedef enum e_error
{
	ERR_NO_ERR,
	ERR_MAP_INNIT_FAILURE,
	ERR_MAP_GENERATE_FAILURE,
	ERR_MAP_VALIDATE_FAILURE,
	ERR_SYS_MALLOC_FAILURE,
	ERR_IMG_TEXTURE_FAILURE
}	t_error;

extern void	print_error(t_error error);

#endif