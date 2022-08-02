/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/08/02 18:43:26 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	final_light(t_scene *scene)
{
	int	i;

	i = 0;
	if (!(scene->light.bright_diam_ratio >= 0.0
			&& scene->light.bright_diam_ratio <= 1.0))
		return (INCORRECT);
	while (scene->camera.orient_vector[i])
	{
		if (!(scene->light.r_g_b[i] >= 0 && scene->light.r_g_b[i] <= 255))
			return (INCORRECT);
		i++;
	}
	scene->light.identifier_num += 1; // after checking that all params are correct -> then align a value
	if (scene->light.identifier_num != 1)
		return (INCORRECT);
	return (CORRECT);
}

static int	split_light_content(int num, t_scene *scene, char **elem_content)
{
	int		i;
	char	**v_points;

	i = 0;
	v_points = ft_split(elem_content[num], ',');
	while (v_points[i])
	{
		if (i > 2)
			return (INCORRECT);
		if (num == 1)
		{
			if (check_float(v_points[i]))
				scene->light.point_xyz[i] = ft_atof(v_points[i]);
			else
				return (INCORRECT);
		}
		else
			scene->light.r_g_b[i] = ft_atoi(v_points[i]);
		i++;
	}
	return (CORRECT);
}

int	check_light(char **elem_content, t_scene *scene)
{
	int	i;
	int	flag;

	i = 0;
	while (elem_content[i])
		i++;
	if (i == 4)
	{
		flag = split_light_content(1, scene, elem_content);
		if (check_float(elem_content[2]))
			scene->light.bright_diam_ratio = ft_atof(elem_content[2]);
		else
			return (INCORRECT);
		i = split_light_content(3, scene, elem_content);
		return (i * flag * final_light(scene));
	}
	return (INCORRECT);
}
