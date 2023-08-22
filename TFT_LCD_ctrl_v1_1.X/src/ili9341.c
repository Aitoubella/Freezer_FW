#include <math.h>
#include "ili9341.h"
#ifdef ILI9341_SPI_PLIB
    #include "../framework/peripheral/spi/plib_spi.h"
#endif

ILI9341_INFO ili9341Info;
DRV_SPI_BUFFER_HANDLE bufHandle;

void ili9341_writeCommand(uint8_t cmd);
void ili9341_writeData(uint8_t dat);
void ili9341_writeData16(uint16_t dat);
void ili9341_mode16(void);
void ili9341_mode8(void);

void ILI9341_Init(void)
{
    ili9341Info.width = ILI9341_DEF_WIDTH;
    ili9341Info.height = ILI9341_DEF_HEIGHT;
    ili9341Info.cursorX = 0;
    ili9341Info.cursorY = 0;
    ili9341Info.rotation = 0;
    ili9341Info.textSize = 1;
    ili9341Info.textColor = ILI9341_WHITE;
    ili9341Info.textBgColor = ILI9341_BLACK;

    LCD_RST_TRIS = 0;
    LCD_DC_TRIS = 0;
    LCD_CS_TRIS = 0;

    LCD_DC_LAT = 0;
    LCD_CS_LAT = 1;

    // Reset
    LCD_RST_LAT = 0;
    __delay_ms(1);    
    LCD_RST_LAT = 1;
    __delay_ms(10);

    ili9341_writeCommand(0xEF);
    ili9341_writeData(0x03);
    ili9341_writeData(0x80);
    ili9341_writeData(0x02);

    ili9341_writeCommand(0xCF);
    ili9341_writeData(0x00);
    ili9341_writeData(0xC1);
    ili9341_writeData(0x30);

    ili9341_writeCommand(0xED);
    ili9341_writeData(0x64);
    ili9341_writeData(0x03);
    ili9341_writeData(0x12);
    ili9341_writeData(0x81);

    ili9341_writeCommand(0xE8);
    ili9341_writeData(0x85);
    ili9341_writeData(0x00);
    ili9341_writeData(0x78);

    ili9341_writeCommand(0xCB);
    ili9341_writeData(0x39);
    ili9341_writeData(0x2C);
    ili9341_writeData(0x00);
    ili9341_writeData(0x34);
    ili9341_writeData(0x02);

    ili9341_writeCommand(0xF7);
    ili9341_writeData(0x20);

    ili9341_writeCommand(0xEA);
    ili9341_writeData(0x00);
    ili9341_writeData(0x00);

    ili9341_writeCommand(ILI9341_PWCTR1);    //Power control
    ili9341_writeData(0x23);                 //VRH[5:0]

    ili9341_writeCommand(ILI9341_PWCTR2);    //Power control
    ili9341_writeData(0x10);                 //SAP[2:0];BT[3:0]

    ili9341_writeCommand(ILI9341_VMCTR1);    //VCM control
    ili9341_writeData(0x3e);
    ili9341_writeData(0x28);

    ili9341_writeCommand(ILI9341_VMCTR2);    //VCM control2
    ili9341_writeData(0x86);

    ili9341_writeCommand(ILI9341_MADCTL);    // Memory Access Control
    ili9341_writeData(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);

    ili9341_writeCommand(ILI9341_PIXFMT);
    ili9341_writeData(0x55);

    ili9341_writeCommand(ILI9341_FRMCTR1);
    ili9341_writeData(0x00);
    ili9341_writeData(0x18);

    ili9341_writeCommand(ILI9341_DFUNCTR);    // Display Function Control
    ili9341_writeData(0x08);
    ili9341_writeData(0x82);
    ili9341_writeData(0x27);

    ili9341_writeCommand(0xF2);              // 3Gamma Function Disable
    ili9341_writeData(0x00);

    ili9341_writeCommand(ILI9341_GAMMASET);   //Gamma curve selected
    ili9341_writeData(0x01);

    ili9341_writeCommand(ILI9341_GMCTRP1);    //Set Gamma
    ili9341_writeData(0x0F);
    ili9341_writeData(0x31);
    ili9341_writeData(0x2B);
    ili9341_writeData(0x0C);
    ili9341_writeData(0x0E);
    ili9341_writeData(0x08);
    ili9341_writeData(0x4E);
    ili9341_writeData(0xF1);
    ili9341_writeData(0x37);
    ili9341_writeData(0x07);
    ili9341_writeData(0x10);
    ili9341_writeData(0x03);
    ili9341_writeData(0x0E);
    ili9341_writeData(0x09);
    ili9341_writeData(0x00);

    ili9341_writeCommand(ILI9341_GMCTRN1);    //Set Gamma
    ili9341_writeData(0x00);
    ili9341_writeData(0x0E);
    ili9341_writeData(0x14);
    ili9341_writeData(0x03);
    ili9341_writeData(0x11);
    ili9341_writeData(0x07);
    ili9341_writeData(0x31);
    ili9341_writeData(0xC1);
    ili9341_writeData(0x48);
    ili9341_writeData(0x08);
    ili9341_writeData(0x0F);
    ili9341_writeData(0x0C);
    ili9341_writeData(0x31);
    ili9341_writeData(0x36);
    ili9341_writeData(0x0F);

    ili9341_writeCommand(ILI9341_SLPOUT);    //Exit Sleep
    __delay_ms(120);
    ILI9341_FillScreen(ILI9341_BLACK);
    ili9341_writeCommand(ILI9341_DISPON);    //Display on
    
    // Default 16bit Mode
    ili9341_mode16();
}

