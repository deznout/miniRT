/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/08/02 21:00:44 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	final_sphere(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->sphere.r_g_b[i])
	{
		if (!(scene->sphere.r_g_b[i] >= 0 && scene->sphere.r_g_b[i] <= 255))
			return (INCORRECT);
		i++;
	}
	scene->sphere.identifier_num += 1; // after checking that all params are correct -> then align a value
	if (scene->sphere.identifier_num < 1)
		return (INCORRECT);
	return (CORRECT);
}

static int	split_sphere_content(int num, t_scene *scene, char **elem_content)
{
	int		i;
	char	**v_points;

	i = 0;
	v_points = ft_split(elem_content[num], ',');
	while (v_points[i])
	{
		if (i > 2)
			return (INCORRECT);
		if (num == 3)
			scene->sphere.r_g_b[i] = ft_atoi(v_points[i]);
		else
		{
			if (check_float(v_points[i]))
				scene->sphere.point_xyz[i] = ft_atof(v_points[i]);
			else
				return (INCORRECT);
		}
		i++;
	}
	return (CORRECT);
}

int	check_sphere(char **elem_content, t_scene *scene)
{
	int	i;
	int	flag;

	i = 0;
	while (elem_content[i])
		i++;
	if (i == 4)
	{
		flag = split_sphere_content(1, scene, elem_content);
		if (check_float(elem_content[2]))
			scene->sphere.bright_diam_ratio = ft_atof(elem_content[2]);
		else
			return (INCORRECT);
		i = split_sphere_content(3, scene, elem_content);
		return (i * flag * final_sphere(scene));
	}
	return (INCORRECT);
}
