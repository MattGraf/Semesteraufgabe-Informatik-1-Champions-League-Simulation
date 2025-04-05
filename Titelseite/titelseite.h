#ifndef TITELSEITE_H_INCLUDED
#define TITELSEITE_H_INCLUDED

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Farben/farben.h"
#include "../Gruppenphase/gruppen.h"
#include "../Gruppenphase/gruppen_intern.h"
#include "../Auslosung/auslosung.h"
#include "../Wetten/wetten.h"

#define MIN_MODE 1
#define MAX_MODE 5

int print_page();       /*Ausgabe der Titelseite und starten des Programms*/

int choose_mode();      /*Menue-Auswahl*/
int switch_mode(int mode);      /*Modus-Wechsel*/
int flush_buff();
int back();     /*Erwarten der Eingabe zum Wechsel zum Hauptmenue*/
int back_and_restart(int mode); /*Erwarten der Eingabe zum Wechsel zum Hauptmenue oder Starten einer neuen Simulation*/

void print_anleitung(int method);       /*Ausgabe, welche Zeichen erlaubt sind*/

#endif
