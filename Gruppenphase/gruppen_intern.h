#ifndef GRUPPEN_INTERN_H_INCLUDED
#define GRUPPEN_INTERN_H_INCLUDED

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING 20

#define VALID_INPUT 0
#define INVALID_INPUT 1
#define BUFFER_ERROR 2

struct mannschaften {
        char name[MAX_STRING];  /*Name der Mannschaft*/
        int tordifferenz;       /*Tordifferenz der Mannschaft in der Gruppenphase*/
        int punkte;             /*Gesamtpunktzahl aus der Gruppenphase*/
};

int is_Gruppe_A_to_H(char *string);     /*Ueberpruefung, ob String aus "Gruppe" und einem Grossbuchstaben von A bis H besteht*/
int read_string(FILE *file, char *string);      /*Liest String aus einer File (fuer Mannschaftsnamen)*/
int read_games(FILE *file, struct mannschaften gruppe[]);       /*Liest aus einer File ein bestimmtes Format aus (fuer Gruppenspiele)*/

int winner(int tore_eins, int tore_zwei);       /*Ueberprueft anhand der Tore, wer gewonnen hat*/
int sign(int number);   /*Gibt Vorzeichen der mitgegebenen Zahl mit*/

int ist_team_number(int team);  /*Ueberprueft, ob die Zahl zwischen 1 und 4 liegt*/
int ist_goal_number(int goal);  /*Ueberprueft, ob die Zahl >= 0 ist*/

#endif
