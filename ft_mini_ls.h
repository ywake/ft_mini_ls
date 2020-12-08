/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:56:59 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 02:35:30 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# define ERRMSG_CMDARG "Error: Command line arguments are not accepted."

typedef struct	s_fileinfo
{
	char			*name;
	struct stat		*stat;
}				t_fileinfo;

#endif
