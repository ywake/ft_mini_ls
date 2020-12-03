/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:34 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 08:18:07 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_H
# define COMPARE_H

# include "ft_mini_ls.h"

int		compare_name(t_fileinfo *fi1, t_fileinfo *fi2);
int		compare_modtime_sec(t_fileinfo *fi1, t_fileinfo *fi2);
int		compare_modtime_nsec(t_fileinfo *fi1, t_fileinfo *fi2);

#endif
