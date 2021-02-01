/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:57:55 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/31 22:14:02 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define K_UP 65362
#define K_DOWN 65364
#define K_LEFT 65361
#define K_RIGHT 65363

void *mlx_ptr;
void *win_ptr;
char **map;
int width = 1500;
int height = 1000;
//design morba3 (map 2D)
char **line;
int y_len;
int x;
int y;
int k = 0;
int remaind = 50;
int none = 1;
//wall
int wall = 50;
int x_len_map;

int swiitch = 1;
// Player movement
double X_player;
double Y_player;   
int radian = 3;
double rotationAngle = 0;
double rotationSpeed = 3;
int len_angle = 30;
double turnDirection = 0;
int walkDirection = 0;
int j;
double rotation;

double rot;
//DATA COLLECTION FOR IMAGE 
int g_a;
int g_b;
int g_c;
int *g_data;
void *g_image;


//int k = 0;
//Remainding the old position of X && Y Player
int Y_remainder;
int X_remainder;
//Ray Intersaction && steps
 double xintercept;
 double yintercept;

 double ystep;
 double xstep;

    int g_remain_argc;
 double nextHoriX;
 double nextHoriY;
 //check if wall is hited
 double wallHoriHit;
 double wallVertHit;
 double HorizwallHitX;
 double HorizwallHitY;
 double VertwallHitX;
 double VertwallHitY;
 

 int color_c;
 int color_f;
 //delete
 int pc = 0;

 double WallHitX;
 double WallHitY;
// Ray Direction 
int rayFacingDown;
int rayFacingUp;
int rayFacingRight;
int rayFacingLeft;

// Distance between Vertical && Horizontal
double HorzHitDistance;
double VertHitDistance;
double distance;
double wasHitVertical;
//COLOR RENDERING
int alpha;
//key UP / DOWN
int up;
int down;
int left;
int right;
int a;
int d;
//Rendering 3D MAP
double correctWallDistance;
double distanceProjectionPlan;
double wallStripHeight;
double WallStripWidth = 1;
//color
unsigned int DarkColor;
//bullshit variables for data (LEARN LATER)
int tab[20];
void *img1;
void *img2;
void *img3;
void *img4;
unsigned int *textu0;
unsigned int *textu1;
unsigned int *textu2;
unsigned int *textu3;
unsigned int *textu4;
double xOfsset;
double yOffset;
int g_mhah;
double g_pourcent;
char **copy;
int copystart;
int f;
int g_rightleftupdown;
int N;
//The Raycasting variables
//indicateur pour le stockage
int g_f;
//double isRaydown = ;
int calculparam_x = 50 / 2;
int calculparam_y = 50 / 2;
    int sprite;
int distance_center;
int sprite_indicator;

//// SAVE X AND Y CENTER;
int center_x;
int center_y;

char **check;
////////////
int sprite_number;
int dontenteragain;

typedef struct s_sprite
{
double wallVertHit;
double VertwallHitX;
double VertwallHitY;
double wallHoriHit;
double HorizwallHitX;
double HorizwallHitY;
double g_mhah;
double wasHitVertical;
double VertHitDistance;
double HorzHitDistance;
double WallHitX;
double WallHitY;
double xcentre;
double ycentre;
double distance;
double rotation;
double x;
double y;
double xoff;
}               t_sprite;
t_sprite sprites[1000], sprites_temp;

typedef struct s_spritefinder
{
    double point_x;
    double point_y;
    double point_distance_x;
    double point_distance_y;
    double new_angle;
    double x_offset;
    double angle_sghira;
    double angle_kbira;
    double angle_wanted;
    double angle_jdida;
    double center_x;
    double center_y;
}               t_spritefinder;
t_spritefinder finder;

int sprite_count;
typedef struct s_mapcount
{
    int mapx;
    int strx;
    int linex;
    int lenghtx;
}               t_mapcount;
t_mapcount mapcount[1000];

int inde;

typedef struct s_direction
{
    int we;
    int ea;
    int su;
    int no;
    int r;
    int s;
    int f;
    int c;
}               t_direction;
t_direction direction;

typedef struct s_screenmap
{
    char *header;
    short int bit_count;
    unsigned int width;
    unsigned int height;
    int width_in_byte;
    unsigned int image_size;
    unsigned int size_header;
    unsigned int offset_bits;
    int file_size;
    short int planes;
    int fd;
    char *img;

}               t_screenmap;
t_screenmap screenmap;
char *g_chorfi;
char *mapo;
char *map_fd;
int t = 0;
int empty_line;
int g_fd;
int g_indexo;

int g_calcul_parameter;

int     design_morba3(int i, unsigned int color, int j)
{
    int save;
    int y_copy;

    y_copy = y;
    save = k;

   // i = i + 1;

    while (k < x)
    {
        if(swiitch == 0)
            mlx_pixel_put(mlx_ptr, win_ptr, k, y, color);
        k++;
        if (k == x)
        {
            k = save;
            y = y - 1;
            if (y == remaind - wall - 1)
            {
                k += wall;
                break;
                }
            }
    }

    if ((line[j][i] == 'N' || line[j][i] == 'E' || line[j][i] == 'W' || line[j][i] == 'S' ) && none == 1)
    {
        if (swiitch == 0)
            mlx_pixel_put(mlx_ptr, win_ptr, k, y, 0x000000);
       // X_player = k - 1;
      // Y_player = y ;
        X_player = i * 50 + 25;
        Y_player = j * 50 + 25;

        none++;
    }
    y = y_copy;
    x = x + wall;
    return k;
}

