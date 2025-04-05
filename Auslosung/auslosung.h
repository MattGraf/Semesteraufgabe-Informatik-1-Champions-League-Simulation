#ifndef AUSLOSUNG_H_INCLUDED
#define AUSLOSUNG_H_INCLUDED

#include <stdlib.h>

#include "auslosung_random.h"
#include "auslosung_punkte.h"

void generate_auslosung_random(); /*Zufaellige Auslosung durchfuehren*/
void print_auslosung_random(); /*Zufaellige Auslosung ausgeben*/

void generate_auslosung_punkte();       /*Auslosung mit Ergebnissen durchfuehren*/
void print_auslosung_punkte();  /*Auslosung mit Ergebnissen ausgeben*/

#endif
