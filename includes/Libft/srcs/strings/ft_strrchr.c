/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:00:17 by lmaria            #+#    #+#             */
/*   Updated: 2024/11/28 15:57:06 by lmaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*last_occurrence;
	int				i;
	unsigned char	ch;

	i = 0;
	last_occurrence = 0;
	ch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == ch)
			last_occurrence = &s[i];
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return ((char *)last_occurrence);
}
