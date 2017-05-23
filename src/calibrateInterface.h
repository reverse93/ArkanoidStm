/*
 * calibrateSpi.h
 *
 *  Created on: 02.02.2017
 *      Author: Wlasciciel
 */

#ifndef CALIBRATEINTERFACE_H_
#define CALIBRATEINTERFACE_H_
	int i=0;
#ifdef __cplusplus
 extern "C" {
#endif

  void calibrateSpi(void);
  int checkDcOffset(void);
  int measureY(void);
  void init_lcd(void);

  typedef struct {
	  int Up;
	  int Down;
	  int Left;
	  int Right;
  } Direction;
#endif /* CALIBRATESPI_H_ */
