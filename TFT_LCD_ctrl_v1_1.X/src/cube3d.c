#include "cube3d.h"
#include "cordic.h"
#include "ili9341.h"
#include <math.h>

double degree = -180.0;
double scale = 1.0;
double scale_inc = 0.05;
double scale_min = 0.2;
double scale_max = 2.0;

static const int16_t pix[AMOUNT_NODE][3] ={{-25,-25,-25},{25,-25,-25},{25,25,-25},{-25,25,-25},
											{-25,-25,25}, {25,-25,25}, {25,25,25}, {-25,25,25}};
static int16_t newpix[AMOUNT_NODE][3];

static void calcPerspectiveProjection(const int16_t * coordinate, int16_t * x, int16_t * y)
{
	*x = coordinate[0] + coordinate[2] / 2;
	*y = coordinate[1] - coordinate[2] / 2;
}

static void drawLine( int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t color)
{
	ILI9341_DrawLine(x0 + ili9341Info.width/2, y0 + ili9341Info.height/2, x1 + ili9341Info.width/2, y1 + ili9341Info.height/2, color);
}

inline double round(double x){
    return (floor(x+0.5));
}

void cube_calculate(double degreeX, double degreeY, double degreeZ, double scale, int16_t shiftX, int16_t shiftY, int16_t shiftZ)
{
	uint8_t i;
	double sinx, siny, sinz, cosx, cosy, cosz;
	double x,y,z,x1,y1,z1;

	cordic(degreeX, &sinx, &cosx);
	cordic(degreeY, &siny, &cosy);
	cordic(degreeZ, &sinz, &cosz);

	for (i = 0; i < AMOUNT_NODE; i++)
	{
	    x = pix[i][0];              // Base coordinate
	    y = pix[i][1];
	    z = pix[i][2];

	    x1 = x*cosz + y*sinz;       // Rotation around axis Z
	    y1 = -x*sinz + y*cosz;
	    z1 = z;

	    x = x1;                     // Rotation around axis X
	    y = y1*cosx + z1*sinx;
	    z = -y1*sinx + z1*cosx;

	    x1 = x*cosy - z*siny;       // Rotation around axis Y
	    y1 = y;
	    z1 = x*siny + z*cosy;

    	newpix[i][0] = (int16_t)round(x1 * scale);    // Scaling
    	newpix[i][1] = (int16_t)round(y1 * scale);
    	newpix[i][2] = (int16_t)round(z1 * scale);

    	newpix[i][0] += shiftX;     // Shift center coordinates
    	newpix[i][1] += shiftY;
    	newpix[i][2] += shiftZ;
	}
}

void cube_draw(uint16_t color)
{
	uint8_t i, j;
	int16_t x0, y0, x1, y1;
    
#ifdef USE_COLOR_FRAME
    bool isDraw = (color > 0);
#endif
    
	for (j = 0; j < AMOUNT_NODE; j++)
	{
		i = j;
		calcPerspectiveProjection(newpix[i], &x0, &y0);
		if (i < AMOUNT_NODE/2)   // Draw sealing ribs
		{
			calcPerspectiveProjection(newpix[i+4], &x1, &y1);
			drawLine(x0, y0, x1, y1, color);
		}
		i ++;
		i = (i == AMOUNT_NODE/2) ? 0 : i;   // Draws front face
		i = (i == AMOUNT_NODE) ? 4 : i;	// Draws back face

		calcPerspectiveProjection(newpix[i], &x1, &y1);

#ifdef USE_COLOR_FRAME        
        if (isDraw)
        {    
            switch (j)
            {
                case 0: color = ILI9341_OLIVE; break;
                case 1: color = ILI9341_GREEN; break;
                case 2: color = ILI9341_PURPLE; break;
                case 3: color = ILI9341_YELLOW; break;
                case 4: color = ILI9341_RED; break;
                case 5: color = ILI9341_WHITE; break;
                case 6: color = ILI9341_ORANGE; break;
                case 7: color = ILI9341_PINK; break;
            }        
        }
#endif
        
		drawLine(x0, y0, x1, y1, color);
	}
}

void cubeDisplay(void)
{
	cube_draw(0x0000);      // Clear
	if (degree >= 180.0) degree = -180.0;
	if ((scale < scale_min) && (scale_inc < 0)) scale_inc = -scale_inc;
	if ((scale > scale_max) && (scale_inc > 0)) scale_inc = -scale_inc;
	cube_calculate(degree, degree, degree, scale, 0, 0, 0);
	degree += 0.5;
	scale += scale_inc;
	cube_draw(0xFFFF);      // Draw
}