// configure SPI1 for 16-bit mode
inline void ili9341_mode16(void)
{
#ifdef ILI9341_SPI_PLIB
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_4, SPI_COMMUNICATION_WIDTH_16BITS);
#else
    SPI4CONSET = 0x400;
#endif    
}

// configure SPI1 for 8-bit mode
inline void ili9341_mode8(void)
{
#ifdef ILI9341_SPI_PLIB
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_4, SPI_COMMUNICATION_WIDTH_8BITS);
#else    
    SPI4CONCLR = 0x400;
#endif
}

void ili9341_spiWrite8(uint8_t c)
{
#ifdef ILI9341_SPI_PLIB
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_4, SPI_COMMUNICATION_WIDTH_8BITS);
    PLIB_SPI_BufferWrite(SPI_ID_4, c);
    while (PLIB_SPI_IsBusy(SPI_ID_4));
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_4, SPI_COMMUNICATION_WIDTH_16BITS);
#else
    // 8bit Mode: ili9341_mode8()
    SPI4CONCLR = 0x400;

    // Send data to SPI4BUF.
    SPI4BUF = c;
    while (SPI4STATbits.SPIBUSY);

    //16bit Mode: ili9341_mode16()
    SPI4CONSET = 0x400;
#endif
}

#ifdef ILI9341_SPI_SPEED_UP
    #ifdef ILI9341_SPI_PLIB
        #define ili9341_spiWrite16(c) {PLIB_SPI_BufferWrite16bit(SPI_ID_4, c); while (PLIB_SPI_IsBusy(SPI_ID_4));}
    #else
        #define ili9341_spiWrite16(c) {SPI4BUF = c; while (SPI4STATbits.SPIBUSY);}
    #endif
#else
    void ili9341_spiWrite16(uint16_t c)
    {
        #ifdef ILI9341_SPI_PLIB
            PLIB_SPI_BufferWrite16bit(SPI_ID_4, c);
            while (PLIB_SPI_IsBusy(SPI_ID_4));
        #else
            SPI4BUF = c;
            while (SPI4STATbits.SPIBUSY);
        #endif
    }
#endif    

//color565toRGB14		- converts 16 bit 565 format color to 14 bit RGB (2 bits clear for math and sign)
//returns 00rrrrr000000000,00gggggg00000000,00bbbbb000000000
//thus not overloading sign, and allowing up to double for additions for fixed point delta
void ili9341_color565toRGB14(uint16_t color, int16_t *r, int16_t *g, int16_t *b)
{
	*r = (color >> 2) & 0x3E00;
	*g = (color << 3) & 0x3F00;
	*b = (color << 9) & 0x3E00;
}

//RGB14tocolor565		- converts 14 bit RGB back to 16 bit 565 format color
uint16_t ili9341_RGB14tocolor565(int16_t r, int16_t g, int16_t b)
{
	return (((r & 0x3E00) << 2) | ((g & 0x3F00) >>3) | ((b & 0x3E00) >> 9));
}

void ili9341_setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    ili9341_writeCommand(ILI9341_CASET);    // Column addr set
    ili9341_writeData16(x0);
    ili9341_writeData16(x1);

    ili9341_writeCommand(ILI9341_PASET);    // Row addr set
    ili9341_writeData16(y0);
    ili9341_writeData16(y1);

    ili9341_writeCommand(ILI9341_RAMWR);    // write to RAM
}

