#ifndef AUSLOSUNG_RANDOM_H_INCLUDED
#define AUSLOSUNG_RANDOM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "auslosung_intern.h"
#include "../Gruppenphase/gruppen.h"

/*Diese Methoden ermitteln die Gewinner und Verlierer des Turniers */
int achtel_gruppen_auslosung(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer);
int restliche_auslosung(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, struct mannschaften **before_gewinner);

/*Diese Methoden speichern die Gewinner und Verlierer des Turniers */
extern struct mannschaften *achtel_gewinner[8];
extern struct mannschaften *achtel_verlierer[8];

extern struct mannschaften *vier_gewinner[4];
extern struct mannschaften *vier_verlierer[4];

extern struct mannschaften *halb_gewinner[2];
extern struct mannschaften *halb_verlierer[2];

extern struct mannschaften *final_gewinner[1];
extern struct mannschaften *final_verlierer[1];

#endif
