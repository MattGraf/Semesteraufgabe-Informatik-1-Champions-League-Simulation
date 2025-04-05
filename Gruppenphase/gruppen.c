#include "gruppen.h"

struct mannschaften gruppe[8][4];

int read_groups(void)   /*Einlesen der Gruppenphase*/
{
        int i, j;
        int check_error; /*Fehlerueberpruefung*/

        FILE *gruppen;
        gruppen = fopen("Gruppen.txt","r");

        if (gruppen == NULL) {
                printf("File can not be opened.");
                return 1;
        }


        for (i = 0; i < 8; i++) {
                for (j = 0; j < 4; j++) { /*Lesen der Mannschaften der jeweiligen Gruppe*/
                        char *teamname = gruppe[i][j].name;

                        while (is_Gruppe_A_to_H(teamname) || !strcmp(teamname, "")) {
                                check_error = read_string(gruppen, teamname);
                                if (check_error == BUFFER_ERROR) {
                                        return BUFFER_ERROR;
                                }
                        }

                }

                for (j = 0; j < 12; j++) { /*Lesen der Spiele der jeweiligen Gruppe*/
                        check_error = read_games(gruppen, gruppe[i]);

                        if (check_error == BUFFER_ERROR) {
                                return BUFFER_ERROR;
                        } else if (check_error == INVALID_INPUT) {
                                return INVALID_INPUT;
                        }
                }

        }


        return VALID_INPUT;
}

int order_groups()      /*Neuordnung der Gruppen*/
{
        int i, j, k;
        int successfull;
        int hoechste_punkte;
        int beste_mannschaft;

        successfull = 1;

        for (i = 0; i < 8; i++) { /*Durchgehen aller Gruppen*/
                for (j = 0; j < 3; j++) { /*Nur Notwendigkeit zur Ueberpruefung von drei Mannschaften*/
                        struct mannschaften temp = gruppe[i][j]; /*Naechste ungeordnete Mannschaft in der Gruppe*/
                        hoechste_punkte = 0;
                        beste_mannschaft = 0;

                        for (k = j; k < 4; k++) { /*Herausfiltern der besten Mannschaft aus den uebrigen Teams*/
                                if (gruppe[i][k].punkte > hoechste_punkte) {
                                        hoechste_punkte = gruppe[i][k].punkte;
                                        beste_mannschaft = k;

                                } else if (gruppe[i][k].punkte == hoechste_punkte && hoechste_punkte != 0) {
                                        if (gruppe[i][k].tordifferenz > gruppe[i][beste_mannschaft].tordifferenz) {
                                                beste_mannschaft = k;
                                        }
                                }
                        }

                        gruppe[i][j] = gruppe[i][beste_mannschaft]; /*Zuordnung der besten uebrigen Mannschaft an naechster Position in der Gruppe*/
                        gruppe[i][beste_mannschaft] = temp; /*Zuordnung der Mannschaft, die vorher an dieser Position war, an alter Position der anderen Mannschaft*/
                }
        }

        return successfull;
}

void print_groups()     /*Ausgabe der Gruppen*/
{
        int i, j;

        printf("\033[2J"); /*Leeren der Terminalseite*/
        printf("\033[2;H"); /*Bewegen der Position des Cursors (wo bei Ausgabe ausgegeben wird) an Position (2, 0) des Terminals*/

        for (i = 0; i < 8; i++) {
                printf("\033[5C");      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                printf("\033[1m");      /*Anschalten von fetter Schrift*/
                printf("\033[4m");      /*Anschalten von unterstrichener Schrift*/
                printf("Gruppe %c\n", 'A' + i); /*Ausgabe der aktuellen Gruppe*/
                printf("\033[24m");     /*Ausschalten von unterstrichener Schrift*/
                printf("\033[22m");     /*Ausschalten von fetter Schrift*/
                for (j = 0; j < 4; j++) {
                        printf("\033[5C");      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                        printf("%s\t", gruppe[i][j].name);      /*Ausgabe des Teamnamens*/

                        printf("\033[%i;30H", i * 6 + j + 3);   /*Aendern der aktuellen x-Koordinate zu 30*/
                        printf("%i\t", gruppe[i][j].tordifferenz);      /*Ausgabe der Tordifferenz*/

                        printf("\033[%i;40H", i * 6 + j + 3);   /*Aendern der aktuellen x-Koordinate zu 40*/
                        printf("%i\n", gruppe[i][j].punkte);     /*Ausgabe der Punkte*/
                }
                printf("\n");
        }

        printf("\033[100;H");   /*Bewegen des Cursors zum Punkt (0, 100), was meistens (aufgrund zu niedriger Zahl) der untersten Zeile entspricht*/
}
