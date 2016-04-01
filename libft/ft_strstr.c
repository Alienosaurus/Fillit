/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:58:34 by adenece           #+#    #+#             */
/*   Updated: 2016/02/23 10:58:38 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	if (!needle || !(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		if (*haystack == *needle)
			while (haystack[i] == needle[i] && needle[i] && haystack[i])
				i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