void ili9341_pushColor(uint16_t color)
{
    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    ili9341_spiWrite16(color);

    LCD_CS_LAT = 1;
}

void ILI9341_DrawPixel(int16_t x, int16_t y, uint16_t color)
{
/* Draw a pixel at location (x,y) with given color
 * Parameters:
 *      x:  x-coordinate of pixel to draw; top left of screen is x=0
 *              and x increases to the right
 *      y:  y-coordinate of pixel to draw; top left of screen is y=0
 *              and y increases to the bottom
 *      color:  16-bit color value
 * Returns:     Nothing
 */

    if((x < 0) ||(x >= ili9341Info.width) || (y < 0) || (y >= ili9341Info.height)) return;

    ili9341_setAddrWindow(x, y, x + 1, y + 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;
    
    ili9341_spiWrite16(color);
    
    LCD_CS_LAT = 1;
}

void ili9341_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
/* Draw a vertical line at location from (x,y) to (x,y+h-1) with color
 * Parameters:
 *      x:  x-coordinate line to draw; top left of screen is x=0
 *              and x increases to the right
 *      y:  y-coordinate of starting point of line; top left of screen is y=0
 *              and y increases to the bottom
 *      h:  height of line to draw
 *      color:  16-bit color value
 * Returns:     Nothing
 */

	if ((x >= ili9341Info.width) || (x < 0) || (y >= ili9341Info.height)) return;
	if(y < 0)
    {
        h += y;
        y = 0;
 	}
	if (( y + h - 1) >= ili9341Info.height) h = ili9341Info.height - y;
    
    ili9341_setAddrWindow(x, y, x, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    while (h--)
    {
        ili9341_spiWrite16(color);
    }

    LCD_CS_LAT = 1;
}

void ili9341_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
/* Draw a horizontal line at location from (x,y) to (x+w-1,y) with color
 * Parameters:
 *      x:  x-coordinate starting point of line; top left of screen is x=0
 *              and x increases to the right
 *      y:  y-coordinate of starting point of line; top left of screen is y=0
 *              and y increases to the bottom
 *      w:  width of line to draw
 *      color:  16-bit color value
 * Returns:     Nothing
 */

	if ((x >= ili9341Info.width) || (y >= ili9341Info.height) || (y < 0)) return;
	if (x < 0)
    {
        w += x;
        x = 0;
 	}
	if ((x + w - 1) >= ili9341Info.width)  w = ili9341Info.width - x;

    ili9341_setAddrWindow(x, y, x + w - 1, y);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    while (w--)
    {
        ili9341_spiWrite16(color);
    }

    LCD_CS_LAT = 1;
}

void ILI9341_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
/* Draw a filled rectangle with starting top-left vertex (x,y),
 *  width w and height h with given color
 * Parameters:
 *      x:  x-coordinate of top-left vertex; top left of screen is x=0
 *              and x increases to the right
 *      y:  y-coordinate of top-left vertex; top left of screen is y=0
 *              and y increases to the bottom
 *      w:  width of rectangle
 *      h:  height of rectangle
 *      color:  16-bit color value
 * Returns:     Nothing
 */

	if ((x >= ili9341Info.width) || (y >= ili9341Info.height)) return;
	if (x < 0)
    {
        w += x;
        x = 0;
 	}
	if (y < 0)
    {
        h += y;
        y = 0;
 	}
	if ((x + w - 1) >= ili9341Info.width)  w = ili9341Info.width  - x;
	if ((y + h - 1) >= ili9341Info.height) h = ili9341Info.height - y;
    
    ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    for (y = h; y > 0; y--)
    {
        for (x = w; x > 0; x--)
        {
            ili9341_spiWrite16(color);
        }
    }

    LCD_CS_LAT = 1;
}

void ILI9341_FillScreen(uint16_t color)
{
/* Fill entire screen with given color
 * Parameters:
 *      color: 16-bit color value
 * Returs:  Nothing
 */
    ILI9341_FillRect(0, 0, ili9341Info.width, ili9341Info.height, color);
}

