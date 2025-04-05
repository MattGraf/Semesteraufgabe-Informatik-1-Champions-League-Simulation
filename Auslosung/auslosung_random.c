#include "auslosung_random.h"

/*Speichert die Gewinner und Verlierer jedes Finales, um Sie ausgeben zu können*/
struct mannschaften *achtel_gewinner[8];
struct mannschaften *achtel_verlierer[8];

struct mannschaften *vier_gewinner[4];
struct mannschaften *vier_verlierer[4];

struct mannschaften *halb_gewinner[2];
struct mannschaften *halb_verlierer[2];

struct mannschaften *final_gewinner[1];
struct mannschaften *final_verlierer[1];

/*Ermittelt die Gewinner der einzelnen Finalen und speichert die Gewinner und Verlierer*/
int restliche_auslosung(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, struct mannschaften **before_gewinner)
{
          int coinflip;

          /*Im Viertelfinale und weiter spielen die erste Mannschaft mit der Darauffolgenden.*/
          int team_eins = 0;
          int team_zwei = 1;

          int i;

          srand(time (NULL));

          for(i = 0; i < finale; i++) {
            /*Ermittlung der Random zahlen*/
            coinflip = rand();
            /*Ermittelt den Sieger. Wenn der coinflip gleich 0 ist, dan Gewinnt die erste Mannschaft 
            und wenn sie 1 ist gewinnt die zweite Mannschaft.
            Speichert die Gewinner und Verlierer*/
            if(coinflip % 2 == 0) {
              temp_gewinner[i] =  before_gewinner[team_eins];
              temp_verlierer[i] = before_gewinner[team_zwei];
            } else {
              temp_gewinner[i] =  before_gewinner[team_zwei];
              temp_verlierer[i] = before_gewinner[team_eins];
            }
            /*Wechselt die Teams nach jedem Spiel*/
            team_eins = team_eins + 2;
            team_zwei = team_zwei + 2;
          }
          return 0;
}

/*Simuliert die ersten 8 Spiele im Achetelfinale. Benützt Pointer um die Adressen der Gewinner und Verlierer zu speichern.*/
int achtel_gruppen_auslosung(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer)
{
          /*Speichert die Nummer der Gengerteams, welche schon gespielt haben*/
          int *gegner_gruppe;
          
          /*Ermittelt eine Random für die Gegnerische zahl die in der Methode finde_gegner() 
          angepasst um zwischen eingeschlossen 1 und 7 zu sein*/
          int gegner_gruppe_nummer;

          /*Wir verwendet um den Gewinner/ Vertlierer zu ermitteln*/
          int coinflip;

          int i;

          srand(time (NULL));

          gegner_gruppe = malloc(finale * sizeof(int));

          for(i = 0; i < finale; i++) {
                    /*Ermittlung der Random zahlen*/
                    coinflip = rand();
                    gegner_gruppe_nummer = rand();
                    /*Ermittelt eine Randomzahl für die Gegnergruppe, die in der Methode finde_gegner() 
                    angepasst wird. Sie muss zwischen 0 und 7 sein, da diese in dem Gruppenarray benützt werden*/
                    gegner_gruppe_nummer = finde_gegner(i, gegner_gruppe, gegner_gruppe_nummer, finale);
                    /*Speichert die Gegnernummer damit sie nicht nochmal ausgewählt wird*/
                    gegner_gruppe[i] = gegner_gruppe_nummer;
                    /*Ermittelt den Sieger. Wenn der coinflip gleich 0 ist, dan Gewinnt die erste Mannschaft 
                    und wenn sie 1 ist gewinnt die zweite Mannschaft.
                    Speichert die Gewinner und Verlierer*/
                    if(coinflip % 2 == 0) {
                            temp_gewinner[i] = &(gruppe[i][0]);
                            temp_verlierer[i] = &(gruppe[gegner_gruppe_nummer][1]);
                    } else {
                            temp_gewinner[i] = &(gruppe[gegner_gruppe_nummer][1]);
                            temp_verlierer[i] = &(gruppe[i][0]);
                    }
          }
          free(gegner_gruppe);
          return 0;
}