void	sorting(void)
{
	int indd;
	int j;

	indd = 1;
	j = 0;
	while (indd < sprite_count)
	{
		while (j < sprite_count - indd)
		{
			if (sprites[j].distance > sprites[j + 1].distance)
			{
				sprites_temp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = sprites_temp;
			}
			j++;
		}
		j = 0;
		indd++;
	}
    sprites[sprite_count].distance = '\0';
}
void ft_directions(int j,int i)
{
    if (line[j][i] == 'N')
        rotationAngle = 3 * (M_PI)/2;
    else if (line[j][i] == 'S')
        rotationAngle = M_PI / 2;
    else if (line[j][i] == 'W')
        rotationAngle = 0;
    else if (line[j][i] == 'E')
        rotationAngle = M_PI;

}
void ft_morba3()
{
    int i;
    unsigned int color;
    sprite_number = 0;

    N = 0;
    i = 0;
    j = 0;
    while(j < inde && line[j][i])
    {
        if (line[j][i] == '1'  || line[j][i] == ' ')
        {
            color = 0x6f665d;
            design_morba3(i, color, j);
        }
        else if(line[j][i] == '0' || line[j][i] == 'N' || line[j][i] == 'E' || line[j][i] == 'W' || line[j][i] == 'S')
        {
            color = 0xFFFFFF;
            design_morba3(i, color, j);
            if(line[j][i] == 'N' || line[j][i] == 'E' || line[j][i] == 'W' || line[j][i] == 'S')
            {
                N++;
                ft_directions(j,i);
            }
        }
        else if(line[j][i] == '2')
        {
            color = 0xdcd3f6;
            design_morba3(i, color, j);
            sprite_number++;
        }
        i++;
        if (line[j][i] == '\0')
        {
            i = 0;
            if (j < inde) //line[j + 1] != NULL)
            {
                j++;
                y = y + wall;
                x = wall;
                remaind = remaind + wall;
                k = 0;
            }
            else
                break;
        }    
    }
}





int abs (int n)
{ 
    return ( (n>0) ? n : ( n * (-1))); 
}

unsigned int    *ft_texture(char     *file, unsigned int *texture)
{
    g_f = 0;
    int c = 63;
    int i= 0;
    img1 = mlx_xpm_file_to_image(mlx_ptr,file,&tab[g_f],&tab[g_f + 1]);
    if ((int)(img1) == 0)
    {
        ft_putstr("INVALID MAP");
        exit (0);
    }
    texture = (unsigned int *)mlx_get_data_addr(img1,&tab[g_f + 2],&tab[g_f + 3], &tab[g_f + 4]);
    g_f = g_f + 5;
    return texture;
}

//DDA Function for line generation 
void DDA(int X0, int Y0, int X1, int Y1) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    double Xinc = dx / (double) steps; 
    double Yinc = dy / (double) steps; 
  
    // Put pixel for each step 
    double X = X0; 
    double Y = Y0; 

    int i = 0;
    i = ft_strlen(line[0]);
    for (int i = 0; i <= steps; i++) 
    { 
       
        if(X >= 0 && X <= i * 50 && Y >= 0 && Y <= inde * 50)
        {
            if(swiitch == 0)
           mlx_pixel_put(mlx_ptr, win_ptr, X, Y, 0xFF0000);
        }
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
         // for visualization of line- 
                             // generation step by step 
    } 
} 
//FUNCTION TO COVERT HEXA TO RGB
unsigned int    convert_rgb(int r, int g, int b)
{
    unsigned int color;
    color = r;
    color = (color << 8) + g;
    color = (color << 8) + b;
    return (color);
} 
unsigned int    check_opacity(unsigned int hexcolor)
{
    double red;
    double green;
    double blue;
    double oppasity;

    oppasity = (distance / 1600) > 1 ? 1 : 1 - (distance / 1600) ;
    red = ((hexcolor >> 16) & 255) * oppasity;
    green = ((hexcolor >> 8) & 255) * oppasity;
    blue = (hexcolor & 255) * oppasity;
    return (convert_rgb(red, green, blue));
}

int wall_checker()
{
    int X_pos;
    int Y_pos;
    int i;

    X_pos = nextHoriX / wall;
    Y_pos = nextHoriY / wall;
    if ((X_pos >= 0 &&  X_pos <= mapcount[0].lenghtx) && (Y_pos >= 0 &&  Y_pos < inde))
    {

        if (line[Y_pos][X_pos] == '2')
        {
            sprite = 1;
            sprite_indicator = 1;
        }
        if (line[Y_pos][X_pos] == '1')
            return (1);
        
    }
    return 0;

}
 int wall_collision()
{
    int X_pos;
    int Y_pos;

    X_pos = X_remainder / wall;
    Y_pos = Y_remainder / wall;
    if (line[Y_pos][X_pos] == '1' || line[Y_pos][X_pos] == '2')
    {
        return (1);
    }
    return 0;

}

