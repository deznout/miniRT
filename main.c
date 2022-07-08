#include "minirt.h"

int	main(int ac, char **ag)
{
    if (ac == 2)
    {
        t_scene scene;

        ft_open(&scene, ag[1]);
        //check(&scene, ag[1]);
//        draw_map(&scene);
//        mlx_key_hook(scene.win, actions, &scene);
//        mlx_hook(scene.win, 17, 0, leave_game, &scene);
//        mlx_loop(scene.mlx);
    }
    return (0);
}
