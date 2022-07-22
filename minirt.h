//
// Created by Hoover Brent on 3/9/22.
//

#ifndef JENISH_MINIRT_H
#define JENISH_MINIRT_H

# include "Lib/libft.h"
# include "minilibx_macOS/mlx.h"
# include <stdio.h>
# include "parser/parser.h"
# include "display/display.h"

# define CORRECT    1
# define INCORRECT  0
# define WIDTH      1000
# define HEIGHT     1000

typedef struct s_float {
    float   rez;
    float   fact;
    int     point_seen;
}           check_fl;

typedef struct s_mlx {
    void    *win;
    void	*mlx;
}       t_display;

typedef struct s_element {
    float       bright_diam_ratio;
    float       light_height_ratio;
    int         r_g_b[3];
    int         identifier_num;
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
    t_display   display;
}				t_scene;

void    ft_open(t_scene *scene, char *arg);

#endif //JENISH_MINIRT_H
