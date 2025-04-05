#include "auslosung_punkte.h"

/*Die Variablen speichern die Gewinner, die Verlierer und die Ergebnisse jeder Finale*/
struct spiel achtel_finale[8];
struct spiel viertel_finale[4];
struct spiel halb_finale[2];
struct spiel finale[1];

/*Ermittelt die Gewinner der einzelnen Finalen und speichert die Gewinner, die Verlierer und die Ergbenisse */
int restliche_auslosung_punkte(int finale, struct spiel *jetzt_finale, struct spiel *vor_finale)
{
        /*Speichert temporär die Ergebnisse der Spiele*/
        int ergebnis_eins;
        int ergebnis_zwei;

        /*Im Viertelfinale und weiter spielt die erste Mannschaft gegen die Darauffolgende*/
        int team_nummer_eins = 0;
        int team_nummer_zwei = 1;

        int i;

        /*speichert die Gerbnisse des Elfmeterschießens*/
        int elfmeterergebnisse[2];

        srand(time (NULL));

        for(i = 0; i < finale; i++) {
                /*Ermittelt die Ergebisse der Teams*/
                ergebnis_eins = rand() % 5;
                ergebnis_zwei = rand() % 5;
                /*Vergleicht die Ergebnisse und schaut welche Mannschaft gewonnen hat. 
                Die Ergebnisse müssen unterschiedlich sein. 
                Speichert die Ergebnisse und die Mannschaften in den Structs, welche der Methode mitgegeben wurden*/
                if(ergebnis_eins > ergebnis_zwei) {
                        jetzt_finale[i].gewinner = vor_finale[team_nummer_eins].gewinner;
                        jetzt_finale[i].gewinner_ergebnis = ergebnis_eins;
                        jetzt_finale[i].verlierer = vor_finale[team_nummer_zwei].gewinner;
                        jetzt_finale[i].verlierer_ergebnis = ergebnis_zwei;
                } else {
                        jetzt_finale[i].gewinner = vor_finale[team_nummer_zwei].gewinner;
                        jetzt_finale[i].gewinner_ergebnis = ergebnis_zwei;
                        jetzt_finale[i].verlierer = vor_finale[team_nummer_eins].gewinner;
                        jetzt_finale[i].verlierer_ergebnis = ergebnis_eins;
                }

                if(ergebnis_zwei == ergebnis_eins) {
                        /*Vergleicht die Ergebnisse des Elfmeterschießens. 
                        Speichert den Gewinner, den Verlierer und die Ergebnisse.*/
                        elfmeter(elfmeterergebnisse);
                        if(elfmeterergebnisse[0] > elfmeterergebnisse[1]) {
                                jetzt_finale[i].gewinner = vor_finale[team_nummer_eins].gewinner;
                                jetzt_finale[i].gewinner_ergebnis = elfmeterergebnisse[0];
                                jetzt_finale[i].verlierer = vor_finale[team_nummer_zwei].gewinner;
                                jetzt_finale[i].verlierer_ergebnis = elfmeterergebnisse[1];
                        } else {
                                jetzt_finale[i].gewinner = vor_finale[team_nummer_zwei].gewinner;
                                jetzt_finale[i].gewinner_ergebnis = elfmeterergebnisse[1];
                                jetzt_finale[i].verlierer = vor_finale[team_nummer_eins].gewinner;
                                jetzt_finale[i].verlierer_ergebnis = elfmeterergebnisse[0];
                        }
                }
                /*Nach jedem Spiel werden die Teams gewechselt*/
                team_nummer_eins = team_nummer_eins + 2;
                team_nummer_zwei = team_nummer_zwei + 2;
        }
        return 0;
}

