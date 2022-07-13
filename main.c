#include "minirt.h"

int	main(int ac, char** ag)
{
    if (ac == 2)
    {
        t_scene scene;

        scene.ambient.identifier_num = 0;
        scene.camera.identifier_num = 0;
        scene.cylinder.identifier_num = 0;
        scene.light.identifier_num = 0;
        scene.plane.identifier_num = 0;
        scene.sphere.identifier_num = 0;
//        int d  = 43;
//        printf("%f\n", (float)d);
        ft_open(&scene, ag[1]);
        //check(&scene, ag[1]);
//        draw_map(&scene);
//        mlx_key_hook(scene.win, actions, &scene);
//        mlx_hook(scene.win, 17, 0, leave_game, &scene);
//        mlx_loop(scene.mlx);
    }
    return (0);
}
