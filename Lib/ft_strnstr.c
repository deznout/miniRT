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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			k = 1;
			while (little[k] && big[i + k] == little[k] && i + k < len)
				k++;
			if (little[k] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
