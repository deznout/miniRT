//
// Created by Hoover Brent on 7/21/22.
//

#include "parser.h"

int check_camera(char **elem_content, t_scene *scene)
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
                scene->camera.point_xyz[i] = ft_atof(v_points[i]);
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
                scene->camera.orient_vector[i] = ft_atof(v_points[i]);
            else
                return (INCORRECT);
            if (!(scene->camera.orient_vector[i] >= -1 && scene->camera.orient_vector[i] <= 1))
                return (INCORRECT);
            i++;
        }
        scene->camera.fov_in_degrees = ft_atoi(elem_content[3]);
        if (!(scene->camera.fov_in_degrees >= 0 && scene->camera.fov_in_degrees <= 180))
            return (INCORRECT);
        scene->camera.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}
