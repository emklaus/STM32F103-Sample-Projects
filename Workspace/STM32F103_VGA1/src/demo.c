/***************************************************************************
 * STM32 VGA demo
 * Copyright (C) 2012 Artekit Italy
 * http://www.artekit.eu
 * Written by Ruben H. Meleca
 
### demo.c
 
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

***************************************************************************/

#include "stm32f10x.h"
#include "sys.h"
#include "video.h"
#include "gdi.h"
#include "string.h"
#include <stdlib.h>

extern volatile uint32_t		sysTicks;

const uint8_t	deBadBoys1[] = {0x00, 0x00,
								0x00, 0x00,
								0x07, 0xc0,
								0x1f, 0xf0,
								0x3f, 0xf8,
								0x33, 0x98,
								0x3f, 0xf8,
								0x0c, 0x60,
								0x1b, 0xb0,
								0x30, 0x18,
								0x00, 0x00,
								0x00, 0x00 };

const uint8_t	deBadBoys2[] = {0x00, 0x00,
								0x00, 0x00,
								0x07, 0xc0,
								0x1f, 0xf0,
								0x3f, 0xf8,
								0x33, 0x98,
								0x3f, 0xf8,
								0x0c, 0x60,
								0x1b, 0xb0,
								0x0c, 0x60,
								0x00, 0x00,
								0x00, 0x00 };

void loopDelay(uint32_t d)
{
 while(d--);
}

void demoInit(uint16_t demo_no) {

uint16_t x, y, x1, y1, i, flip;

switch(demo_no)
{
 case 1: //	Demo Point
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(172, 70, "POINT DEMO", GDI_ROP_COPY);
	loopDelay(20000000); // approx 2sec.
	srand(sysTicks);
	for (i = 0; i < 5000; i++) {
		//sysDelayMs(1);
		loopDelay(10000); // approx 1ms

		x = rand();	x = x % (VID_PIXELS_X - 1);
		y = rand();	y = y % VID_VSIZE - 1;
		gdiPoint(NULL,x,y,GDI_ROP_COPY);
	}
	//sysDelayMs(3000);
 break;
 case 2: //	Demo Line
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(175, 70, "LINE DEMO", GDI_ROP_COPY);
	loopDelay(20000000); // approx 2sec.
	srand(sysTicks);
	for (i = 0; i < 50; i++) {
		loopDelay(500000); // approx 50ms
		x = rand();	x = x % (VID_PIXELS_X - 1);
		y = rand();	y = y % VID_VSIZE - 1;
		x1 = rand();	x1 = x1 % (VID_PIXELS_X - 1);
		y1 = rand();	y1 = y1 % VID_VSIZE - 1;
		gdiLine(NULL,x,y,x1,y1,GDI_ROP_COPY);
	}
 break;
 case 3: //	Demo Square
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(157, 70, "RECTANGLE DEMO", GDI_ROP_COPY);
	loopDelay(20000000); // approx 2sec
	srand(sysTicks);
	for (i = 0; i < 50; i++) {
		loopDelay(500000); // approx 50ms
		x = rand();	x = x % (VID_PIXELS_X - 1);
		y = rand();	y = y % VID_VSIZE - 1;
		x1 = rand();	x1 = x1 % 100;
		y1 = rand();	y1 = y1 % 100;
		gdiRectangle(x,y,x1,y1,GDI_ROP_COPY);
	}
	//sysDelayMs(3000);
 break;
 case 4: //	Demo Circle
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(165, 70, "CIRCLE DEMO", GDI_ROP_COPY);
	loopDelay(20000000); // approx 2sec.

	srand(sysTicks);
	for (i = 0; i < 50; i++) {
		loopDelay(200000); // approx 20ms
		x = rand();	x = x % (VID_PIXELS_X - 1);
		y = rand();	y = y % VID_VSIZE - 1;
		x1 = rand(); x1 = x1 % 80;
		gdiCircle(x,y,x1,GDI_ROP_COPY);
	}
 break;
 case 5: //	Demo Bitmap
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(165, 70, "BITMAP DEMO", GDI_ROP_COPY);
	loopDelay(20000000); // approx 2sec.

	x = 100;
	y = 130;
	flip = 0;
	for (i = 0; i < 100; i++) {
		loopDelay(1000000); // approx 100ms
		if (flip) {
			flip = 0;
			gdiBitBlt(NULL,x,y,15,12,(uint8_t *) deBadBoys1,GDI_ROP_COPY);
		} else {
			flip = 1;
			gdiBitBlt(NULL,x,y,15,12,(uint8_t *) deBadBoys2,GDI_ROP_COPY);
		}
		x += 2;
	}
 break;
 default:
	vidClearScreen();
	gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	gdiDrawTextEx(180, 40, "ARTEKIT", GDI_ROP_COPY);
	gdiDrawTextEx(161, 55, "AK-STM32-LKIT", GDI_ROP_COPY);
	gdiDrawTextEx(115, 75, "ARM CORTEX DEVELOPMENT BOARDS", GDI_ROP_COPY);

	gdiDrawTextEx(156, 90, "WWW.ARTEKIT.EU", GDI_ROP_COPY);
	gdiDrawTextEx(141, 120, "FREE GRAPHIC ENGINE", GDI_ROP_COPY);
	gdiDrawTextEx(165, 130, "SOURCE CODE", GDI_ROP_COPY);
 break;
	//while (1) {};
 }
}
