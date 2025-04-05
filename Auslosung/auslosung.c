#include "auslosung.h"

void generate_auslosung_random()        /*Zufaellige Auslosung durchfuehren*/
{
        achtel_gruppen_auslosung(8, achtel_gewinner, achtel_verlierer);
        gruppentausch_random(achtel_gewinner, achtel_verlierer);

        restliche_auslosung(4, vier_gewinner, vier_verlierer, achtel_gewinner);
        restliche_auslosung(2, halb_gewinner, halb_verlierer, vier_gewinner);
        restliche_auslosung(1, final_gewinner, final_verlierer, halb_gewinner);
}

void print_auslosung_random()   /*Zufaellige Auslosung ausgeben*/
{
        int i, j;

        printf("\033[2J");      /*Leeren des Bildschirms*/
        printf("\033[2;H");     /*Setzen des Cursors auf Position (0, 2)*/

        for (i = 0; i < 8; i++) { /*Ausgabe des Achtelfinales*/
                int erster_gewinner = 0;

                for (j = 0; j < 8; j++) {       /*Ueberpruefen, ob Gewinner erster in der Gruppe ist, damit der erste an erster Stelle ausgegeben wird*/
                        if (achtel_gewinner[i] == gruppe[j]) {
                                erster_gewinner = 1;
                        }
                }

                if(erster_gewinner) {
                        printf("\033[5C");      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                        printf("%s", (*achtel_gewinner[i]).name);
                        printf("\033[%i;30H", i * 4 + 2);       /*Aendern der x-Achse auf 30*/
                        printf("vs.");
                        printf("\033[%i;40H", i * 4 + 2);      /*Aendern der x-Achse auf 40*/
                        printf("%s", (*achtel_verlierer[i]).name);
                        printf("\033[3B\n");                    /*Bewegen des Cursors 3 Zeilen nach unten*/
                } else {
                        printf("\033[5C");      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                        printf("%s", (*achtel_verlierer[i]).name);
                        printf("\033[%i;30H", i * 4 + 2);       /*Aendern der x-Achse zu 30*/
                        printf("vs.");
                        printf("\033[%i;40H", i * 4 + 2);       /*Aendern der x-Achse zu 40*/
                        printf("%s", (*achtel_gewinner[i]).name);
                        printf("\033[3B\n");                    /*Bewegen des Cursors 3 Zeilen nach unten*/
                }
        }

        for (i = 0; i < 4; i++) {       /*Ausgabe des Viertelfinales*/
                if (vier_gewinner[i] == achtel_gewinner[2 * i]) {       /*Herausfinden, ob der Gewinner aus dem ersten
                                oder dem zweiten Achtelfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
                        printf("\033[%i;65H", i * 8 + 4);       /*Bewegen des Cursors so,
                                dass die Spalte 65 und die Zeile so ist, dass das Viertelfinale zwischen den Achtelfinalen
                                gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                        printf("%s", (*vier_gewinner[i]).name);
                        printf("\033[%i;90H", i * 8 + 4);       /*Aendern der x-Achse zu 90*/
                        printf("vs.");
                        printf("\033[%i;100H", i * 8 + 4);      /*Aendern der x-Achse zu 100*/
                        printf("%s", (*vier_verlierer[i]).name);
                } else {
                        printf("\033[%i;65H", i * 8 + 4);       /*Bewegen des Cursors so,
                                dass die Spalte 65 und die Zeile so ist, dass das Viertelfinale zwischen den Achtelfinalen
                                gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                        printf("%s", (*vier_verlierer[i]).name);
                        printf("\033[%i;90H", i * 8 + 4);       /*Aendern der x-Achse zu 90*/
                        printf("vs.");
                        printf("\033[%i;100H", i * 8 + 4);      /*Aendern der x-Achse zu 100*/
                        printf("%s", (*vier_gewinner[i]).name);
                }
        }

        for (i = 0; i < 2; i++) {
                if (halb_gewinner[i] == vier_gewinner[2 * i]) { /*Herausfinden, ob der Gewinner aus dem ersten
                                oder dem zweiten Viertelfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
                        printf("\033[%i;125H", i * 16 + 8);     /*Bewegen des Cursors so,
                                dass die Spalte 125 und die Zeile so ist, dass das Viertelfinale zwischen den Viertelfinalen
                                gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                        printf("%s", (*halb_gewinner[i]).name);
                        printf("\033[%i;150H", i * 16 + 8);     /*Aendern der x-Achse zu 150*/
                        printf("vs.");
                        printf("\033[%i;160H", i * 16 + 8);     /*Aendern der x-Achse zu 160*/
                        printf("%s", (*halb_verlierer[i]).name);
                } else {
                        printf("\033[%i;125H", i * 16 + 8);     /*Bewegen des Cursors so,
                                dass die Spalte 125 und die Zeile so ist, dass das Viertelfinale zwischen den Viertelfinalen
                                gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                        printf("%s", (*halb_verlierer[i]).name);
                        printf("\033[%i;150H", i * 16 + 8);     /*Aendern der x-Achse zu 150*/
                        printf("vs.");
                        printf("\033[%i;160H", i * 16 + 8);     /*Aendern der x-Achse zu 160*/
                        printf("%s", (*halb_gewinner[i]).name);
                }
        }
        if (final_gewinner[0] == halb_gewinner[0]) {    /*Herausfinden, ob der Gewinner aus dem ersten
                        oder dem zweiten Halbfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
                printf("\033[16;185H"); /*Aendern der Koordinaten zu (185, 16)*/
                printf("%s", (*final_gewinner[0]).name);
                printf("\033[16;210H"); /*Aendern der Koordinaten zu (210, 16)*/
                printf("vs.");
                printf("\033[16;220H"); /*Aendern der Koordinaten zu (220, 16)*/
                printf("%s", (*final_verlierer[0]).name);
        } else {
                printf("\033[16;185H"); /*Aendern der Koordinaten zu (185, 16)*/
                printf("%s", (*final_verlierer[0]).name);
                printf("\033[16;210H"); /*Aendern der Koordinaten zu (210, 16)*/
                printf("vs.");
                printf("\033[16;220H"); /*Aendern der Koordinaten zu (220, 16)*/
                printf("%s", (*final_gewinner[0]).name);
        }

        printf("\033[40;5H");   /*Gehen zu Position (5, 40)*/
        printf("Champions League Sieger: %s", (*final_gewinner[0]).name); /*Ausgabe des Gewinners,
                Pokale basiern auf ANSII-Art*/
        printf("\033[100;H");   /*Gehen zur untersten Zeile des Terminals*/

}

