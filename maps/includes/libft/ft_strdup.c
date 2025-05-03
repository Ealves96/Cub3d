/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwolf <bwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:56 by ealves            #+#    #+#             */
/*   Updated: 2024/01/31 03:35:55 by bwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen((char *) s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*str_dup;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	if (atoi(argv[1]) == 1)
// 	{
// 		if (!(str_dup = ft_strdup(str)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(str_dup);
// 		if (str_dup == str)
// 			ft_print_result("\nstr_dup's adress == str's adress");
// 	}
// 	return (0);
// }
