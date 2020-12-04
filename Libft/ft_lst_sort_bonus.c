/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:21:21 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 07:04:58 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstadd_back_quick(t_list **list, t_list *new, t_list **last)
{
	t_list	*next;

	next = new->next;
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
		*last = new;
	}
	else
	{
		(*last)->next = new;
		*last = new;
	}
	return (next);
}

t_list			*ft_lst_sort(t_list *left, int (*cmp)())
{
	int		size;
	t_list	*ans;
	t_list	*tmp;
	t_list	*right;

	if (left == NULL || left->next == NULL)
		return (left);
	size = ft_lstsize(left);
	tmp = ft_lst_at(left, size / 2 - 1);
	right = tmp->next;
	tmp->next = NULL;
	left = ft_lst_sort(left, cmp);
	right = ft_lst_sort(right, cmp);
	ans = NULL;
	while (left || right)
	{
		if (left && (!right || cmp(left->content, right->content) <= 0))
			left = lstadd_back_quick(&ans, left, &tmp);
		else
			right = lstadd_back_quick(&ans, right, &tmp);
	}
	return (ans);
}
