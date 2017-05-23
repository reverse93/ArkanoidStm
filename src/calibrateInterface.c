/*
 * calibrateSpi.c
 *
 *  Created on: 02.02.2017
 *      Author: Wlasciciel
 */

#include "stm32f429i_discovery_l3gd20.h"
#include "stm32f429i_discovery_lcd.h"

  int8_t y_low =0x00;
  int8_t y_high=0x00;
  int8_t x_low =0x00;
  int8_t x_high=0x00;
  int8_t z_low=0x00;
  int8_t z_high=0x00;
  int16_t y=0x00;
  int16_t x=0x00;
  int16_t yConv=0;
  int sampleNum=500;
  int dc_offset=0;
  int control=0;

void calibrateSpi(){
    L3GD20_InitTypeDef gyroscope_init;
    gyroscope_init.Axes_Enable = 0b00000111;
    gyroscope_init.Power_Mode = 0b00001000;
    gyroscope_init.Band_Width = 0b00010000;
    gyroscope_init.BlockData_Update = 0;
    gyroscope_init.Endianness = 0;
    gyroscope_init.Full_Scale = 0;
    gyroscope_init.Output_DataRate = 0b11000000;

    L3GD20_Init(&gyroscope_init);
}

int checkDcOffset()
{
    for(int n=0;n<sampleNum;n++){
        y=(uint16_t)y;
        L3GD20_Read(&y_low, 0x2A, 1);
        L3GD20_Read(&y_high, 0x2B, 1);
        y = (uint16_t)y_high;
        y = y <<8;
        y|= (uint16_t)y_low;
     dc_offset+=y*250/32767;
    }
    dc_offset=dc_offset/sampleNum;
    return dc_offset;
}

int measureY(){
	if(control == 0 ){
		dc_offset = checkDcOffset();
		control = 1;
	}
	L3GD20_Read(&y_low, 0x2A, 1);
    L3GD20_Read(&y_high, 0x2B, 1);
    y = (uint16_t)y_high;
    y = y <<8;
    y|= (uint16_t)y_low;

    yConv=y;
    yConv=(yConv*250/32767)-dc_offset;
    return yConv;
}

void init_lcd(){

	  /* LCD initialization */
	  LCD_Init();
	  /* LCD Layer initialization */
	  LCD_LayerInit();
	  LCD_SetLayer(LCD_FOREGROUND_LAYER);
	  LCD_SetColorKeying(0xFFFFFF);
	  /* Need to reload */
	  LTDC_ReloadConfig(LTDC_IMReload);
	  /* Enable the LTDC */
	  LTDC_Cmd(ENABLE);
	  /* Set LCD foreground layer */
	  /* Clear the LCD */
	  LCD_Clear(LCD_COLOR_WHITE);
	  LCD_SetFont(&Font12x12);
	  LCD_SetLayer(LCD_BACKGROUND_LAYER);
	  LCD_SetColors(LCD_COLOR_BLACK,LCD_COLOR_WHITE);
	  LCD_Clear(LCD_COLOR_WHITE);
	  LCD_SetLayer(LCD_FOREGROUND_LAYER);
	  LCD_Clear(LCD_COLOR_WHITE);
}
