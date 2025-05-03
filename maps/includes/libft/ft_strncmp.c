/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:56:17 by ealves            #+#    #+#             */
/*   Updated: 2024/02/12 22:49:00 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	// char s1[5] = "Test1";
// 	// char s2[2] = "OK";
// 	// char s1[] = "Same";
// 	// char s2[] = "Size";
// 	// char s1[] = "Shorter";
// 	char s2[] = "ThanMyself";
// 	char s1[] = "ShorterTest";

// 	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
// }