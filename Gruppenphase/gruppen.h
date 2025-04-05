#ifndef GRUPPEN_H_INCLUDED
#define GRUPPEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gruppen_intern.h"

int read_groups(); /*Einlesen der Gruppenphase*/
int order_groups(); /*Neuordnung der Gruppen*/
void print_groups(); /*Ausgabe der Gruppen*/

extern struct mannschaften gruppe[8][4]; /*Zweidimensionaler Array zur Speicherung der Gruppen*/

#endif
