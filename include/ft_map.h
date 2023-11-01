/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:37:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/01 16:32:02 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_map {
	char	*map;
	size_t	l_len;
	int		start_index;
	int		exit_index;
} t_map;

extern t_map	ft_parse_map(char *path);
extern int		ft_count_alnum(char *str, size_t len);
extern void		ft_init_map(t_map *map);

#endif
