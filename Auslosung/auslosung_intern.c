#include "auslosung_intern.h"

/*Diese Methode wird genutzt um die Gruppe des Gegners zu ermitteln*/
int finde_gegner(const int match_anzahl, int *schon_gespielte_gruppen, int random, int finale)
{
          int i, j;
          /*Gruppen_nummer speichert temporär die Gruppennummer vom Gegner und 
          wird verändert bis sie einer Gruppe entspricht, die noch nicht gespielt hat*/
          int gruppen_nummer = random;
          gruppen_nummer = gruppen_nummer % finale;

          /*Überprüft ob die Mannschaft schon gespielt hat.
          Falls ja, dann wird sie um 1 größer und nochmal überprüft, 
          bis die Gegnergruppennummer noch nicht benützt wurde*/
          for(j = 0; j < match_anzahl; j++) {
                  for(i = 0; i < match_anzahl; i++) {
                          if(gruppen_nummer == schon_gespielte_gruppen[i]) {
                                  gruppen_nummer++;
                          }
                          if(gruppen_nummer >= finale) {
                                  gruppen_nummer = 0;
                          }
                  }
          }
          /*Gibt die Gegnergruppennummer zurück*/
          return gruppen_nummer;
}

/*Tauscht 8 mal die Gruppen. Damit im Viertelfinale nicht immer die gleichen Mannschaften spielen*/
void gruppentausch_random(struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer) {
  struct mannschaften *teamtemp; /* Speichert temporär eine Mannschaft*/
  int i;

  teamtemp = NULL; /* muss zuerst initialisier werden damit der pointer nicht ins nichts zeigt*/

  /*Tauscht 8 mal die Achtelfinalegewinner / -verlierer*/
  for(i = 0; i < 8; i++) {
          int random_eins = rand() % 8; /*ermittelt eine zahl zwischen eingeschlossen 0 und 7*/
          int random_zwei = rand() % 8; /*ermittelt eine zahl zwischen eingeschlossen 0 und 7*/

          teamtemp = *(temp_gewinner + random_eins);
          *(temp_gewinner + random_eins) = *(temp_gewinner + random_zwei);
          *(temp_gewinner + random_zwei) = teamtemp;

          teamtemp = *(temp_verlierer + random_eins);
          *(temp_verlierer + random_eins) = *(temp_verlierer + random_zwei);
          *(temp_verlierer + random_zwei) = teamtemp;
  }
}

/*tauscht 8 mal die Gruppen. Damit im Viertelfinale nicht immer die gleichen Mannschaften spielen*/
void gruppentausch_punkte(struct spiel *spiele)
{
        struct spiel spiel_temp;

        int i;
        /*Tauscht 8 mal die Gewinner, die Verlierer und die Ergebnisse*/
        for (i = 0; i < 8; i++) {
                int random_eins = rand() % 8; /*ermittelt eine zahl zwischen eingeschlossen 0 und 7*/
                int random_zwei = rand() % 8; /*ermittelt eine zahl zwischen eingeschlossen 0 und 7*/

                spiel_temp = *(spiele + random_eins);
                *(spiele + random_eins) = *(spiele + random_zwei);
                *(spiele + random_zwei) = spiel_temp;
        }

}
