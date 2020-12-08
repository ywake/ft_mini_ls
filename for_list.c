/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:09 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 03:06:28 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "for_list.h"

#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"

void	print_filename(void *content)
{
	t_fileinfo *fi;

	fi = (t_fileinfo *)content;
	if (fi->name[0] != '.')
		ft_putendl_fd(fi->name, STDOUT_FILENO);
}

void	del_list(void *content)
{
	t_fileinfo *fi;

	fi = (t_fileinfo *)content;
	if (fi->stat)
		free(fi->stat);
	if (fi->name)
		free(fi->name);
	free(fi);
}

int		compare_name(t_fileinfo *fi1, t_fileinfo *fi2)
{
	return (ft_strcmp(fi1->name, fi2->name));
}

int		compare_modtime(t_fileinfo *fi1, t_fileinfo *fi2)
{
	long			div_sec;
	long			div_nsec;

	div_sec = fi1->stat->st_mtimespec.tv_sec - fi2->stat->st_mtimespec.tv_sec;
	if (div_sec < 0)
		return (1);
	else if (div_sec > 0)
		return (-1);
	else
	{
		div_nsec = fi1->stat->st_mtimespec.tv_nsec -
					fi2->stat->st_mtimespec.tv_nsec;
		if (div_nsec < 0)
			return (1);
		else if (div_nsec > 0)
			return (-1);
	}
	return (0);
}
