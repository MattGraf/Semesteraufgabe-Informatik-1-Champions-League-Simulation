#ifndef WETTEN_H_INCLUDED
#define WETTEN_H_INCLUDED

#include "../Auslosung/auslosung_random.h"
#include "../Titelseite/titelseite.h"
#include "../Farben/farben.h"

/*Führt die Wette aus*/
int wetten(void);
/*Ausgabe*/
int wette(int wett_geld, int *gewinner_zahl);
/*Vergleicht das Ergebnis mit dem Getippten Ergebnissen*/
int wette_eingabe(int *wett_geld, int gewinner_zahl);
/*Simuliert das Turnier*/
int restliche_auslosung_punkte_wetten(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, struct mannschaften **before_gewinner, int *gewinner_zahl);
int achtel_gruppen_auslosung_wetten(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, int *gewinner_zahl);

void print_anleitung_wette(); /*Ausgabe der Anleitung fuer die Wette*/
void delete_anleitung_wette();

#endif
