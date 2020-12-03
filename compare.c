/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 07:14:09 by ywake             #+#    #+#             */
/*   Updated: 2020/12/04 07:17:47 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

#include <dirent.h>

int		compare_name(struct dirent *de1, struct dirent *de2)
{
	return (ft_strcmp(de1->d_name, de2->d_name));
}
