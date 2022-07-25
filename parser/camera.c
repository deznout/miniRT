//
// Created by Hoover Brent on 7/21/22.
//

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

static void get_camera_cords(int *flag, t_scene *scene, char **elem_content, int num) // correct !!!
{
    int     i;
    char    **v_points;

    i = 0;
    if (num)
    v_points = ft_split(elem_content[1], ',');
    while (v_points[i])
    {
        if (i > 2)
        {
            *flag = INCORRECT;
            return ;
        }
        if (check_float(v_points[i]))
            scene->camera.point_xyz[i] = ft_atof(v_points[i]);
        else
            *flag = INCORRECT;
        i++;
    }
    v_points = ft_split(elem_content[2], ',');
    i = 0;
    while (v_points[i])
    {
        if (i > 2)
        {
            *flag = INCORRECT;
            return ;
        }
        if (check_float(v_points[i]))
            scene->camera.orient_vector[i] = ft_atof(v_points[i]);
        else
            *flag = INCORRECT;
        i++;
    }
}

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
            i++;
        }
        scene->camera.fov_in_degrees = ft_atoi(elem_content[3]);
        return (final_camera(scene));
    }
    return (INCORRECT);
}