void ILI9341_FillRectVGradient(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color1, uint16_t color2)
{
	// rudimentary clipping (drawChar w/big text requires this)
	if ((x >= ili9341Info.width) || (y >= ili9341Info.height)) return;
	if ((x + w - 1) >= ili9341Info.width)  w = ili9341Info.width  - x;
	if ((y + h - 1) >= ili9341Info.height) h = ili9341Info.height - y;
	
	int16_t r1, g1, b1, r2, g2, b2, dr, dg, db, r, g, b;
	ili9341_color565toRGB14(color1, &r1, &g1, &b1);
	ili9341_color565toRGB14(color2, &r2, &g2, &b2);
	dr = (r2 - r1) / h;
    dg = (g2 - g1) / h;
    db = (b2 - b1) / h;
	r = r1;
    g = g1;
    b = b1;	

	// TODO: this can result in a very long transaction time
	// should break this into multiple transactions, even though
	// it'll cost more overhead, so we don't stall other SPI libs
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		uint16_t color = ili9341_RGB14tocolor565(r, g, b);

		for (x = w; x > 1; x--)
        {
			ili9341_spiWrite16(color);
		}

		r += dr;
        g += dg;
        b += db;
	}

    LCD_CS_LAT = 1;
}

void ILI9341_FillRectHGradient(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color1, uint16_t color2)
{
	// rudimentary clipping (drawChar w/big text requires this)
	if ((x >= ili9341Info.width) || (y >= ili9341Info.height)) return;
	if ((x + w - 1) >= ili9341Info.width)  w = ili9341Info.width  - x;
	if ((y + h - 1) >= ili9341Info.height) h = ili9341Info.height - y;
	
	int16_t r1, g1, b1, r2, g2, b2, dr, dg, db, r, g, b;
	
    ili9341_color565toRGB14(color1, &r1, &g1, &b1);
	ili9341_color565toRGB14(color2, &r2, &g2, &b2);
	
    dr = (r2 - r1) / h;
    dg = (g2 - g1) / h;
    db = (b2 - b1) / h;
	r = r1;
    g = g1;
    b = b1;	

	// TODO: this can result in a very long transaction time
	// should break this into multiple transactions, even though
	// it'll cost more overhead, so we don't stall other SPI libs
	ili9341_setAddrWindow(x, y, x+w-1, y+h-1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		uint16_t color;
		
        for (x = w; x > 1; x--)
        {
			color = ili9341_RGB14tocolor565(r, g, b);
			ili9341_spiWrite16(color);
			r += dr;
            g += dg;
            b += db;
		}
		
        color = ili9341_RGB14tocolor565(r, g, b);
		r = r1;
        g = g1;
        b = b1;
	}

    LCD_CS_LAT = 1;
}

void ILI9341_FillScreenVGradient(uint16_t color1, uint16_t color2)
{
	ILI9341_FillRectVGradient(0, 0, ili9341Info.width, ili9341Info.height, color1, color2);
}

void ILI9341_FillScreenHGradient(uint16_t color1, uint16_t color2)
{
	ILI9341_FillRectHGradient(0, 0, ili9341Info.width, ili9341Info.height, color1, color2);
}

void ILI9341_SetRotation(uint8_t m)
{
	ili9341Info.rotation = m % 4; // can't be higher than 3

	ili9341_writeCommand(ILI9341_MADCTL);
	
    switch (ili9341Info.rotation)
    {
        case 0:
            ili9341_writeData(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
            ili9341Info.width  = ILI9341_DEF_WIDTH;
            ili9341Info.height = ILI9341_DEF_HEIGHT;
            break;
        case 1:
            ili9341_writeData(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
            ili9341Info.width  = ILI9341_DEF_HEIGHT;
            ili9341Info.height = ILI9341_DEF_WIDTH;
            break;
        case 2:
            ili9341_writeData(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
            ili9341Info.width  = ILI9341_DEF_WIDTH;
            ili9341Info.height = ILI9341_DEF_HEIGHT;
            break;
        case 3:
            ili9341_writeData(ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
            ili9341Info.width  = ILI9341_DEF_HEIGHT;
            ili9341Info.height = ILI9341_DEF_WIDTH;
            break;
	}

	ili9341Info.cursorX = 0;
	ili9341Info.cursorY = 0;
}

void ILI9341_SetScroll(uint16_t offset)
{
	ili9341_writeCommand(ILI9341_VSCRSADD);
	ili9341_writeData16(offset);
}

void ILI9341_InvertDisplay(bool b)
{
	ili9341_writeCommand(b ? ILI9341_INVON : ILI9341_INVOFF);
}

// Now lets see if we can writemultiple pixels
void ILI9341_WriteRect(int16_t x, int16_t y, int16_t w, int16_t h, const uint16_t *pcolors)
{
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		for(x = w; x > 1; x--)
        {
			ili9341_spiWrite16(*pcolors++);
		}
	}

    LCD_CS_LAT = 1;
}

// writeRect8BPP - 	write 8 bit per pixel paletted bitmap
//					bitmap data in array at pixels, one byte per pixel
//					color palette data in array at palette
void ili9341_writeRect8BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette )
{
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		for (x = w; x > 1; x--)
        {
			ili9341_spiWrite16(palette[*pixels++]);
		}
	}

    LCD_CS_LAT = 1;
}

// writeRect4BPP - 	write 4 bit per pixel paletted bitmap
//					bitmap data in array at pixels, 4 bits per pixel
//					color palette data in array at palette
//					width must be at least 2 pixels
void ili9341_writeRect4BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette )
{
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		for (x = w; x > 2; x -= 2)
        {
			ili9341_spiWrite16(palette[((*pixels)>>4)&0xF]);
			ili9341_spiWrite16(palette[(*pixels++)&0xF]);
		}
	}

    LCD_CS_LAT = 1;
}

