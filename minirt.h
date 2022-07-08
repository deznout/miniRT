//
// Created by Hoover Brent on 3/9/22.
//

#ifndef JENISH_MINIRT_H
#define JENISH_MINIRT_H

# include "Lib/libft.h"
# include "minilibx_macOS/mlx.h"
# include <stdio.h>

typedef struct s_element {
    char		*identifier;
    float       br_diam_ratio;
    float       lg_hgt_ratio;
    int         r_g_b[3];
    int         count_dup;
    float       point_xyz[3];
    float       orient_vector[3];
    int         fov_in_degrees;
}				t_element;

typedef struct s_scene {
    t_element   ambient;
    t_element   camera;
    t_element   light;
    t_element   plane;
    t_element   sphere;
    t_element   cylinder;
}				t_scene;

void    ft_open(t_scene *scene, char *arg);

#endif //JENISH_MINIRT_H
