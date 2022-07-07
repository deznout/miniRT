/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:09:43 by hbrent            #+#    #+#             */
/*   Updated: 2022/01/13 20:09:49 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char s1, char const *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (((char *)set)[k] == s1)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	char		*res;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_check(((char *)s1)[i], set))
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (j >= 0 && ft_check(((char *)s1)[j], set))
		j--;
	if (j <= i)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (j - i) + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + i, j - i + 2);
	return (res);
}
