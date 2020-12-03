/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:55:52 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 08:44:43 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"
#include "ft_mini_ls.h"
#include "compare.h"

#ifdef TEST
# include "test.h"
#endif

int		error(char *str)
{
	if (errno)
		perror(str);
	else
		ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

void	print_filename(void *content)
{
	t_fileinfo *fi;

	fi = (t_fileinfo *)content;
	if (fi->dirent->d_name[0] != '.')
		ft_putendl_fd(fi->dirent->d_name, STDOUT_FILENO);
}

int		get_dirinfo(char *filepath, t_list **list)
{
	DIR				*dirp;
	struct dirent	*dirent;
	t_fileinfo		*finfo;

	if ((dirp = opendir(".")) == NULL)
		return (-1);
	while ((dirent = readdir(dirp)))
	{
		finfo = (t_fileinfo *)malloc(sizeof(t_fileinfo));
		finfo->dirent = dirent;
		finfo->stat = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(dirent->d_name, finfo->stat))
			return (-1);
		ft_lstadd_back(list, ft_lstnew(finfo));
	}
	if (errno || closedir(dirp))
		return (-1);
	return (0);
}

void	del_list(void *content)
{
	t_fileinfo *fi;

	fi = (t_fileinfo *)content;
	free(fi->stat);
	free(fi);
}

int		main(int argc, char *argv[])
{
	t_list			*list;

	(void)argv;
	if (argc > 1)
		return (error(ERRMSG_CMDARG));
	errno = 0;
	list = NULL;
	if (get_dirinfo(".", &list))
		return (error(""));
	list = ft_lst_sort(list, compare_name);
	list = ft_lst_sort(list, compare_modtime_nsec);
	list = ft_lst_sort(list, compare_modtime_sec);
	ft_lst_reverse(&list);
	ft_lstiter(list, print_filename);
	ft_lstclear(&list, del_list);
	return (0);
}
