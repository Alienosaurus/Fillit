/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <adenece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:41:10 by adenece           #+#    #+#             */
/*   Updated: 2016/02/25 11:51:36 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 && s2)
		while (n-- > 0)
		{
			if (*((unsigned char *)s1) != *((unsigned char *)s2))
				return (*((unsigned char *)s1) - *((unsigned char *)s2));
			s1++;
			s2++;
		}
	return (0);
}
