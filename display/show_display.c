//
// Created by Hoover Brent on 7/22/22.
//

#include "display.h"

void	open_display(t_scene *scene)
{
    scene->display.mlx = mlx_init();
    scene->display.win = mlx_new_window(scene->display.mlx, WIDTH,
                                        HEIGHT, "My first RayTracer!");
    /*
    init_scene(scene);
    while (scene->y_ < scene->height)
    {
        scene->x_ = 0;
        while (scene->x_ < scene->width)
        {
            draw_certain(scene);
            scene->x_++;
        }
        scene->y_++;
    }
    */
    //mlx_string_put(scene->display.mlx, scene->display.win, 32, 32, 255255255, "0");
}
