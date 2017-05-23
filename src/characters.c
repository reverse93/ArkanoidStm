
#include "stm32f429i_discovery_lcd.h"

extern life;
extern life1;
extern life2;
extern life3;
extern life4;
extern life5;
extern changeX;
extern positionY;
extern kierunek;
int score=0;
void enemy(int circleX, int circleY)
{
    if(life == 1 ) LCD_DrawFullRect(46, 70, 20,2);
    if(life1 == 1) LCD_DrawFullRect(86, 70, 20,2);
    if(life2 == 1) LCD_DrawFullRect(126, 70, 20,2);
    if(life3 == 1) LCD_DrawFullRect(176, 70, 20,2);
    if(life4 == 1) LCD_DrawFullRect(20, 90, 20,2);
    if(life5 == 1) LCD_DrawFullRect(50, 90, 20,2);

    if(circleX >=46 && circleX <= 66 && circleY>=70 && circleY<=72 && life == 1) life--;
    if(circleX >=86 && circleX <= 106 && circleY>=70 && circleY<=72 && life1 == 1) life1--;
    if(circleX >=126 && circleX <= 146 && circleY>=70 && circleY<=72 && life2 == 1) life2--;
    if(circleX >=176 && circleX <= 196 && circleY>=70 && circleY<=72 && life3 == 1) life3--;
    if(circleX >=20 && circleX <= 40 && circleY>=90 && circleY<=92 && life4 == 1) life4--;
    if(circleX >=50 && circleX <= 60 && circleY>=90 && circleY<=92 && life == 1)  life5--;

    if(life == 0 )
    	{
    		score+=1;
    		life=2;
    	}
    else if(life1 == 0)
		{
			score+=1;
			life1=2;
		}
    else if(life2 == 0)
		{
			score+=1;
			life2=2;
		}
    else if(life3 == 0)
    	{
    		score+=1;
    		life3=2;
    	}
    else if(life4 == 0)
    	{
			score+=1;
			life4=2;
    	}
    else if(life5 == 0)
    {
		score+=1;
		life5=2;
	}
}

int mainCharacter(int circleX, int circleY)
{
	positionY = 300;
	if(circleY > positionY || score == 6) return 0;
	else return 1;

}
