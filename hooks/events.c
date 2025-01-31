#include "../fdf.h"

int	handle_movement(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
		clean_mlx_infos(vars);
    return (0);
}
