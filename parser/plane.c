//
// Created by Hoover Brent on 7/21/22.
//

#include "parser.h"

int check_plane(char **elem_content, t_scene *scene)
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
                scene->plane.point_xyz[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            i++;
        }
        i = 0;
        v_points = ft_split(elem_content[2], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            if (check_float(v_points[i]))
                scene->plane.orient_vector[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            if (!(scene->plane.orient_vector[i] >= -1 && scene->plane.orient_vector[i] <= 1))
                return (INCORRECT);
            i++;
        }
        v_points = ft_split(elem_content[3], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->plane.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->plane.r_g_b[i] >= 0 && scene->plane.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->plane.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}
