

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

        ft_open(&scene, ag[1]);
        open_display(&scene);
//        mlx_key_hook(scene.display.win, actions, &scene);
//        mlx_hook(scene.display.win, 17, 0, leave_game, &scene);
        mlx_loop(scene.display.mlx);
    }
    else
        printf("The scene wasn't given!\n");
    return (0);
}
