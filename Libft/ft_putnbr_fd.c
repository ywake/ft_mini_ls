/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:41:22 by ywake             #+#    #+#             */
/*   Updated: 2020/06/29 04:24:11 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa(int n, char *buf)
{
	int		t;
	int		digit;
	int		sign;

	digit = (n < 0) ? 2 : 1;
	sign = (n < 0) ? -1 : 1;
	t = n;
	while (t /= 10)
		digit++;
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

void		ft_putnbr_fd(int n, int fd)
{
	char buf[12];

	ft_bzero(buf, 12);
	itoa(n, buf);
	ft_putstr_fd(buf, fd);
}
