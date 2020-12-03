/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:55:52 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 04:18:11 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"
#include "ft_mini_ls.h"

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
	struct dirent *dirent;
	dirent = (struct dirent *)content;
	ft_putendl_fd(dirent->d_name, STDOUT_FILENO);
}

int		main(int argc, char *argv[])
{
	DIR				*dirp;
	struct dirent	*dirent;
	t_list			*list;

	(void)argv;
	if (argc > 1)
		return (error(ERRMSG_CMDARG));
	errno = 0;
	if ((dirp = opendir(".")) == NULL)
		return (error(""));
	list = NULL;
	while ((dirent = readdir(dirp)))
		ft_lstadd_back(&list, ft_lstnew(dirent));
	if (errno || closedir(dirp))
		return (error(""));
	ft_lstiter(list, print_filename);
	return (0);
}
