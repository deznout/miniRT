/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/08/02 20:59:18 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	final_cylinder(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->cylinder.orient_vector[i])
	{
		if (!(scene->cylinder.orient_vector[i] >= -1
				&& scene->cylinder.orient_vector[i] <= 1))
			return (INCORRECT);
		i++;
	}
	i = 0;
	while (scene->cylinder.r_g_b[i])
	{
		if (!(scene->cylinder.r_g_b[i] >= 0 && scene->cylinder.r_g_b[i] <= 255))
			return (INCORRECT);
		i++;
	}
	scene->cylinder.identifier_num += 1; // after checking that all params are correct -> then align a value
	if (scene->cylinder.identifier_num < 1)
		return (INCORRECT);
	return (CORRECT);
}

static void	fill_cylinder_float(int num, int i, t_scene *scene, char **v_points)
{
	if (num == 1)
		scene->cylinder.point_xyz[i] = ft_atof(v_points[i]);
	else
		scene->cylinder.orient_vector[i] = ft_atof(v_points[i]);
}

static int	split_cylinder_content(int num, t_scene *scene, char **elem_content)
{
	int		i;
	char	**v_points;

	i = 0;
	v_points = ft_split(elem_content[num], ',');
	while (v_points[i])
	{
		if (i > 2)
			return (INCORRECT);
		if (num == 5)
			scene->cylinder.r_g_b[i] = ft_atoi(v_points[i]);
		else
		{
			if (check_float(v_points[i]))
				fill_cylinder_float(num, i, scene, v_points);
			else
				return (INCORRECT);
		}
		i++;
	}
	return (CORRECT);
}

int	check_cylinder(char **elem_content, t_scene *scene)
{
	int	i;
	int	flag;
	int	flag2;

	i = 0;
	while (elem_content[i])
		i++;
	if (i == 6)
	{
		flag = split_cylinder_content(1, scene, elem_content);
		flag2 = split_cylinder_content(2, scene, elem_content);
		if (check_float(elem_content[3]))
			scene->cylinder.bright_diam_ratio = ft_atof(elem_content[3]);
		else
			return (INCORRECT);
		if (check_float(elem_content[4]))
			scene->cylinder.light_height_ratio = ft_atof(elem_content[4]);
		else
			return (INCORRECT);
		i = split_cylinder_content(5, scene, elem_content);
		return (flag2 * flag * i * final_cylinder(scene));
	}
	return (INCORRECT);
}
