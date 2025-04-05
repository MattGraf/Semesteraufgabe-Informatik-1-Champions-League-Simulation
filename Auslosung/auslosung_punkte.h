#ifndef AUSLOSUNG_PUNKTE_H_INCLUDED
#define AUSLOSUNG_PUNKTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "auslosung_intern.h"
#include "../Gruppenphase/gruppen.h"

/*Wird genützt um die Gewinner, die Verlierer und die Ergbnisse zu speichern*/
struct spiel {
  struct mannschaften *gewinner;
  struct mannschaften *verlierer;
  int gewinner_ergebnis;
  int verlierer_ergebnis;
};

/*Wird genützt um die Gewinner, die Verlierer und die Ergbnisse, der Finale zu speichern*/
extern struct spiel achtel_finale[8];
extern struct spiel viertel_finale[4];
extern struct spiel halb_finale[2];
extern struct spiel finale[1];

/*Diese Methoden werden genutzt um das Turnier zu simulieren*/
int achtel_gruppen_auslosung_punkte(int finale, struct spiel *achtel_finale);
int restliche_auslosung_punkte(int finale, struct spiel *jetzt_finale, struct spiel *vor_finale);
int elfmeter(int elfmeterergebnisse[2]);

#endif
