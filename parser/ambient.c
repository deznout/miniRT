//
// Created by Hoover Brent on 7/21/22.
//

#include "parser.h"

int check_ambient(char **elem_content, t_scene *scene)
{
    char    **colors;
    int     i;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 3)
    {
        i = 0;
        if (check_float(elem_content[1]))
            scene->ambient.light_height_ratio = ft_atof(elem_content[1]);
        else
            return (INCORRECT);
        if (!(scene->ambient.light_height_ratio >= 0.0 && scene->ambient.light_height_ratio <= 1.0))
            return (INCORRECT);
        colors = ft_split(elem_content[2], ',');
        while (colors[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->ambient.r_g_b[i] = ft_atoi(colors[i]);
            if (!(scene->ambient.r_g_b[i] >= 0 && scene->ambient.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->ambient.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}
