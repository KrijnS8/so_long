/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:43:24 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 14:38:49 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_lst
{
	void	*content;
	void	*next;
	void	*prev;
}	t_lst;

t_lst	*lst_new(void *content);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst **lst, t_lst *node);
void	lstclear(t_lst **lst, void (*del)(void*));

#endif