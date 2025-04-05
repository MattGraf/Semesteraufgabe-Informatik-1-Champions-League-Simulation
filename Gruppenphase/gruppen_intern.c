#include "gruppen_intern.h"

int is_Gruppe_A_to_H(char *string)      /*Ueberpruefung, ob String aus "Gruppe" und einem Grossbuchstaben von A bis H besteht*/
{
        int i;
        int erg = 0;
        for (i = 0; i < 8 && !erg; i++) {
                char group[] = "Gruppe A";
                group[7] += i;  /*Erhoeht das Zeichen 'A' um i: Also geht von 'A' bis 'H' durch*/
                erg = !strcmp(string, group);
        }
        return erg;
}

int read_string(FILE *file, char *string)       /*Liest String aus einer File (fuer Mannschaftsnamen)*/
{
        char new_string[MAX_STRING] = {0};      /*Zwischenspeicher fuer den auszulesenden String*/
        int i; /*aktuelle Position im String-Zwischenspeicher*/
        char c; /*Zwischenspeicher fuers naechste Zeichen*/

        i = 0;
        c = fgetc(file); /*Zuweisenung vom naechsten Zeichen aus der File zu c*/

        if (c == EOF) {
                return BUFFER_ERROR;
        }

        strcpy(string, "");
        while (isprint(c)) { /*Ueberpruefung, ob in c ein druckbares Zeichen ist*/
                new_string[i] = c;
                c = fgetc(file);
                i++;
        }
        strncpy(string, new_string, MAX_STRING - 1); /*Kopieren des Zwischenspeicher-Strings in mitgegenen String*/
        string[MAX_STRING - 1] = '\0'; /*An letzter Stelle vom mitgegebenen String eine binaere 0 einfuegen*/

        return VALID_INPUT;
}

int read_games(FILE *file, struct mannschaften gruppe[])        /*Liest aus einer File ein bestimmtes Format aus (fuer Gruppenspiele)*/
{
        int status;
        int team_heim, team_aus, tore_heim, tore_aus;
        int gewinner;

        status = fscanf(file, "%i : %i = %i:%i", &team_heim, &team_aus, &tore_heim, &tore_aus);

        if (status == EOF) {
                return BUFFER_ERROR;
        }

        if (status != 4 || !(ist_team_number(team_heim) && ist_team_number(team_aus) && /*Ueberpruefung, ob Eingabe gueltig ist*/
        ist_goal_number(tore_heim) && ist_goal_number(tore_aus)) || fgetc(file) != '\n') {
                return INVALID_INPUT;
        }

        gewinner = winner(tore_heim, tore_aus);

        switch (gewinner) { /*Zuordnung der im Spiel erhaltenen Punkte und der Tordifferenz, den entsprechenden Teams*/
                case 1:
                        gruppe[team_heim - 1].punkte += 3;
                        gruppe[team_heim - 1].tordifferenz += tore_heim - tore_aus;
                        gruppe[team_aus - 1].tordifferenz += tore_aus - tore_heim;
                        break;
                case 2:
                        gruppe[team_aus - 1].punkte += 3;
                        gruppe[team_heim - 1].tordifferenz += tore_heim - tore_aus;
                        gruppe[team_aus - 1].tordifferenz += tore_aus - tore_heim;
                        break;
                default:
                        gruppe[team_heim - 1].punkte += 1;
                        gruppe[team_aus - 1].punkte += 1;
        }

        return VALID_INPUT;
}


int winner(int tore_eins, int tore_zwei)        /*Ueberprueft anhand der Tore, wer gewonnen hat*/
{
        int tordifferenz;
        int rueckgabe;

        tordifferenz = tore_eins - tore_zwei;
        tordifferenz = sign(tordifferenz);

        switch(tordifferenz) {
                case 1:
                        rueckgabe = 1;
                        break;
                case -1:
                        rueckgabe = 2;
                        break;
                default:
                        rueckgabe = 0;
        }

        return rueckgabe;
}

int sign(int number)    /*Gibt Vorzeichen der mitgegebenen Zahl mit*/
{
        int rueckgabe;
        if (number > 0) {
                rueckgabe = 1;
        } else if (number < 0) {
                rueckgabe = -1;
        } else {
                rueckgabe = 0;
        }
        return rueckgabe;
}

int ist_team_number(int team)   /*Ueberprueft, ob die Zahl zwischen 1 und 4 liegt*/
{
        int rueckgabe;
        if (team > 0 && team < 5) {
                rueckgabe = 1;
        } else {
                rueckgabe = 0;
        }

        return rueckgabe;
}

int ist_goal_number(int goal)   /*Ueberprueft, ob die Zahl >= 0 ist*/
{
        int rueckgabe;
        if (goal >= 0) {
                rueckgabe = 1;
        } else {
                rueckgabe = 0;
        }
        return rueckgabe;
}
