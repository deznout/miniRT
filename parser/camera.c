/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/07/21 10:26:22 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int  final_camera(t_scene *scene)
{
    int i;

    i = 0;
    while (scene->camera.orient_vector[i])
    {
        if (!(scene->camera.orient_vector[i] >= -1 && scene->camera.orient_vector[i] <= 1))
            return (INCORRECT);
        i++;
    }
    if (!(scene->camera.fov_in_degrees >= 0 && scene->camera.fov_in_degrees <= 180))
        return (INCORRECT);
    scene->camera.identifier_num += 1; // after checking that all params are correct -> then align a value
    if (scene->camera.identifier_num != 1)
        return (INCORRECT);
    return (CORRECT);
}

static int  split_camera_content(int num, t_scene *scene, char **elem_content)
{
    int     i;
    char    **v_points;

    i = 0;
    v_points = ft_split(elem_content[num], ',');
    while (v_points[i])
    {
        if (i > 2)
            return (INCORRECT);
        if (check_float(v_points[i]))
        {
            if (num == 1)
                scene->camera.point_xyz[i] = ft_atof(v_points[i]);
            else
                scene->camera.orient_vector[i] = ft_atof(v_points[i]);
        }
        else
            return (INCORRECT);
        i++;
    }
    return (CORRECT);
}

int check_camera(char **elem_content, t_scene *scene)
{
    int i;
    int flag;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        flag = split_camera_content(1, scene, elem_content);
        i = split_camera_content(2, scene, elem_content);
        scene->camera.fov_in_degrees = ft_atoi(elem_content[3]);
        return (flag * i * final_camera(scene));
    }
    return (INCORRECT);
}
