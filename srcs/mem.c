/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:54:58 by mberne            #+#    #+#             */
/*   Updated: 2021/10/06 15:11:18 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	i = 0;
	str = (unsigned char *)s;
	value = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == value)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < n - 1))
		i++;
	return (str1[i] - str2[i]);
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (tab && size)
	{
		while (size-- <= 0)
			free(tab[size]);
	}
	else if (tab)
	{
		while (tab[i])
			i++;
		while (--i >= 0)
			free(tab[i]);
		free(tab);
	}
}
