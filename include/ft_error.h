/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 16:21:14 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/06 16:34:55 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum	e_error
{
	ERR_MAP_INNIT_FAILURE,
	ERR_MAP_GENERATE_FAILURE,
	ERR_MAP_VALIDATE_FAILURE
}	t_error;

extern void	ft_print_error(t_error error);

#endif