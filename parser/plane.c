/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/08/02 19:01:00 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	final_plane(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->plane.orient_vector[i])
	{
		if (!(scene->plane.orient_vector[i] >= -1
				&& scene->plane.orient_vector[i] <= 1))
			return (INCORRECT);
		i++;
	}
	i = 0;
	while (scene->plane.r_g_b[i])
	{
		if (!(scene->plane.r_g_b[i] >= 0 && scene->plane.r_g_b[i] <= 255))
			return (INCORRECT);
		i++;
	}
	scene->plane.identifier_num += 1; // after checking that all params are correct -> then align a value
	if (scene->plane.identifier_num < 1)
		return (INCORRECT);
	return (CORRECT);
}

static void	fill_plane_float(int num, int i, t_scene *scene, char **v_points)
{
	if (num == 1)
		scene->plane.point_xyz[i] = ft_atof(v_points[i]);
	else
		scene->plane.orient_vector[i] = ft_atof(v_points[i]);
}

static int	split_plane_content(int num, t_scene *scene, char **elem_content)
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
			scene->plane.r_g_b[i] = ft_atoi(v_points[i]);
		else
		{
			if (check_float(v_points[i]))
				fill_plane_float(num, i, scene, v_points);
			else
				return (INCORRECT);
		}
		i++;
	}
	return (CORRECT);
}

int	check_plane(char **elem_content, t_scene *scene)
{
	int	i;
	int	flag;
	int	flag2;

	i = 0;
	while (elem_content[i])
		i++;
	if (i == 4)
	{
		flag = split_plane_content(1, scene, elem_content);
		flag2 = split_plane_content(2, scene, elem_content);
		i = split_plane_content(3, scene, elem_content);
		return (flag2 * flag * i * final_plane(scene));
	}
	return (INCORRECT);
}
