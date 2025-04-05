#ifndef FARBEN_H_INCLUDED
#define FARBEN_H_INCLUDED

#include <stdio.h>

#define WHITE_BG "\033[48;5;15m"     /*ANSI-Escape-Code fuer weissen Hintergrund*/
#define BLUE_BG "\033[48;5;12m"     /*ANSI-Escape-Code fuer blauen Hintergrund*/

#define BLACK_FG "\033[38;5;0m"     /*ANSI-Escape-Code fuer schwarzen Vordergrund*/
#define RED_FG "\033[38;5;9m"
#define GREEN_FG "\033[38;5;10m"
#define WHITE_FG "\033[38;5;15m"     /*ANSI-Escape-Code fuer weissen Vordergrund*/

void setColour_BG(int colour); /*Setzen der Hintergrund-Farbe*/
void setColour_FG(int colour); /*Setzen der Vordergrund-Farbe*/

#endif
