#ifndef __OLED_H_
#define __OLED_H_

/*
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define uint  unsigned int
#define uchar unsigned char
*/

#include "include.h"

void OLED_Pin_Init(void);
void LCD_WrDat(uchar dat);
void LCD_WrCmd(uchar dat);
void LCD_Set_Pos(uchar x,uchar y);
void LCD_Fill(unsigned char bmp_dat);
void OLED_Fill(unsigned char bmp_dat);
void LCD_CLS(void);
void OLED_CLS(void);
void LCD_Init(void);
void LCD_P6x8Str(unsigned char x,unsigned char y,char *ch);
void OLED_P6X8Str(uchar x,uchar y,char *ch);
void OLED_Write();


#endif