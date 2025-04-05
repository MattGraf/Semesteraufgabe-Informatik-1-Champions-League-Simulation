#include "farben.h"

void setColour_BG(int colour)  /*Setzen der Hintergrund-Farbe*/
{
        switch(colour) {
                case 1:
                        printf(BLUE_BG);         /*ANSI-Escape-Code fuer blauen Hintergrund*/
                        break;
                default:
                        printf(WHITE_BG);        /*ANSI-Escape-Code fuer weissen Hintergrund*/
                        break;
        }
}

void setColour_FG(int colour) /*Setzen der Vordergrund-Farbe*/
{
        switch(colour) {
                case 1:
                        printf(WHITE_FG);         /*ANSI-Escape-Code fuer blauen Vordergrund*/
                        break;
                case 2:
                        printf(GREEN_FG);
                        break;
                case 3:
                        printf(RED_FG);
                        break;
                default:
                        printf(BLACK_FG);        /*ANSI-Escape-Code fuer schwarzen Vordergrund*/
        }
}
