/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:55:52 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 02:46:03 by ywake            ###   ########.fr       */
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
	if (fi->name[0] != '.')
		ft_putendl_fd(fi->name, STDOUT_FILENO);
}

void	del_list(void *content)
{
	t_fileinfo *fi;

	fi = (t_fileinfo *)content;
	free(fi->stat);
	free(fi->name);
	free(fi);
}

int		get_dirinfo(char *filepath, t_list **list)
{
	DIR				*dirp;
	struct dirent	*dirent;
	t_fileinfo		*finfo;

	if (!(dirp = opendir(filepath)))
		return (-1);
	while ((dirent = readdir(dirp)))
	{
		if (!(finfo = (t_fileinfo *)malloc(sizeof(t_fileinfo))))
			break ;
		ft_lstadd_front(list, ft_lstnew(finfo));
		finfo->name = ft_strdup(dirent->d_name);
		finfo->stat = (struct stat *)malloc(sizeof(struct stat));
		if (!finfo->name || !finfo->stat)
			break ;
		if (lstat(dirent->d_name, finfo->stat))
			break ;
	}
	if (errno || closedir(dirp))
	{
		ft_lstclear(list, del_list);
		closedir(dirp);
		return (-1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_list			*list;

	(void)argv;
	errno = 0;
	if (argc > 1)
		return (error(ERRMSG_CMDARG));
	list = NULL;
	if (get_dirinfo("./", &list))
		return (error("Error"));
	ft_lst_sort(&list, compare_name);
	ft_lst_sort(&list, compare_modtime);
	ft_lst_reverse(&list);
	ft_lstiter(list, print_filename);
	ft_lstclear(&list, del_list);
	return (0);
}
