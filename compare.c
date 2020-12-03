/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:09 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 07:46:24 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

#include <dirent.h>
#include "libft.h"

int		compare_name(t_fileinfo *fi1, t_fileinfo *fi2)
{
	return (ft_strcmp(fi1->dirent->d_name, fi2->dirent->d_name));
}
