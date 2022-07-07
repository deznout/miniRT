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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			k;
	char			*sub;
	unsigned int	strlen;

	k = 0;
	if (!s)
		return (NULL);
	strlen = (int)ft_strlen(s);
	if (start >= strlen)
	{
		sub = (char *)malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (start + len >= strlen)
		sub = (char *)malloc(sizeof(char) * (strlen - start));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (k < len && start < strlen)
		sub[k++] = s[start++];
	sub[k] = '\0';
	return (sub);
}
