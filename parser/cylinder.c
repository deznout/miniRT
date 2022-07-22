//
// Created by Hoover Brent on 7/21/22.
//

#include "parser.h"

int check_cylinder(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 6)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            if (check_float(v_points[i]))
                scene->cylinder.point_xyz[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            i++;
        }
        v_points = ft_split(elem_content[2], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            if (check_float(v_points[i]))
                scene->cylinder.orient_vector[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            if (!(scene->cylinder.orient_vector[i] >= -1 && scene->cylinder.orient_vector[i] <= 1))
                return (INCORRECT);
            i++;
        }
        if (check_float(elem_content[3]))
            scene->cylinder.bright_diam_ratio = ft_atof(elem_content[3]);
        else
            return (INCORRECT);
        if (check_float(elem_content[4]))
            scene->cylinder.light_height_ratio = ft_atof(elem_content[4]);
        else
            return (INCORRECT);
        v_points = ft_split(elem_content[5], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->cylinder.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->cylinder.r_g_b[i] >= 0 && scene->cylinder.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->cylinder.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}