// writeRect2BPP - 	write 2 bit per pixel paletted bitmap
//					bitmap data in array at pixels, 4 bits per pixel
//					color palette data in array at palette
//					width must be at least 4 pixels
void ili9341_writeRect2BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette )
{
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		for (x = w; x > 4; x -= 4)
        {
			//unrolled loop might be faster?
			ili9341_spiWrite16(palette[((*pixels)>>6)&0x3]);
			ili9341_spiWrite16(palette[((*pixels)>>4)&0x3]);
			ili9341_spiWrite16(palette[((*pixels)>>2)&0x3]);
			ili9341_spiWrite16(palette[(*pixels++)&0x3]);
		}
	}

    LCD_CS_LAT = 1;
}

// writeRect1BPP - 	write 1 bit per pixel paletted bitmap
//					bitmap data in array at pixels, 4 bits per pixel
//					color palette data in array at palette
//					width must be at least 8 pixels
void ili9341_writeRect1BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette )
{
	ili9341_setAddrWindow(x, y, x + w - 1, y + h - 1);

    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	for (y = h; y > 0; y--)
    {
		for (x = w; x > 8; x -= 8)
        {
			//unrolled loop might be faster?
			ili9341_spiWrite16(palette[((*pixels)>>7)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>6)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>5)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>4)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>3)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>2)&0x1]);
			ili9341_spiWrite16(palette[((*pixels)>>1)&0x1]);
			ili9341_spiWrite16(palette[(*pixels++)&0x1]);
		}
	}
    
    LCD_CS_LAT = 1;
}

void ILI9341_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    ILI9341_DrawPixel(x0  , y0 + r, color);
    ILI9341_DrawPixel(x0  , y0 - r, color);
    ILI9341_DrawPixel(x0 + r, y0  , color);
    ILI9341_DrawPixel(x0 - r, y0  , color);

    while (x < y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        ILI9341_DrawPixel(x0 + x, y0 + y, color);
        ILI9341_DrawPixel(x0 - x, y0 + y, color);
        ILI9341_DrawPixel(x0 + x, y0 - y, color);
        ILI9341_DrawPixel(x0 - x, y0 - y, color);
        ILI9341_DrawPixel(x0 + y, y0 + x, color);
        ILI9341_DrawPixel(x0 - y, y0 + x, color);
        ILI9341_DrawPixel(x0 + y, y0 - x, color);
        ILI9341_DrawPixel(x0 - y, y0 - x, color);
    }
}

void ili9341_drawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    while (x < y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
    
        if (cornername & 0x4)
        {
            ILI9341_DrawPixel(x0 + x, y0 + y, color);
            ILI9341_DrawPixel(x0 + y, y0 + x, color);
        }
        if (cornername & 0x2)
        {
            ILI9341_DrawPixel(x0 + x, y0 - y, color);
            ILI9341_DrawPixel(x0 + y, y0 - x, color);
        }
        if (cornername & 0x8)
        {
            ILI9341_DrawPixel(x0 - y, y0 + x, color);
            ILI9341_DrawPixel(x0 - x, y0 + y, color);
        }
        if (cornername & 0x1)
        {
            ILI9341_DrawPixel(x0 - y, y0 - x, color);
            ILI9341_DrawPixel(x0 - x, y0 - y, color);
        }
    }
}

