/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:34 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 03:01:52 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOR_LIST_H
# define FOR_LIST_H

# include "ft_mini_ls.h"

void	print_filename(void *content);
void	del_list(void *content);
int		compare_name(t_fileinfo *fi1, t_fileinfo *fi2);
int		compare_modtime(t_fileinfo *fi1, t_fileinfo *fi2);

#endif
