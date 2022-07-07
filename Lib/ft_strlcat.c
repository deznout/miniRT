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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_d;
	size_t	res;
	size_t	len_s;
	size_t	i;

	s = (char *)src;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > len_d)
		res = len_s + len_d;
	else
		res = len_s + size;
	while (s[i] != '\0' && (len_d + 1) < size)
	{
		dst[len_d] = s[i];
		len_d++;
		i++;
	}
	dst[len_d] = '\0';
	return (res);
}