void ili9341_fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    while (x < y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        if (cornername & 0x1)
        {
            ili9341_drawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
            ili9341_drawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
        }
        if (cornername & 0x2)
        {
            ili9341_drawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
            ili9341_drawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
        }
    }
}

void ILI9341_FillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    ili9341_drawFastVLine(x0, y0 - r, 2 * r + 1, color);
    ili9341_fillCircleHelper(x0, y0, r, 3, 0, color);
}

void ili9341_HLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
  	if ((x >= ili9341Info.width) || (y >= ili9341Info.height) || (y < 0)) return;
	if (x < 0)
    {
        w += x;
        x = 0;
 	}
	if ((x + w - 1) >= ili9341Info.width)  w = ili9341Info.width - x;

	ili9341_setAddrWindow(x, y, x + w - 1, y);
    
    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	do
    {
        ili9341_spiWrite16(color);
    } while (--w > 0);

    LCD_CS_LAT = 1;
}

void ili9341_VLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	if ((x >= ili9341Info.width) || (x < 0) || (y >= ili9341Info.height)) return;
	if (y < 0)
    {
        h += y;
        y = 0;
 	}
	if ((y + h - 1) >= ili9341Info.height) h = ili9341Info.height - y;
	ili9341_setAddrWindow(x, y, x, y + h - 1);
    
    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

	do
    {
        ili9341_spiWrite16(color);
    } while (--h > 0);

    LCD_CS_LAT = 1;
}

void ili9341_Pixel(int16_t x, int16_t y, uint16_t color)
{
	if ((x >= ili9341Info.width) || (x < 0) || (y >= ili9341Info.height) || (y < 0)) return;
	ili9341_setAddrWindow(x, y, x, y);
	ili9341_writeData16(color);
}

// Bresenham's algorithm - thx wikpedia
void ILI9341_DrawLine(int16_t x0, int16_t y0,	int16_t x1, int16_t y1, uint16_t color)
{
	if (y0 == y1)
    {
		if (x1 > x0)
        {
			ili9341_drawFastHLine(x0, y0, x1 - x0 + 1, color);
		} else if (x1 < x0)
        {
			ili9341_drawFastHLine(x1, y0, x0 - x1 + 1, color);
		} else
        {
			ILI9341_DrawPixel(x0, y0, color);
		}
		return;
	} else if (x0 == x1)
    {
		if (y1 > y0)
        {
			ili9341_drawFastVLine(x0, y0, y1 - y0 + 1, color);
		} else
        {
			ili9341_drawFastVLine(x0, y1, y0 - y1 + 1, color);
		}
		return;
	}

	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep)
    {
		swap(x0, y0);
		swap(x1, y1);
	}
	if (x0 > x1)
    {
		swap(x0, x1);
		swap(y0, y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1)
    {
		ystep = 1;
	}
    else
    {
		ystep = -1;
	}

	int16_t xbegin = x0;

	if (steep)
    {
		for (; x0 <= x1; x0++)
        {
			err -= dy;
			if (err < 0)
            {
				int16_t len = x0 - xbegin;
				if (len)
                {
					ili9341_VLine(y0, xbegin, len + 1, color);
				}
                else
                {
					ili9341_Pixel(y0, x0, color);
				}
				xbegin = x0 + 1;
				y0 += ystep;
				err += dx;
			}
		}
		if (x0 > xbegin + 1)
        {
			ili9341_VLine(y0, xbegin, x0 - xbegin, color);
		}
	}
    else
    {
		for (; x0 <= x1; x0++)
        {
			err -= dy;
			if (err < 0)
            {
				int16_t len = x0 - xbegin;
				if (len)
                {
					ili9341_HLine(xbegin, y0, len + 1, color);
				} else
                {
					ili9341_Pixel(x0, y0, color);
				}
				xbegin = x0 + 1;
				y0 += ystep;
				err += dx;
			}
		}
		if (x0 > xbegin + 1)
        {
			ili9341_HLine(xbegin, y0, x0 - xbegin, color);
		}
	}
	ili9341_writeCommand(ILI9341_NOP);
}

void ILI9341_DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	ili9341_HLine(x, y, w, color);
	ili9341_HLine(x, y + h - 1, w, color);
	ili9341_VLine(x, y, h, color);
	ili9341_VLine(x + w - 1, y, h, color);
	ili9341_writeCommand(ILI9341_NOP);
}

