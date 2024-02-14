# include <../minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

#include "../libft/libft.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int nScreanWidth = 120;
int nScreanHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14159/4;
float fDepth = 16.0f;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_img;

typedef struct  s_data
{
    void *mlx_ptr;
    void *win_ptr;
    t_img *img;
}t_data;

static void initData(t_data *data)
{
    data = malloc(1 * sizeof(t_data));
    data->img = malloc(1 * sizeof(t_img));
    mlx_init(data->mlx_ptr);
    data->win_ptr = mlx_new_window(data->mlx_ptr, 120, 40, "RAYCASTING");
    data->img->mlx_img = mlx_new_image(data->mlx_ptr, 120, 40);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
	&data->img->line_len, &data->img->endian);
}
static void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
 
    return (0);
}


//  int hande_move(int keysym, t_data *data)
// {
//     dprintf(1, "player x = %d", data->playerPos->x);
//     dprintf(1, "player y = %d", data->playerPos->y);
//     ft_error("moved well\n");
//     if (!move(keysym, data))
//     {
//         printf("player x = %d", data->playerPos->x);
//         dprintf(1, "player y = %d# include <minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

#include "libft/libft.h"

#include <stdio.h>
#include <stdbool.h>

int nScreanWidth = 120;
int nScreanHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14159/4;
float fDepth = 16.0f;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_img;

typedef struct  s_data
{
    void *mlx_ptr;
    void *win_ptr;
    t_img *img;
}t_data;

static void initData(t_data *data)
{
    data = malloc(1 * sizeof(t_data));
    data->img = malloc(1 * sizeof(t_img));
    mlx_init(data->mlx_ptr);
    data->win_ptr = mlx_new_window(data->mlx_ptr, 120, 40, "RAYCASTING");
    data->img->mlx_img = mlx_new_image(data->mlx_ptr, 120, 40);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
	&data->img->line_len, &data->img->endian);
}
static void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
 
    return (0);
}


//  int hande_move(int keysym, t_data *data)
// {
//     dprintf(1, "player x = %d", data->playerPos->x);
//     dprintf(1, "player y = %d", data->playerPos->y);
//     ft_error("moved well\n");
//     if (!move(keysym, data))
//     {
//         printf("player x = %d", data->playerPos->x);
//         dprintf(1, "player y = %d", data->playerPos->y);
//         // renderGame(game);
//     }
//     return (0);
// }

char map[16][16] ={"################",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"################"};
int main()
{
    t_data *data;

    initData(data);
    //data loop
    while(1)
    {
        for(int x = 0; x < nScreanWidth; x++)
        {
            //for each column calculate the projected ray angle into map
            //(fPlayerA - fFOV / 2.0f) : start of the raycast angle
            //((float)x / (float)nScreanWidth) * fFOV : end of the ray cast angle
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreanWidth) * fFOV;
            float fDistancetoWall = 0;
            /*to calculate the distance to wall, we need to calculate step by step anc check each time if we hit a wall!*/
            bool bHitWall = false;

            float fEyeX = sinf(fRayAngle); //Unit vector for ray in player space
            float fEyeY = cosf(fRayAngle);
            while(!bHitWall && fDistancetoWall < fDepth)
            {
                fDistancetoWall += 0.1f; /*a small step*/
                /*created a test point*/
                int nTestX = (int)(fPlayerA + fEyeX *fDistancetoWall);
                int nTestY = (int)(fPlayerA + fEyeY *fDistancetoWall);
                //test if ray is out of the bounds
                if (nTestX < 0 || nTestX > nMapWidth || nTestY < 0 || nTestY > nMapHeight)
                {
                    bHitWall = true; //just set distance to maximum depth
                    fDistancetoWall = fDepth;
                }
                else
                {
                    //Ray is inbounds so test to see if the aray cell is a wall black
                    if(map[nTestX *nMapWidth + nTestX] == '#')
                    {
                        bHitWall = true;
                        /*the wall distance is found*/
                    }
                }
            }
            //calculate distance to ceiling and floor
            int nCeiling = (float)(nScreanHeight / 2.0) - nScreanHeight / ((float)fDistancetoWall);
            int nFloor = nScreanWidth - nCeiling;

            for (int y = 0; y < nScreanHeight; y++)
            {
                if (y < nCeiling)
                   my_mlx_pixel_put(data->img,x,y,create_rgb(1,0,0));
                else if (y > nCeiling && y < nFloor)
                   my_mlx_pixel_put(data->img,x,y,create_rgb(0,1,0));
                else
                   my_mlx_pixel_put(data->img,x,y,create_rgb(0,0,1));
            }
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
           	// mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	        // mlx_key_hook(game->win_ptr, &hande_move, game);
            mlx_loop(data->mlx_ptr);
        }
    }
    return 0;
}", data->playerPos->y);
//         // renderGame(game);
//     }
//     return (0);
// }

char map[16][16] ={"################",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"#..............#",
"################"};
int main()
{
    t_data *data;
    data = NULL;
    initData(data);
    //data loop
    while(1)
    {
        for(int x = 0; x < nScreanWidth; x++)
        {
            //for each column calculate the projected ray angle into map
            //(fPlayerA - fFOV / 2.0f) : start of the raycast angle
            //((float)x / (float)nScreanWidth) * fFOV : end of the ray cast angle
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreanWidth) * fFOV;
            float fDistancetoWall = 0;
            /*to calculate the distance to wall, we need to calculate step by step anc check each time if we hit a wall!*/
            bool bHitWall = false;

            float fEyeX = sinf(fRayAngle); //Unit vector for ray in player space
            float fEyeY = cosf(fRayAngle);
            while(!bHitWall && fDistancetoWall < fDepth)
            {
                fDistancetoWall += 0.1f; /*a small step*/
                /*created a test point*/
                int nTestX = (int)(fPlayerA + fEyeX *fDistancetoWall);
                int nTestY = (int)(fPlayerA + fEyeY *fDistancetoWall);
                //test if ray is out of the bounds
                if (nTestX < 0 || nTestX > nMapWidth || nTestY < 0 || nTestY > nMapHeight)
                {
                    bHitWall = true; //just set distance to maximum depth
                    fDistancetoWall = fDepth;
                }
                else
                {
                    //Ray is inbounds so test to see if the aray cell is a wall black
                    if(*map[nTestX *nMapWidth + nTestX] == '#')
                    {
                        bHitWall = true;
                        /*the wall distance is found*/
                    }
                }
            }
            //calculate distance to ceiling and floor
            int nCeiling = (float)(nScreanHeight / 2.0) - nScreanHeight / ((float)fDistancetoWall);
            int nFloor = nScreanWidth - nCeiling;

            for (int y = 0; y < nScreanHeight; y++)
            {
                if (y < nCeiling)
                   my_mlx_pixel_put(data->img,x,y,create_rgb(1,0,0));
                else if (y > nCeiling && y < nFloor)
                   my_mlx_pixel_put(data->img,x,y,create_rgb(0,1,0));
                else
                   my_mlx_pixel_put(data->img,x,y,create_rgb(0,0,1));
            }
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
           	// mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	        // mlx_key_hook(game->win_ptr, &hande_move, game);
            mlx_loop(data->mlx_ptr);
        }
    }
    return 0;
}