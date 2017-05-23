/*
 * main.h
 *
 *  Created on: 02.02.2017
 *      Author: Wlasciciel
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <calibrateInterface.h>
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include <stdio.h>
#include <string.h>
#include "math.h"
#include "characters.h"
extern life;
extern life1;
extern life2;
extern life3;
extern life4;
extern life5;
extern yConv;
extern score;
int16_t changeX =75;
int positionY=300;
float circleX =100;
float circleY =290;
float moveX = 5;
float moveY = 10;
int kierunek=1;
int kierunekLR = 3;
char str[] = "";
#endif /* MAIN_H_ */
