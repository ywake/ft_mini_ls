/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:35:06 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 04:51:26 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lst_reverse(t_list **lst)
{
	t_list *tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lst_reverse(lst);
	ft_lstadd_back(lst, tmp);
}
