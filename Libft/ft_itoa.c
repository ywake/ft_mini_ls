/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:39:57 by ywake             #+#    #+#             */
/*   Updated: 2020/06/29 04:21:38 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		t;
	int		digit;
	int		sign;
	char	*buf;

	digit = (n < 0) ? 2 : 1;
	sign = (n < 0) ? -1 : 1;
	t = n;
	while (t /= 10)
		digit++;
	buf = (char *)ft_calloc(digit + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (digit > 0)
	{
		if (n == 0 && sign < 0)
			buf[--digit] = '-';
		else
			buf[--digit] = n % 10 * sign + '0';
		n /= 10;
	}
	return (buf);
}
