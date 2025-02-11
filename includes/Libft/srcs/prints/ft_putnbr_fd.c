/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:05 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/11 13:18:55 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_putnbr_internal(int n, int fd, int count)
{
	if (n >= 10)
		ft_putnbr_internal(n / 10, fd, count);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_putnbr_internal(n, fd, count);
	return (count);
}