void generate_auslosung_punkte()        /*Auslosung mit Ergebnissen durchfuehren*/
{
        achtel_gruppen_auslosung_punkte(8, achtel_finale);
        gruppentausch_punkte(achtel_finale);

        restliche_auslosung_punkte(4, viertel_finale, achtel_finale);
        restliche_auslosung_punkte(2, halb_finale, viertel_finale);
        restliche_auslosung_punkte(1, finale, halb_finale);
}

void print_auslosung_punkte()   /*Auslosung mit Ergebnissen ausgeben*/
{
        /*Kommentare: siehe print_auslosung_random() - einziger Unterschied:
                statt 'vs.' wird ausgegeben, wie viel die Mannschaft gegeneinander gespielt haben*/

        int i, j;

        printf("\033[2J");
        printf("\033[2;H");

        for (i = 0; i < 8; i++) {
                int erster_gewinner = 0;

                for (j = 0; j < 8; j++) {
                        if (achtel_finale[i].gewinner == gruppe[i]) {
                                erster_gewinner = 1;
                        }
                }

                if(erster_gewinner) {
                        printf("\033[5C");
                        printf("%s", (*achtel_finale[i].gewinner).name);
                        printf("\033[%i;30H", i * 4 + 2);
                        printf("%i:%i", achtel_finale[i].gewinner_ergebnis, achtel_finale[i].verlierer_ergebnis);
                        printf("\033[%i;40H", i * 4 + 2);
                        printf("%s", (*achtel_finale[i].verlierer).name);
                        printf("\033[3B\n");
                } else {
                        printf("\033[5C");
                        printf("%s", (*achtel_finale[i].verlierer).name);
                        printf("\033[%i;30H", i * 4 + 2);
                        printf("%i:%i", achtel_finale[i].verlierer_ergebnis, achtel_finale[i].gewinner_ergebnis);
                        printf("\033[%i;40H", i * 4 + 2);
                        printf("%s", (*achtel_finale[i].gewinner).name);
                        printf("\033[3B\n");
                }
        }

        for (i = 0; i < 4; i++) {
                if (viertel_finale[i].gewinner == achtel_finale[2 * i].gewinner) {
                        printf("\033[%i;65H", i * 8 + 4);
                        printf("%s", (*viertel_finale[i].gewinner).name);
                        printf("\033[%i;90H", i * 8 + 4);
                        printf("%i:%i", viertel_finale[i].gewinner_ergebnis, viertel_finale[i].verlierer_ergebnis);
                        printf("\033[%i;100H", i * 8 + 4);
                        printf("%s", (*viertel_finale[i].verlierer).name);
                } else {
                        printf("\033[%i;65H", i * 8 + 4);
                        printf("%s", (*viertel_finale[i].verlierer).name);
                        printf("\033[%i;90H", i * 8 + 4);
                        printf("%i:%i", viertel_finale[i].verlierer_ergebnis, viertel_finale[i].gewinner_ergebnis);
                        printf("\033[%i;100H", i * 8 + 4);
                        printf("%s", (*viertel_finale[i].gewinner).name);
                }
        }

        for (i = 0; i < 2; i++) {
                if (halb_finale[i].gewinner == viertel_finale[2 * i].gewinner) {
                        printf("\033[%i;125H", i * 16 + 8);
                        printf("%s", (*halb_finale[i].gewinner).name);
                        printf("\033[%i;150H", i * 16 + 8);
                        printf("%i:%i", halb_finale[i].gewinner_ergebnis, halb_finale[i].verlierer_ergebnis);
                        printf("\033[%i;160H", i * 16 + 8);
                        printf("%s", (*halb_finale[i].verlierer).name);
                } else {
                        printf("\033[%i;125H", i * 16 + 8);
                        printf("%s", (*halb_finale[i].verlierer).name);
                        printf("\033[%i;150H", i * 16 + 8);
                        printf("%i:%i", halb_finale[i].verlierer_ergebnis, halb_finale[i].gewinner_ergebnis);
                        printf("\033[%i;160H", i * 16 + 8);
                        printf("%s", (*halb_finale[i].gewinner).name);
                }
        }
        if (finale[0].gewinner == halb_finale[0].gewinner) {
                printf("\033[16;185H");
                printf("%s", (*finale[0].gewinner).name);
                printf("\033[16;210H");
                printf("%i:%i", finale[0].gewinner_ergebnis, finale[0].verlierer_ergebnis);
                printf("\033[16;220H");
                printf("%s", (*finale[0].verlierer).name);
        } else {
                printf("\033[16;185H");
                printf("%s", (*finale[0].verlierer).name);
                printf("\033[16;210H");
                printf("%i:%i", finale[0].verlierer_ergebnis, finale[0].gewinner_ergebnis);
                printf("\033[16;220H");
                printf("%s", (*finale[0].gewinner).name);
        }

        printf("\033[40;5H");
        printf("Champions League Sieger: %s", (*finale[0].gewinner).name);
        printf("\033[100;H");

}
