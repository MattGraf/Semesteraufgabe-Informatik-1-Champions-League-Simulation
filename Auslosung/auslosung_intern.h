#ifndef AUSLOSUNG_INTERN_H_INCLUDED
#define AUSLOSUNG_INTERN_H_INCLUDED

#include <stdlib.h>

#include "auslosung_punkte.h"
#include "../Gruppenphase/gruppen_intern.h"

/*Diese Methoden werden genutzt, damit nach dem Achtelfinale nicht immer die gleichen teams gegeneinander spielen*/
void gruppentausch_random(struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer);
void gruppentausch_punkte(struct spiel *spiele);
/*Diese Methode wird genutzt um die Gruppe des Gegners zu ermitteln*/
int finde_gegner(const int match_anzahl, int *schon_gespielte_gruppen, int random, int finale);


#endif
