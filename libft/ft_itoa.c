/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:35:57 by alakhdar          #+#    #+#             */
/*   Updated: 2022/03/09 10:39:54 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_allocm(unsigned int len, int n)
{
	char	*dest;

	if (n < 0)
		dest = (char *)malloc(sizeof(char) * len + 1 + 1);
	else
		dest = (char *)malloc(sizeof(char) * len + 1);
	return (dest);
}

unsigned int	ft_checksign(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

char	*ft_finalizer(char *src, unsigned int index,
				unsigned int len, unsigned int nb)
{
	src[index] = nb % 10 + 48;
	src[len] = '\0';
	return (src);
}

char	*ft_itoa(int n)
{
	char			*dest;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = ft_checksign(n);
	len = ft_nblen(nb);
	dest = ft_allocm(len, n);
	i = 0;
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	ft_finalizer(dest, i, len, nb);
	return (dest);
}