/*Simuliert die ersten 8 Spiele im Achtelfinale. Benützt einen Pointerstruct um die Adressen der Gewinner und der Verlierer zu speichern. 
Speichert auch die Ergebnisse. Es spielen immer das Team, das die Gruppe gewonnen hat und der zweite einer anderen Gruppe*/
int achtel_gruppen_auslosung_punkte(int finale, struct spiel *achtel_finale)
{
/*Speichert die Nummer der Gengerteams, welche schon gespielt haben*/
  int *gegner_gruppe;
/*Speichert temporär die Nummer des Gegnerteams*/
  int gegner_gruppe_nummer;
/*Speichert temporär die Ergebnisse der Spiele*/
  int ergebnis_eins;
  int ergebnis_zwei;
  int i;

/*Speichert die Ergebnisse falls es zu einem Elfmeterschießen kommt*/
  int elfmeterergebnisse[2];

  srand(time (NULL));

  gegner_gruppe = malloc(finale * sizeof(int));

  for(i = 0; i < finale; i++) {
    /*Ermittelt die Ergebisse der Teams*/
    ergebnis_eins = rand() % 5;
    ergebnis_zwei = rand() % 5;
    /*Ermittelt eine Randomzahl für die Gegnergruppe, die in der Methode finde_gegner() 
    angepasst wird. Sie muss zwischen 0 und 7 sein, da diese in dem Gruppenarray benützt werden*/
    gegner_gruppe_nummer = rand();
    gegner_gruppe_nummer = finde_gegner(i, gegner_gruppe, gegner_gruppe_nummer, finale);
    /*Speichert die Gegnernummer damit sie nicht nochmal ausgewählt wird*/
    gegner_gruppe[i] = gegner_gruppe_nummer;
    /*Vergleicht die Ergebnisse und schaut welche Mannschaft gewonnen hat. Die Ergebnisse müssen unterschiedlich sein. 
    Speichert die Ergebnisse und die Mannschaften in den Structs, welche der Methode mitgegeben wurden*/
    if(ergebnis_eins > ergebnis_zwei) {
      achtel_finale[i].gewinner = &(gruppe[i][0]);
      achtel_finale[i].gewinner_ergebnis = ergebnis_eins;
      achtel_finale[i].verlierer = &(gruppe[gegner_gruppe_nummer][1]);
      achtel_finale[i].verlierer_ergebnis = ergebnis_zwei;
    } else {
      achtel_finale[i].gewinner = &(gruppe[gegner_gruppe_nummer][1]);
      achtel_finale[i].gewinner_ergebnis = ergebnis_zwei;
      achtel_finale[i].verlierer = &(gruppe[i][0]);
      achtel_finale[i].verlierer_ergebnis = ergebnis_eins;
    }

    /*Falls die Ergebnisse gleich sind, wird es ein Elmeterschießen geben*/
    if(ergebnis_zwei == ergebnis_eins) {
      /*Elfmeter schießen. Man gibt ein array mit um die Ergbenisse zu speichern*/
      elfmeter(elfmeterergebnisse);
      /*Vergleicht die Ergebnisse des Elfmeterschießens. 
      Speichert den Gewinner, den Verlierer und die Ergebnisse.*/
      if(elfmeterergebnisse[0] > elfmeterergebnisse[1]) {
        achtel_finale[i].gewinner = &(gruppe[i][0]);
        achtel_finale[i].gewinner_ergebnis = elfmeterergebnisse[0];
        achtel_finale[i].verlierer = &(gruppe[gegner_gruppe_nummer][1]);
        achtel_finale[i].verlierer_ergebnis = elfmeterergebnisse[1];
      } else {
        achtel_finale[i].gewinner = &(gruppe[gegner_gruppe_nummer][1]);
        achtel_finale[i].gewinner_ergebnis = elfmeterergebnisse[1];
        achtel_finale[i].verlierer = &(gruppe[i][0]);
        achtel_finale[i].verlierer_ergebnis = elfmeterergebnisse[0];
      }
    }
  }
  free(gegner_gruppe);
  return 0;
}

/*Ermittelt das Elfmeterschießen und gibt die Ergebnisse zurück*/
int elfmeter(int elfmeterergebnisse[2])
{
        /*speichert temporär ddie Ergbenisse des Elfmeterschießen*/
        int elfmeter_eins = 0;
        int elfmeter_zwei = 0;

        /*Die Variablen werden in der While-Loop zu den Ergebnissen*/
        int elfmeterschuss_eins;
        int elfmeterschuss_zwei;

        /*speichert die Runde*/
        int runde = 1;
        /*Gibt die Runden an die man noch spielen kann*/
        int noch_zu_spielen = 5;

        /*Gibt den Betrag des Unterschiedes von elfmeter_eins und elfmeter_zwei an*/
        int diferenz;

        int fertig = 1;

        /*Ermittelt die Ergbnisse. Jeder Elmeterschuss ist zu 50% ein treffer. 
        Falls eine Mannschaft nicht mehr verlieren kann wird das Elfmeterschießen beendet. 
        Wenn nach 5 Rundne die Erbenisse gleich sind, 
        wird nur darauf geschaut wann eine Mannschat trifft und wann eine Mannschaft nicht trift um den Gewinner zu 
        ermitteln*/
        while (fertig) {
                elfmeterschuss_eins = rand() % 2;
                if(elfmeterschuss_eins) {
                        elfmeter_eins++;
                }
                elfmeterschuss_zwei = rand() % 2;
                if(elfmeterschuss_zwei) {
                        elfmeter_zwei++;
                }
                noch_zu_spielen = 5 - runde;
                diferenz = abs(elfmeter_eins - elfmeter_zwei);
                /* Gibt zurück wenn eine Mannschaft nicht mehr verlieren kann*/
                if(diferenz > noch_zu_spielen && runde < 5) {
                        fertig = 0;
                }
                /* Gibt zurück ob eine Mannschaft nach den 5 Runden gewonnen hat*/
                if(runde >= 5 && elfmeter_eins != elfmeter_zwei) {
                        fertig = 0;
                }
                runde++;
        }

        /*Hier werden die Ergebnisse gespeichert*/
        elfmeterergebnisse[0] = elfmeter_eins;
        elfmeterergebnisse[1] = elfmeter_zwei;
        return 0;
}
