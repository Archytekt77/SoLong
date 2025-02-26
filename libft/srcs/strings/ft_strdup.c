/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:59:02 by lmaria            #+#    #+#             */
/*   Updated: 2025/01/03 14:13:47 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	int		length;

	i = 0;
	length = ft_strlen(s);
	dup = ft_calloc(length + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < length)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
