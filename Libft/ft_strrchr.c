/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:57:15 by ywake             #+#    #+#             */
/*   Updated: 2020/06/24 16:37:50 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int lensrc;

	lensrc = ft_strlen(s);
	i = 0;
	while (lensrc - i > -1)
	{
		if (s[lensrc - i] == c)
			return ((char *)(s + lensrc - i));
		i++;
	}
	return (NULL);
}