void ILI9341_DrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
  // smarter version
  ili9341_drawFastHLine(x + r, y, w - 2 * r, color); // Top
  ili9341_drawFastHLine(x + r, y + h - 1, w - 2 * r, color); // Bottom
  ili9341_drawFastVLine(x, y + r, h - 2 * r, color); // Left
  ili9341_drawFastVLine(x + w - 1, y + r, h - 2 * r, color); // Right
  // draw four corners
  ili9341_drawCircleHelper(x + r, y + r, r, 1, color);
  ili9341_drawCircleHelper(x + w - r - 1, y + r, r, 2, color);
  ili9341_drawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
  ili9341_drawCircleHelper(x + r, y + h - r - 1, r, 8, color);
}

void ILI9341_FillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
  // smarter version
  ILI9341_FillRect(x + r, y, w - 2 * r, h, color);

  // draw four corners
  ili9341_fillCircleHelper(x + w - r - 1, y + r, r, 1, h - 2 * r - 1, color);
  ili9341_fillCircleHelper(x + r, y + r, r, 2, h - 2 * r - 1, color);
}

void ILI9341_DrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
  ILI9341_DrawLine(x0, y0, x1, y1, color);
  ILI9341_DrawLine(x1, y1, x2, y2, color);
  ILI9341_DrawLine(x2, y2, x0, y0, color);
}

void ILI9341_FillTriangle ( int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    int16_t a, b, y, last;

    // Sort coordinates by Y order (y2 >= y1 >= y0)
    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }
    if (y1 > y2)
    {
        swap(y2, y1);
        swap(x2, x1);
    }
    if (y0 > y1)
    {
        swap(y0, y1);
        swap(x0, x1);
    }

    // Handle awkward all-on-same-line case as its own thing
    if (y0 == y2)
    {
        a = b = x0;
        if (x1 < a) a = x1;
        else if (x1 > b) b = x1;
        if (x2 < a) a = x2;
        else if (x2 > b) b = x2;
        ili9341_drawFastHLine(a, y0, b-a+1, color);
        return;
    }

    int16_t dx01 = x1 - x0;
    int16_t dy01 = y1 - y0;
    int16_t dx02 = x2 - x0;
    int16_t dy02 = y2 - y0;
    int16_t dx12 = x2 - x1;
    int16_t dy12 = y2 - y1;
    int16_t sa   = 0;
    int16_t sb   = 0;

    // For upper part of triangle, find scanline crossings for segments
    // 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
    // is included here (and second loop will be skipped, avoiding a /0
    // error there), otherwise scanline y1 is skipped here and handled
    // in the second loop...which also avoids a /0 error here if y0=y1
    // (flat-topped triangle).
    if (y1 == y2) last = y1;   // Include y1 scanline
    else last = y1 - 1; // Skip it

    for (y = y0; y <= last; y++)
    {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;
        /* longhand:
        a = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
        b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        */
        if (a > b) swap(a,b);
        ili9341_drawFastHLine(a, y, b - a + 1, color);
    }

    // For lower part of triangle, find scanline crossings for segments
    // 0-2 and 1-2.  This loop is skipped if y1=y2.
    sa = dx12 * (y - y1);
    sb = dx02 * (y - y0);
    for (; y <= y2; y++)
    {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;
        /* longhand:
        a = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
        b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        */
        if (a > b) swap(a,b);
        ili9341_drawFastHLine(a, y, b-a+1, color);
    }
}

void ILI9341_DrawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
{
    int16_t i, j, byteWidth = (w + 7) / 8;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++ )
        {
            if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7)))
            {
                ILI9341_DrawPixel(x + i, y + j, color);
            }
        }
    }
}

//-----------------------------------------------------------------------------
void ili9341_writeCommand(uint8_t cmd)
{
    LCD_DC_LAT = 0;
    LCD_CS_LAT = 0;
    
    ili9341_spiWrite8(cmd);

    LCD_CS_LAT = 1;
}

void ili9341_writeData(uint8_t dat)
{
    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    ili9341_spiWrite8(dat);

    LCD_CS_LAT = 1;
}

void ili9341_writeData16(uint16_t dat)
{
    LCD_DC_LAT = 1;
    LCD_CS_LAT = 0;

    ili9341_spiWrite16(dat);
    
    LCD_CS_LAT = 1;
}
