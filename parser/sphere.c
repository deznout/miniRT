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

int check_sphere(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            if (check_float(v_points[i]))
                scene->sphere.point_xyz[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            i++;
        }
        if (check_float(elem_content[2]))
            scene->sphere.bright_diam_ratio = ft_atof(elem_content[2]);
        else
            return (INCORRECT);
        v_points = ft_split(elem_content[3], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->sphere.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->sphere.r_g_b[i] >= 0 && scene->sphere.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->sphere.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}
