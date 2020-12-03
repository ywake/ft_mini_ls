/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:09 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 08:17:37 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"

int		compare_name(t_fileinfo *fi1, t_fileinfo *fi2)
{
	return (ft_strcmp(fi1->dirent->d_name, fi2->dirent->d_name));
}

int		compare_modtime_sec(t_fileinfo *fi1, t_fileinfo *fi2)
{
	long	div;

	div = fi1->stat->st_mtimespec.tv_sec - fi2->stat->st_mtimespec.tv_sec;
	div *= -1;
	if (div < 0)
		return (-1);
	else if (div > 0)
		return (1);
	return (0);
}

int		compare_modtime_nsec(t_fileinfo *fi1, t_fileinfo *fi2)
{
	long	div;

	div = fi1->stat->st_mtimespec.tv_nsec - fi2->stat->st_mtimespec.tv_nsec;
	div *= -1;
	if (div < 0)
		return (-1);
	else if (div > 0)
		return (1);
	return (0);
}
