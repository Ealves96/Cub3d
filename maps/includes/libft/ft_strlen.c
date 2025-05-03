/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:44:47 by ealves            #+#    #+#             */
/*   Updated: 2024/02/12 22:50:31 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

/*int	main(void)
{
	char	str[] = "elisabeth";
	printf("%d\n", ft_strlen(str));
}*/