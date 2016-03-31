/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:42:22 by adenece           #+#    #+#             */
/*   Updated: 2016/02/23 09:42:28 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nbrchar(char *nbr, int n, int i)
{
	while (n)
	{
		nbr[i] = '0' - (n % 10);
		n = n / 10;
		i--;
	}
	return (nbr);
}

char			*ft_itoa(int n)
{
	int			m;
	int			i;
	char		*nbr;

	i = -1;
	m = n;
	while (m)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
		i++;
	nbr = ft_strnew(i + 2);
	nbr[i + 1] = '\0';
	if (n < 0)
		nbr[0] = '-';
	if (n > 0)
		n = -n;
	if (!n)
		nbr[0] = '0';
	return (ft_nbrchar(nbr, n, i));
}
