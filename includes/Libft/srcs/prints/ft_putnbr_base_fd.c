/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:58:23 by lmaria            #+#    #+#             */
/*   Updated: 2024/12/20 23:22:17 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	int		count;
	size_t	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
		count += ft_putnbr_base_fd(nbr / base_len, base, fd);
	count += ft_putchar_fd(base[nbr % base_len], fd);
	return (count);
}
