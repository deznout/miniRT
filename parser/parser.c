/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/08/02 21:03:09 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"

int	check_float_util(char *str)
{
	str += 2;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (INCORRECT);
		str++;
	}
	return (CORRECT);
}

int	check_float(char *str)
{
	int	dot;

	dot = 0;
	if (*str == '-')
		str++;
	if (*str == '0' && *(str + 1) == '.')
		return (check_float_util(str));
	if (*str != '0' && ft_isdigit(*str))
	{
		while (*str)
		{
			if (*str == '.')
			{
				dot++;
				str++;
			}
			if (!ft_isdigit(*str) || dot > 1)
				return (INCORRECT);
			str++;
		}
		return (CORRECT);
	}
	if (*(str + 1) == 0 && *str == '0')
		return (CORRECT);
	return (INCORRECT);
}

float	ft_atof(const char *s)
{
	check_fl	fl;

	fl.rez = 0;
	fl.fact = 1;
	fl.point_seen = 0;
	if (*s == '-')
	{
		s++;
		fl.fact = -1;
	}
	while ((*s) && (ft_isdigit(*s) || *s == '.'))
	{
		if (*s == '.')
		{
			fl.point_seen = 1;
			s++;
		}
		if (fl.point_seen)
			fl.fact /= 10.0f;
		fl.rez = fl.rez * 10.0f + (float)(*s - '0');
		s++;
	}
	return (fl.rez * fl.fact);
}

int	define_element(char *elem_str, t_scene *scene)
{
	char	**elem_content;

	elem_content = ft_split(elem_str, ' ');
	if (!ft_strncmp("A", elem_content[0], 1))
		return (check_ambient(elem_content, scene));
	if (!ft_strncmp("C", elem_content[0], 1))
		return (check_camera(elem_content, scene));
	if (!ft_strncmp("L", elem_content[0], 1))
		return (check_light(elem_content, scene));
	if (!ft_strncmp("pl", elem_content[0], 2))
		return (check_plane(elem_content, scene));
	if (!ft_strncmp("sp", elem_content[0], 2))
		return (check_sphere(elem_content, scene));
	if (!ft_strncmp("cy", elem_content[0], 2))
		return (check_cylinder(elem_content, scene));
	return (INCORRECT);
}

int	check_scene(t_scene *scene, char *content)
{
	int		i;
	char	**elements;

	i = 0;
	elements = ft_split(content, '\n');

	// write output logs if you wish & time is enough

	while (elements[i])
		if (!define_element(elements[i++], scene))
			return (INCORRECT);
	return (CORRECT);
}

void	ft_open(t_scene *scene, char *arg)
{
	int		fd;
	int		rd;
	char	*content;

	content = ft_substr(arg, ft_strlen(arg) - 3, 3);
	rd = ft_strncmp(content, ".rt", 3);
	free(content);
	fd = open(arg, O_RDONLY);
	if (fd < 0 || rd != 0)
	{
		printf("Incorrect file!\n");
		exit (1);
	}
	content = malloc(10000);
	rd = (int)read(fd, content, 10000);
	content[rd] = '\0';
	if (!check_scene(scene, content))
	{
		printf("Incorrect scene!\n");
		exit (1);
	}
}