double ft_normalize_angle(double angle)
{
    while (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    while (angle < 0)
        angle += (2 * M_PI);
    return (angle);
}

void ft_nizar_calcul()
{
     if(g_mhah)
    {
        if (rayFacingDown)
        {
           g_rightleftupdown = 1;
        }
        else if (rayFacingUp)
        {
          g_rightleftupdown = 2;
        }
    }
    else if(!g_mhah)
    {
        if (rayFacingLeft)
        {
           g_rightleftupdown = 3;
        }
        else if (rayFacingRight)
        {
           g_rightleftupdown = 4;
        }
    }
}
void render_column1(int i, int count)
{
        int start;
    int j;
    int p = 0;
    j = 0;
    start = (height / 2) - (wallStripHeight / 2);
   // unsigned int colorr;
    //if (start < 0)
       // start = 0;
    // modification is here
    
    while(j < start)
    {
        g_data[width * j + i] = color_c;//+ pc;
         j++;
    }
    
    while(j < start + wallStripHeight && j < height)
    {
        g_pourcent = (j - start) / wallStripHeight;
            yOffset = 50 * g_pourcent;
        
            if(check_opacity(textu0[(int)yOffset * 50 + (int)sprites[count].xoff]) != 0x000000)
            {
                g_data[width * j + i] = check_opacity(textu0[(int)yOffset * 50 + (int)sprites[count].xoff]);
            }
            if(swiitch == 0)
                mlx_pixel_put(mlx_ptr,win_ptr,i,j,0x006400);
        j++;
    }
    while(j < height)
    {
         g_data[width * j + i] = color_f;// + pc;
         j++;
    }

}
void render_colomn(int i)
{
    int start;
    int j;
    int p = 0;
    j = 0;
    start = (height / 2) - (wallStripHeight / 2);
    //if (start < 0)
       // start = 0;
    // modification is here
    
    while(j < start)
    {
        g_data[width * j + i] = color_c;
         j++;
    }
    while(j < start + wallStripHeight && j < height)
    {
        g_pourcent = (j - start) / wallStripHeight;
            yOffset = 50 * g_pourcent;
            if(g_rightleftupdown == 1)
            {
                g_data[width * j + i] = check_opacity(textu4[(int)yOffset * 50 + (int)xOfsset]);
            }
            else if(g_rightleftupdown == 2)
            {
                g_data[width * j + i] = check_opacity(textu1[(int)yOffset * 50 + (int)xOfsset]);
            }
            else if(g_rightleftupdown == 3)
            {
                g_data[width * j + i] = check_opacity(textu2[(int)yOffset * 50 + (int)xOfsset]);
            }
            else if(g_rightleftupdown == 4)
            {
                g_data[width * j + i] = check_opacity(textu3[(int)yOffset * 50 + (int)xOfsset]);
            }
         /*   else if(sprite == 1)
            {
                g_data[1000 * j + i] = 0;
            } */

            if(swiitch == 0)
                mlx_pixel_put(mlx_ptr,win_ptr,i,j,0x006400);
        j++;
    }
    while(j < height)
    {
         g_data[width * j + i] = color_f;
         j++;
    }
    
}

void render_map3D(int i)
{
    correctWallDistance = distance * cos(rotation - rotationAngle);
   // alpha = 80 / correctWallDistance;
    distanceProjectionPlan = (width / 2) / tan(rad(45) / 2); //here delete cos
    wallStripHeight = (50 / correctWallDistance) * distanceProjectionPlan;
    xOfsset = g_mhah == 1 ? fmod(WallHitX,50) : fmod(WallHitY,50);
           ft_nizar_calcul();
        //Modification here 2  
        if(swiitch == 1)
            render_colomn(i);
}
void BubbleSort1(int sprite_count)
{
    int i, j, temp;
    for (i = 0; i < (sprite_count - 1); ++i)
    {
        for (j = 0; j < sprite_count - 1 - i; ++j )
        {
            if (sprites[j].distance > sprites[j + 1].distance)
            {
                temp = sprites[j + 1].distance;
                sprites[j + 1].distance = sprites[j].distance ;
                sprites[j].distance = temp;
            }
        }
    }
}
int ray_Direction()
{
    rayFacingDown = 0;
    rayFacingUp = 0;
    rayFacingRight = 0;
    rayFacingLeft = 0;

    rayFacingDown = (deg(rotation) > 0 && deg(rotation) < 180) ? 1 : 0;
    rayFacingUp = !(rayFacingDown) ? 1 : 0;

    rayFacingRight = ((deg(rotation) > 0 && (deg(rotation) < 90)) || (deg(rotation) > 270 && (deg(rotation) < 360))) ? 1 : 0;
    rayFacingLeft = !(rayFacingRight) ? 1 : 0;
  
     return 0;

}
double Distance_between_HorVer(int x1,int y1, int x2, int y2)
{
    return sqrtf(powf((x2 - x1),2) + powf((y2 - y1),2));
}


int ft_cast_ray(int index)
{
    WallHitX = 0;
    WallHitY = 0;
    distance = 0;
    sprite = 0;
    int i = 0;
    sprite_indicator = 0;
    int stop = 1;
    int check;
    wallHoriHit = 0;
    ray_Direction();

    yintercept = (int)(Y_player / wall) * wall;
    yintercept += rayFacingDown ? wall : 0;
    xintercept = X_player + (yintercept - Y_player) / tan(rotation);

    ystep = wall;
    ystep *= rayFacingUp ? -1 : 1;

    // ==> 
    xstep = ystep / tan(rotation);
    // ==>
    //xstep *= (rayFacingLeft && xstep > 0) ? -1 : 1;
    //xstep *= (rayFacingRight && xstep < 0) ? -1 : 1;

    nextHoriX = xintercept;
    nextHoriY = yintercept;

    if(rayFacingUp)
        nextHoriY--;
    int here;
    here = ft_strlen(line[0]);
        //increment x & y step until we find  a wall
    while(nextHoriX >= 0 && nextHoriX < mapcount[0].lenghtx * 50 && nextHoriY >= 0 && nextHoriY < inde * 50)
    {
        sprite = 0;
        check = wall_checker();
        // if(sprite_count > 6)
        //     exit(0);
        if(sprite == 1)
        {
            sprites[sprite_count].xcentre = ((int)nextHoriX / 50 * 50) + 25;
            sprites[sprite_count].ycentre = ((int)nextHoriY / 50 * 50) + 25;
            sprites[sprite_count].x = nextHoriX;
            sprites[sprite_count].y = nextHoriY;
            sprites[sprite_count].distance =  sqrtf(powf(Y_player - sprites[sprite_count].y,2) + powf(X_player - sprites[sprite_count].x,2));
            sprites[sprite_count].rotation = atan2(Y_player - nextHoriY,  X_player - nextHoriX);
            sprite_count++;

        }
        if (check == 1)
        {
            wallHoriHit = 1;
            HorizwallHitX = nextHoriX;
            HorizwallHitY = nextHoriY;
            //DDA(X_player, Y_player,  HorizwallHitX, HorizwallHitY);
            break;
        }
        else
        {
            nextHoriX += xstep;
            nextHoriY += ystep; 
        }
    }
    // VERITICAL RAYCAST
    //sprites[sprite_count].
    wallVertHit = 0;
    ray_Direction();
    xintercept = (int)(X_player / wall) * wall;
    xintercept += rayFacingRight ? wall : 0;
    yintercept = Y_player - (X_player - xintercept) * tan(rotation);

    xstep = wall;
    xstep *= rayFacingLeft ? -1 : 1;
    // ==>
    ystep = xstep * tan(rotation);
    // == <
    //ystep *= (rayFacingUp && ystep > 0) ? -1 : 1;
    //ystep *= (rayFacingDown && ystep < 0) ? -1 : 1;

    nextHoriX = xintercept;
    nextHoriY = yintercept;

    if(rayFacingLeft)
        nextHoriX--;
    //int k = 0;
    while(nextHoriX >= 0 && nextHoriX < mapcount[0].lenghtx * 50 && nextHoriY >= 0 && nextHoriY < inde * 50)
    {
        //k++;
        sprite = 0;
        check = wall_checker();
        if(sprite == 1)
        {
            //ft_putstr("%d\n",sprite_count);
            sprites[sprite_count].xcentre = ((int)nextHoriX / 50 * 50) + 25;
            sprites[sprite_count].ycentre = ((int)nextHoriY / 50 * 50) + 25;
            sprites[sprite_count].rotation = atan2(Y_player - nextHoriY,  X_player - nextHoriX);
            sprites[sprite_count].x = nextHoriX;
            sprites[sprite_count].y = nextHoriY;
            sprites[sprite_count].distance =  sqrtf(powf(Y_player - sprites[sprite_count].y,2) + powf(X_player - sprites[sprite_count].x,2));
            sprite_count++;
        }
       // BubbleSort1(sprite_count);
        if (check == 1)
        {
            wallVertHit = 1;
            VertwallHitX = nextHoriX;
            VertwallHitY = nextHoriY;
          //  DDA(X_player, Y_player,  HorizwallHitX, HorizwallHitY);
            break;
        }
        else
        {
            nextHoriX += xstep;
            nextHoriY += ystep; 
        }

    }

    // The Distance between vert and horizontal distances and precist the smallest value

    HorzHitDistance = (wallHoriHit) ? Distance_between_HorVer(X_player , Y_player, HorizwallHitX,HorizwallHitY) : MAX_INT;
    VertHitDistance = (wallVertHit) ? Distance_between_HorVer(X_player , Y_player, VertwallHitX,VertwallHitY) : MAX_INT;
// store the smallest of the distances

    WallHitX = (HorzHitDistance) < (VertHitDistance) ? HorizwallHitX : VertwallHitX;
    WallHitY = (HorzHitDistance) < (VertHitDistance) ? HorizwallHitY : VertwallHitY;
    distance = (HorzHitDistance) < (VertHitDistance) ? HorzHitDistance : VertHitDistance;
    g_mhah = distance == HorzHitDistance ? 1 : 0;
    wasHitVertical = (VertHitDistance) < (HorzHitDistance);
    
    DarkColor = 0x006400;
    DarkColor = check_opacity(DarkColor);
    
      
    DDA(X_player,Y_player,WallHitX,WallHitY);

   return 0;
}

int mlx_key_press(int key)
{
    if(key == 123)
        left = 1;
    if (key == 124)
        right = 1;
    if (key == 125)
        down = 1;
    if (key == 126)
        up = 1;
    if (key == 0)
        a = 1;
    if (key == 2)
        d = 1;
    if (key == 53)
    {
        exit(0);
    }
    return 0;
}
int key_release(int key)
{
    if(key == 123)
        left = 0;
    if(key == 124)
        right = 0;
    if (key == 125)
        down = 0;
    if (key == 126)
        up = 0;
    if (key == 0)
        a = 0;
    if (key == 2)
        d = 0;
    return 0;
}

void render_sprite(int i)
{
    if (sprite_indicator == 1)
    {
        int ind = 0;
        int count = sprite_count - 1;
        double angle_wanted,angle_sghira,point_x,point_y,point_distance_x,point_distance_y;
        double angle_jdida;
        //sorting();
        while (count >= 0)
        {
            angle_sghira = atan2(Y_player - sprites[count].ycentre, X_player - sprites[count].xcentre);
            angle_wanted = sprites[count].rotation - angle_sghira;

            point_x = X_player + (sprites[count].xcentre - X_player) * cos(angle_wanted) - (sprites[count].ycentre - Y_player) * sin(angle_wanted);
            point_y = Y_player + (sprites[count].xcentre - X_player) * sin(angle_wanted) + (sprites[count].ycentre - Y_player) * cos(angle_wanted);
            angle_jdida = M_PI / 2 + angle_sghira;
            point_distance_x = sprites[count].xcentre + (50 / 2) * cos(angle_jdida);
            point_distance_y = sprites[count].ycentre + (50 / 2) * sin(angle_jdida);
            sprites[count].xoff = sqrtf(powf(point_distance_y - point_y,2) + powf(point_distance_x - point_x,2));
            double diss = sqrtf(powf(point_x - sprites[count].xcentre,2) + powf(point_y - sprites[count].ycentre,2));
            if (diss > 25)
                sprites[count].xoff = 0;
         
            correctWallDistance = sqrtf(powf((Y_player - sprites[count].ycentre), 2)
					+ powf((X_player - sprites[count].xcentre), 2));
  
    
   // alpha = 80 / correctWallDistance;
    distanceProjectionPlan = (width / 2) / tan(rad(45) / 2); //here delete cos
    wallStripHeight = (50 / correctWallDistance) * distanceProjectionPlan;
  //  finder.x_offset = sprites[sprite_count].g_mhah == 1 ? fmod(sprites[sprite_count].WallHitX,50) : fmod(sprites[sprite_count].WallHitY,50);
    ft_nizar_calcul();
        //Modification here 2
 
            if(swiitch == 1)
            {
                if (sprites[count].distance < distance)
                    render_column1(i,count);
            }  
            count--;
        }
    
    }
}
int deal_key(void)
{
    int p = 0;
    x = wall;
    y = wall;
    k = 0;
    int i = 0;
    int j = 0;
    int ray_lenght;
    int sp_c = 0;
    remaind = wall;
   // ft_morba3(line);
   // mlx_clear_window(mlx_ptr,win_ptr);
    rotation = rotationAngle - M_PI / 8;
      //ft_putstr("++++++%lf\n",deg(rotation));
    //rot = rad(45) / width;
    sprite_count = 0;
    if (rotationAngle > 2 * M_PI || rotationAngle < 0)
            rotationAngle = ft_normalize_angle(rotationAngle);
 

    while(i < width)
    {
        if (rotation > 2 * M_PI || rotation < 0)
            rotation = ft_normalize_angle(rotation);
        //DDA(X_player, Y_player,  wallHitX, wallHitY);
        ft_cast_ray(i);

        rotation += rot;
        // if(sprite == 0)
        render_map3D(i);
        sorting();
        if(sprite_indicator == 1 )
        {
            //  while(sp_c < sprite_count)
            //  {
                if (sprites[0].distance < distance)
                {
                    render_sprite(i);
                }
                
            //     sp_c++;
            //  }
           
            
             sprite_count = 0;
        }
        i++;

    }
    if (strcmp(g_chorfi,"--save") == 0)
        screenshot();
    if(down == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder -= cos(rotationAngle) * 4;
        Y_remainder -= sin(rotationAngle) * 4;
        p = wall_collision();
        if (p != 1)
        {
            X_player -= cos(rotationAngle) * 4;
            Y_player -= sin(rotationAngle) * 4;
        } 
    }
    else if (up == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder += cos(rotationAngle) * 4;
        Y_remainder += sin(rotationAngle) * 4;
         p = wall_collision();
        if (p != 1)
        {
            X_player += cos(rotationAngle) * 4;
            Y_player += sin(rotationAngle) * 4;
        } 
    }
    if(d == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder -= cos(rotationAngle - M_PI / 2) * 10;
        Y_remainder -= sin(rotationAngle - M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            X_player -= cos(rotationAngle - M_PI / 2) * 10;
            Y_player -= sin(rotationAngle - M_PI / 2) * 10;
        }
    }
    if(a == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder -= cos(rotationAngle + M_PI / 2) * 10;
        Y_remainder -= sin(rotationAngle + M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            X_player -= cos(rotationAngle + M_PI / 2) * 10;
            Y_player -= sin(rotationAngle + M_PI / 2) * 10;
        }
    }
    if (left == 1)
    {
         rotationAngle -= rad(rotationSpeed);
    }
    if (right == 1)
    {
         rotationAngle += rad(rotationSpeed);
    }
    return 0;
}

int    ft_exit()
{
    mlx_destroy_window(mlx_ptr,win_ptr);
    exit(0);
}

int loop_key()
{

   /*textu1 = "ayoub.xpm";
    textu2 = "maroc.xpm";
    textu3 = "shanks.xpm"; */

    if (strcmp(g_chorfi,"--save") != 0)
    {
        mlx_hook(win_ptr,2,0,mlx_key_press,0);
        mlx_hook(win_ptr,3,0,key_release,0);
        mlx_hook(win_ptr,17,0L,ft_exit,0);
    }
    deal_key();
    // modification 3
    //mlx_clear_window(mlx_ptr,win_ptr);
    if(swiitch == 1)
        mlx_put_image_to_window(mlx_ptr,win_ptr,g_image,0,0);
    
    //ft_texture();
    return 0; 
}
int ft_last_line()
{
    int i = 0;
   // int c = 0;
    while(strchr("1 ",line[inde][i]))
    {
        i++;
        if(line[inde][i] == ' ' && line[inde - 1][i] == '0')
            break;
        if(line[inde][i] == '\0')
            return(1);
    }
    ft_putstr("errormap\n");
    exit(0);
    return(0);
}

int ft_first_line()
{
    int i = 0;
   // int c = 0;
    while(strchr("1 ",map[y_len][i]))
    {
        i++;
        if(map[y_len][i] == '\0')
            return(1);
    }
    return(0);
}
int ft_valid_map()
{
    int i = 0;
   // int c = 0;

    while(strchr("012NWES ",map[y_len][i]))
    {
        i++;
        if(map[y_len][i] == '\0')
            return(1);
    }
    return(0);
}

void ft_check_zero()
{
    int i;
    int j;
    int p;

    i = 0;
    j = 0;
    while(line[j][i] && inde > j)
    {
        if(line[j][i] == '0')
        {
            if(line[j][0] == '0' || line[j][i + 1] == ' ' || line[j][i - 1] == ' ' || line[j - 1][i] == ' ' || line[j][i + 1] == '\0' || line[j + 1][i] == ' ')
            {
                ft_putstr("error in map");
                exit (0);
            }
        }
        else if(line[j][i] == '2')
        {
            if(line[j][i] == '2' && (line[j][i + 1] == ' ' || line[j][i - 1] == ' ' || line[j + 1][i] == ' '|| line[j - 1][i] == ' '))
            {
                ft_putstr("error in map");
                exit (0);
            }
        }
        i++;
        if (line[j][i] == '\0' && inde > j)
        {
            i = 0;
            if (line[j + 1] == NULL)
                break;
            else
                j++;
            
        }

    }
}


void BubbleSort(int inde)
{
    int i, j, temp;
    for (i = 0; i < (inde - 1); ++i)
    {
        for (j = 0; j < inde - 1 - i; ++j )
        {
            if (mapcount[j].lenghtx < mapcount[j+1].lenghtx)
            {
                temp = mapcount[j+1].lenghtx;
                mapcount[j+1].lenghtx = mapcount[j].lenghtx;
                mapcount[j].lenghtx = temp;
            }
        }
    }
}
void fd_tab2(int fd)
{
    int j = 0;
    int c = 0;
    int f = 0;
    
    c = ft_valid_map();
    // = ft_check_zero();
  
        if(c == 1)
        line[inde] = strdup(map[y_len]);
        else
        {
            ft_putstr("error in map");
            exit(0);
        }  
}
int check_valid(char *check)
{
    char *str;
    str = strchr(check,'.');
    if(!str)
    {
        ft_putstr("invalid texture");
        exit(0);
    }
    if(strcmp(str,".xpm") == 0)
        return (1);
    return(0);
}
void ft_check_weird()
{
    int i = 0;
    while(check[1][i])
    {
        if(!((check[1][i] >= '0' && check[1][i] <= '9') || check[1][i] == ','))
        {
            ft_putstr("weirdooo a khey malaoui o yahya 39t bikom");
            exit(0);
        }
        i++;
    }
}

void ft_check_virg()
{
    int i;

    i = 0;
    while(check[1][i])
    {
        if(check[1][i] == ',')
            g_split++;
        i++;
    }
}
void ft_check_resolution()
{
    if(width > 2560 || height > 1440)
    {
        if (width > 2560)
            width = 2560;
        else
            height = 1440;
        
    }
}
void ft_check(int fd,int t,int c)
{
    //int i = 0;
    int i = 0;
    int k = 0;
    char *tmp;
    f = 0;
    static int p = 0;
   
if(*check != NULL)
{
     if (strcmp(check[0],"R") == 0)
     {
         direction.r++;
        if(counter != 3)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
        width = atoi(check[1]);
        height = atoi(check[2]);
        if(width < 0 || height < 0)
        {
            ft_putstr("invalid resolution\n");
            exit (0);
        }
        ft_check_resolution();
        g_calcul_parameter++;
     }
     else if(strcmp(check[0],"NO") == 0)
     {
         direction.no++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         f = check_valid(check[1]);
         if (f == 1)
            textu1 = ft_texture(check[1], textu1);
            if (f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
         g_calcul_parameter++;
     }
     else if(strcmp(check[0],"WE") == 0)
     {
         direction.we++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
          f = check_valid(check[1]);
         if (f == 1)
            textu2 = ft_texture(check[1], textu2);
            if (f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
         g_calcul_parameter++;
     }
     else if(strcmp(check[0],"SO") == 0)
     {
         direction.su++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         f = check_valid(check[1]);
         if (f == 1)
            textu3 = ft_texture(check[1], textu3);
            if (f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
            g_calcul_parameter++;
         
     }
     else if(strcmp(check[0],"EA") == 0)
     {
         direction.ea++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         f = check_valid(check[1]);
         if (f == 1)
            textu4 = ft_texture(check[1], textu4);
            if (f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
            g_calcul_parameter++;
         
     }
     else if(strcmp(check[0],"S") == 0)
     {
         direction.s++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         f = check_valid(check[1]);
         if (f == 1)
            textu0 = ft_texture(check[1], textu0);
            if (f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
            g_calcul_parameter++;
     }
     else if(strcmp(check[0],"C") == 0)
     {
         char *tmp; //////

         direction.c++;
        if(counter != 2 )
        {
            ft_putstr("missing parameter");
            exit(0);
        }
        ft_check_weird();
        ft_check_virg();
        tmp = ft_strdup(check[1]);
        free(check[0]);
        free(check[1]);
        free(check);
        if(g_split != 2)
        {
            ft_putstr("error in parameter");
            exit (0);
        }
        check = ft_split(tmp,',');
        free(tmp);
        if (counter != 3 || atoi(check[0]) > 255 || atoi(check[0]) < 0 || atoi(check[1]) > 255 || atoi(check[1]) < 0 || atoi(check[2]) > 255 || atoi(check[2]) < 0)
        {
            ft_putstr("INVALID MAP\n");
            exit (0);
        }
         color_c = convert_rgb(atoi(check[0]), atoi(check[1]), atoi(check[2]));
         g_calcul_parameter++;
     }
      else if(strcmp(check[0],"F") == 0)
     {
         direction.f++;
         ft_check_weird();
        if(counter != 2 )
        {
            ft_putstr("missing parameter");
            exit(0);
        }
        ft_check_virg();
        if(g_split != 2)
        {
            ft_putstr("error in parameter");
            exit (0);
        }
        tmp = ft_strdup(check[1]);
        free(check[0]);
        free(check[1]);
        free(check);
        check = ft_split(tmp,',');
        free(tmp);
        if (counter != 3 || atoi(check[0]) > 255 || atoi(check[0]) < 0 || atoi(check[1]) > 255 || atoi(check[1]) < 0 || atoi(check[2]) > 255 || atoi(check[2]) < 0)
        {
            ft_putstr("INVALID MAP\n");
            exit (0);
        }
         color_f = convert_rgb(atoi(check[0]), atoi(check[1]), atoi(check[2]));
         g_calcul_parameter++;

     }
     else if(strchr("1 0", map[y_len][0]) && mapcount[t].mapx > 0)
        {
            if(strchr("1 0", map[y_len][0]) && mapcount[t].mapx > 0)
            {
                ft_return();
                ft_switch_space();
                //k = ft_first_line();
                //ft_putstr("ll%dll\n",mapcount[t - 1].mapx);
                if(dontenteragain == 10 && mapcount[t - 1].mapx == 0)
                {
                    ft_putstr("invalid mapox");
                    exit(0);
                }
                    
                if (dontenteragain == 0)
                {
                    k = ft_first_line();
                    if (k == 0)
                    {
                        ft_putstr("invalid mape");
                        exit(0);
                    }
                    else if (k == 1)
                    {
                        line[inde] = strdup(map[y_len]);
                        dontenteragain = 10;
                    }
                }
                else
                {
                    fd_tab2(fd);

                }
                mapcount[p].linex = ft_strlen(line[inde]);
               // ft_putstr("%d\n",inde);
                inde++;
                p++;
             }
        }
        else
        {
            ft_putstr("weird character");
            exit(0);
        }
}
}


void ft_return()
{
    if(direction.c != 1 || direction.we != 1|| direction.ea != 1 || direction.f != 1 || direction.su != 1 || direction.no != 1 || direction.r != 1 || direction.s != 1)
    {
        ft_putstr("missing or multiple parameter");
        exit(0);
    }
}
int  fd_tab(int fd)
{
    int ayoouub=0;
    char **str;
    int c = 0;
    int lenght = 0;
    g_calcul_parameter = 0;
    y_len = 0;
    map = malloc(sizeof(char *) * (g_indexo + 2));
    str = malloc(sizeof(char *) * (g_indexo + 2));
    empty_line = 0;
    while(get_next_line(fd,&str[lenght]))
    {
        if(ft_strlen(str[lenght]) == 0)
            empty_line++;
        map[y_len] = ft_strdup(str[lenght]);
        if(ft_strchr("1 0", str[lenght][0]))
        {
            mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
        }

        lenght++;
        y_len++;
    }
    
    map[y_len] = ft_strdup(str[lenght]);
    mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
    map[++y_len] = NULL;
    str[y_len] = NULL;
    
    ft_free_l3alam(str);
    BubbleSort(lenght);
     
    y_len = 0;
    int k = 0;
    //ft_putstr("%d\n",lenght - empty_line);
    while(y_len <= lenght)
    {
        
        mapcount[t].mapx = ft_strlen(map[y_len]);
        
        if(mapcount[t].mapx > 0)
        {   
            g_split = 0;
            if(g_calcul_parameter <= 8)
                check = ft_split(map[y_len],' ');
            ft_check(fd,t,c);
            if(g_calcul_parameter <= 8)
                ft_free_l3alam1();
        }       
        t++;
        y_len++;
    }
   
    
    ft_return();

    inde--;
    ft_last_line();
    ft_free_l3alam(map);
    line[++inde] = NULL;
    y_len++;
}

void ft_switch_space()
{
    int i = 0;
    int j = 0;
    char *tmp;
    int f = 0;
    int variable;
    char *str;
    variable = ft_strlen(map[y_len]);
   
  
    
        i = mapcount[0].lenghtx - variable;
        str = malloc(sizeof(char) * i + 1);
        f = 0;
        while(i > f)
        {
            str[f] = ' ';
            f++;
        }
        str[f] = '\0';
        tmp = ft_strdup(map[y_len]);
        free(map[y_len]);
        map[y_len] = ft_strjoin(tmp, str);
        free(tmp);
        free(str);
}
void ft_header(void)
{
    screenmap.header = ft_calloc(54,1);
    screenmap.bit_count = 24;
    screenmap.width = width;
    screenmap.height = height;
    screenmap.width_in_byte = ((screenmap.width * screenmap.bit_count + 31) / 32) * 4;
    screenmap.image_size = screenmap.width_in_byte * screenmap.height;
    screenmap.size_header = 40;
    screenmap.offset_bits = 40 + 14;
    screenmap.file_size = screenmap.offset_bits + screenmap.image_size;
    screenmap.planes = 1;
    ft_memcpy(screenmap.header , "BM" , 2);
    ft_memcpy(screenmap.header + 2, &screenmap.file_size, 4);
    ft_memcpy(screenmap.header + 10, &screenmap.offset_bits, 4);
    ft_memcpy(screenmap.header + 14 , &screenmap.size_header, 4);
    ft_memcpy(screenmap.header + 18, &screenmap.width, 4);
    ft_memcpy(screenmap.header + 22 , &screenmap.height, 4);
    ft_memcpy(screenmap.header + 26 , &screenmap.planes, 2);
    ft_memcpy(screenmap.header + 28, &screenmap.bit_count, 2);
    ft_memcpy(screenmap.header + 34 , &screenmap.image_size, 4);
}
int *get_color(int coloor)
{
    int *colors;
    colors = malloc(3 * sizeof(int));
    colors[0] = ((coloor >> 16) & 0xFF);
    colors[1] = ((coloor >> 8) & 0xFF);
    colors[2] = ((coloor) & 0xFF);
    return (colors);

}

void			ft_free_l3alam1()
{
    int j;

    j = 0;
        while (check[j])
	    {
		    free(check[j]);
		    j++;
	    }
	    free(check);
	

}

void			ft_free_l3alam(char **tab)
{
    int j;

     j = 0;
     int ayoouub=0;
     
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}


void create_image(void)
{
    int row;
    unsigned int col;
    int *colors;

    screenmap.img = malloc(screenmap.image_size);
    row = screenmap.height - 1;
    while(row > 0)
    {
        col = 0;
        while(col < screenmap.width)
        {
            colors = get_color(g_data[(screenmap.height - row) * screenmap.width + col]);
            screenmap.img[row * screenmap.width_in_byte + col * 3 + 2] = colors[0];
            screenmap.img[row * screenmap.width_in_byte + col * 3 + 1] = colors[1];
            screenmap.img[row * screenmap.width_in_byte + col * 3 + 0] = colors[2];
            col++;
        }
        row--;
    }
}
void screenshot(void)
{
    screenmap.fd = open("./screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    ft_header();
    create_image();
    write(screenmap.fd,screenmap.header,54);
    write(screenmap.fd,screenmap.img,screenmap.image_size);
    free(screenmap.header);
    free(screenmap.img);
    exit(0);
}
void direction_global()
{
    direction.ea = 0;
    direction.no = 0;
    direction.su = 0;
    direction.we = 0;
    direction.s = 0;
    direction.f = 0;
    direction.c = 0;
}

void ft_check_arg(char **argv,int argc)
{
    int i;
    int len;


    len = ft_strlen(argv[1]);
    len = len - 4;
    mapo = &argv[1][len];
    if (argc == 2)
        g_chorfi = strdup("");
    else
        g_chorfi = argv[2];
    
    if(strcmp(mapo,".cub") != 0)
    {
        ft_putstr("error in .cub");
        exit(0);
    }

}
void ft_calcul_lenght()
{
    char *str;
    g_indexo = 0;
    while(get_next_line(g_fd,&str))
    {
        free(str);
        g_indexo++;
    }
    free(str);
}

int main(int argc, char **argv)
{
    int i;
    g_split = 0;
    dontenteragain = 0;
    if(argc == 2 || argc == 3 )
        ft_check_arg(argv,argc);

    //ft_calcul_lenght();

   i = 0;
    g_remain_argc = argc;
    inde = 0;

    x = wall;
    y = wall;
       direction_global();

   // memset(g_rays, 0, 1000 * sizeof(int));
    //memset(g_rays_hit, 0, 1000 * sizeof(int));
    mlx_ptr = mlx_init();
    g_fd = open(argv[1], O_RDONLY , O_RDWR);
    if (g_fd == -1)
    {
        ft_putstr("error in file descriptor");
        exit(0);
    }
    
    ft_calcul_lenght();
    line = malloc(sizeof(char *) * (g_indexo));
    close(g_fd);
   
    int fd = open(argv[1], O_RDONLY, O_RDWR);
    if (fd == -1)
    {
        ft_putstr("error mapo");
        exit(0);
    }
    
    //fd_tab(fd);
    if (!fd_tab(fd))
            return 0;
    
    ft_check_zero();
     
    if(strcmp(g_chorfi,"--save") != 0 && argc == 3)
    {
        ft_putstr("error in parameter");
        exit (0);
    }

    if(strcmp(g_chorfi,"--save") != 0)
        win_ptr = mlx_new_window(mlx_ptr, width, height,"mlx 42");
    g_image = mlx_new_image(mlx_ptr,width,height);
    g_data = (int *)mlx_get_data_addr(g_image,&g_b,&g_a,&g_c);
    ft_morba3();
     if (N > 1 || N == 0)
    {
        ft_putstr("error multi or miss player\n");
        exit (0);
    }
    //return 0;
    rotation = rotationAngle - M_PI / 8;
    rot = rad(45) / width;
    sprite_count = 0;
    while(i < width)
    {
        if (rotation > 2 * M_PI || rotation < 0)
            rotation = ft_normalize_angle(rotation);
        //DDA(X_player, Y_player,  wallHitX, wallHitY);
        ft_cast_ray(i);

        rotation += rot;
        // if(sprite == 0)
        render_map3D(i);
        sorting();
        if(sprite_indicator == 1 )
        {
            //  while(sp_c < sprite_count)
            //  {
                if (sprites[0].distance < distance)
                {
                    render_sprite(i);
                }
                
            //     sp_c++;
            //  }
           
            
             sprite_count = 0;
        }
        i++;

    }
    mlx_loop_hook(mlx_ptr,loop_key,0);
   //ft_free_l3alam2();
    //free(g_data);
    mlx_loop(mlx_ptr);


}