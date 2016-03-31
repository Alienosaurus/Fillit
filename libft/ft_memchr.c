/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <adenece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:40:31 by adenece           #+#    #+#             */
/*   Updated: 2016/02/25 11:52:21 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s)
		while (n-- > 0)
		{
			if ((unsigned char)c == *((unsigned char *)s))
				return ((void *)s);
			s++;
		}
	return (NULL);
}
