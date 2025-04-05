#include "wetten.h"

/*Ermittelt ob der Gewinner gewonnen oder verloren hat*/
int wetten(void)
{
    /*Speichert alle Ergebnisse des Turniers in der Form von 1 und 0 für jedes Spiel*/
    int gewinner_zahl[15];
    /*Der Wetteinsatz*/
    int wett_geld = 5;

    achtel_gruppen_auslosung_wetten(8, achtel_gewinner, achtel_verlierer, gewinner_zahl);
    gruppentausch_random(achtel_gewinner, achtel_verlierer);

    restliche_auslosung_punkte_wetten(4, vier_gewinner, vier_verlierer, achtel_gewinner, gewinner_zahl + 8);
    restliche_auslosung_punkte_wetten(2, halb_gewinner, halb_verlierer, vier_gewinner, gewinner_zahl + 12);
    restliche_auslosung_punkte_wetten(1, final_gewinner, final_verlierer, halb_gewinner, gewinner_zahl + 14);


    return wette(wett_geld, gewinner_zahl);
}

int wette(int wett_geld, int *gewinner_zahl) { /*Ausgabe der Wette*/

    int i, j;

    int counter;
    counter = 0;

    printf("\033[2J");      /*Leeren des Bildschirms*/

    print_anleitung_wette();

    printf("\033[2;5H");        /*Setzen des Cursors auf Position (5, 2)*/
    printf("Team 1");
    printf("\033[2;40H");       /*Gehe an Position (40, 2)*/
    printf("Team 2");

    printf("\033[43;5H");       /*Gehe an Position (5, 43)*/
    printf("Budget: ");
    setColour_FG(1);            /*Setzen der Farbe auf Weiss*/
    printf("%i", wett_geld);

    printf("\033[44;5H");       /*Gehe an Position (5, 44)*/
    printf("Letzte Wette: -");

    for (i = 0; i < 8; i++) { /*Ausgabe des Achtelfinales*/
            int erster_gewinner = 0;

            for (j = 0; j < 8; j++) {       /*Ueberpruefen, ob Gewinner erster in der Gruppe ist, damit der erste an erster Stelle ausgegeben wird*/
                    if (achtel_gewinner[i] == gruppe[j]) {
                            erster_gewinner = 1;
                    }
            }

            if(erster_gewinner) {
                    printf("\033[%i;5H", i * 4 + 5);      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                    printf("%s", (*achtel_gewinner[i]).name);
                    printf("\033[%i;30H", i * 4 + 5);       /*Aendern der x-Achse auf 30*/
                    printf("vs.");
                    printf("\033[%i;40H", i * 4 + 5);      /*Aendern der x-Achse auf 40*/
                    printf("%s", (*achtel_verlierer[i]).name);
                    printf("\033[3B\n");                    /*Bewegen des Cursors 3 Zeilen nach unten*/
            } else {
                    printf("\033[%i;5H", i * 4 + 5);      /*Bewegen des Cursors um 5 Spalten nach rechts*/
                    printf("%s", (*achtel_verlierer[i]).name);
                    printf("\033[%i;30H", i * 4 + 5);       /*Aendern der x-Achse zu 30*/
                    printf("vs.");
                    printf("\033[%i;40H", i * 4 + 5);       /*Aendern der x-Achse zu 40*/
                    printf("%s", (*achtel_gewinner[i]).name);
            }

            wette_eingabe(&wett_geld, gewinner_zahl[counter]);
            counter++;
    }

    for (i = 0; i < 4; i++) {       /*Ausgabe des Viertelfinales*/
            if (vier_gewinner[i] == achtel_gewinner[2 * i]) {       /*Herausfinden, ob der Gewinner aus dem ersten
                            oder dem zweiten Achtelfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
                    printf("\033[%i;65H", i * 8 + 7);       /*Bewegen des Cursors so,
                            dass die Spalte 65 und die Zeile so ist, dass das Viertelfinale zwischen den Achtelfinalen
                            gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                    printf("%s", (*vier_gewinner[i]).name);
                    printf("\033[%i;90H", i * 8 + 7);       /*Aendern der x-Achse zu 90*/
                    printf("vs.");
                    printf("\033[%i;100H", i * 8 + 7);      /*Aendern der x-Achse zu 100*/
                    printf("%s", (*vier_verlierer[i]).name);
            } else {
                    printf("\033[%i;65H", i * 8 + 7);       /*Bewegen des Cursors so,
                            dass die Spalte 65 und die Zeile so ist, dass das Viertelfinale zwischen den Achtelfinalen
                            gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                    printf("%s", (*vier_verlierer[i]).name);
                    printf("\033[%i;90H", i * 8 + 7);       /*Aendern der x-Achse zu 90*/
                    printf("vs.");
                    printf("\033[%i;100H", i * 8 + 7);      /*Aendern der x-Achse zu 100*/
                    printf("%s", (*vier_gewinner[i]).name);
            }

            wette_eingabe(&wett_geld, gewinner_zahl[counter]);
            counter++;
    }

    for (i = 0; i < 2; i++) {
            if (halb_gewinner[i] == vier_gewinner[2 * i]) { /*Herausfinden, ob der Gewinner aus dem ersten
                            oder dem zweiten Viertelfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
                    printf("\033[%i;125H", i * 16 + 11);     /*Bewegen des Cursors so,
                            dass die Spalte 125 und die Zeile so ist, dass das Viertelfinale zwischen den Viertelfinalen
                            gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                    printf("%s", (*halb_gewinner[i]).name);
                    printf("\033[%i;150H", i * 16 + 11);     /*Aendern der x-Achse zu 150*/
                    printf("vs.");
                    printf("\033[%i;160H", i * 16 + 11);     /*Aendern der x-Achse zu 160*/
                    printf("%s", (*halb_verlierer[i]).name);
            } else {
                    printf("\033[%i;125H", i * 16 + 11);     /*Bewegen des Cursors so,
                            dass die Spalte 125 und die Zeile so ist, dass das Viertelfinale zwischen den Viertelfinalen
                            gedruckt wird, aus denen die Mannschaften hervorgegangen sind*/
                    printf("%s", (*halb_verlierer[i]).name);
                    printf("\033[%i;150H", i * 16 + 11);     /*Aendern der x-Achse zu 150*/
                    printf("vs.");
                    printf("\033[%i;160H", i * 16 + 11);     /*Aendern der x-Achse zu 160*/
                    printf("%s", (*halb_gewinner[i]).name);
            }

            wette_eingabe(&wett_geld, gewinner_zahl[counter]);
            counter++;
    }

    if (final_gewinner[0] == halb_gewinner[0]) {    /*Herausfinden, ob der Gewinner aus dem ersten
                    oder dem zweiten Halbfinale kommt, die Mannschaft aus dem ersten wird zuerst gedruckt*/
            printf("\033[19;185H"); /*Aendern der Koordinaten zu (185, 16)*/
            printf("%s", (*final_gewinner[0]).name);
            printf("\033[19;210H"); /*Aendern der Koordinaten zu (210, 16)*/
            printf("vs.");
            printf("\033[19;220H"); /*Aendern der Koordinaten zu (220, 16)*/
            printf("%s", (*final_verlierer[0]).name);
    } else {
            printf("\033[19;185H"); /*Aendern der Koordinaten zu (185, 16)*/
            printf("%s", (*final_verlierer[0]).name);
            printf("\033[19;210H"); /*Aendern der Koordinaten zu (210, 16)*/
            printf("vs.");
            printf("\033[19;220H"); /*Aendern der Koordinaten zu (220, 16)*/
            printf("%s", (*final_gewinner[0]).name);
    }
            wette_eingabe(&wett_geld, gewinner_zahl[counter]);
            counter++;

            printf("\033[40;5H");   /*Gehen zu Position (5, 40)*/
            printf("Champions League Sieger: %s", (*final_gewinner[0]).name); /*Ausgabe des Gewinners,
                Pokale basiern auf ANSII-Art*/

            delete_anleitung_wette();
            print_anleitung(4);

            printf("\033[100;H");   /*Gehen zur untersten Zeile des Terminals*/


    return VALID_INPUT;
}

/*überprüft ob die wette gleich dem Ergebniss des Spiels ist */
int wette_eingabe(int *wett_geld, int gewinner_zahl) {

        int check_error;
        int number;

        char input;
        char c;

        check_error = INVALID_INPUT;
        input = 0;

        printf("\033[100;0H");  /*Gehen zur letzten Zeile*/

        do {
                printf("\033[1A");      /*Gehen einer Zeile nach oben*/

                input = getchar();
                input = tolower(input);

                if (input == EOF) {
                        return BUFFER_ERROR;
                }

                if (input == '\n') {    /*Rueckgaengig-machen vom Zeilensprung*/
                        continue;
                }


                if ((input != '1' && input != '2') || (c = getchar()) != '\n') {
                        if (c == EOF || !flush_buff()) {
                                return BUFFER_ERROR;
                        }
                        printf("\033[1A");      /*Gehe eine Zeile nach oben*/
                        printf("\033[K\r");     /*Loesche diese Zeile*/
                        printf("\033[1B");      /*Gehe eine Zeile nach unten*/
                        continue;
                } else {
                        check_error = VALID_INPUT;
                }


        } while (check_error == INVALID_INPUT);

        number = input - '1';

        if (number == gewinner_zahl) {
                (*wett_geld)++;
                printf("\033[45;5H"); /*Gehe an Position (5, 45)*/
                printf("\033[K\r");     /*Loesche die komplette Zeile*/
                setColour_FG(2);        /*Setze Farbe auf gruen*/
                printf("\033[45;5H");   /*Gehe an Position (5, 45)*/
                printf("RICHTIG");
                setColour_FG(1);        /*Setze Farbe auf weiss*/
                printf("\033[44;5H");   /*Gehe an Position (5, 44)*/
                printf("\033[K\r");     /*Loesche die komplette Zeile*/
                printf("\033[44;5H");   /*Gehe an Position (5, 44)*/
                printf("Letzte Wette: ");
                setColour_FG(2);        /*Setze Farbe auf gruen*/
                printf("+1");
                setColour_FG(1);        /*Setze Farbe auf weiss*/
        } else {
                (*wett_geld)--;
                printf("\033[45;5H");   /*Gehe an Position (5, 45)*/
                printf("\033[K\r");     /*Loesche die komplette Zeile*/
                printf("\033[45;5H");   /*Gehe an Position (5, 45)*/
                setColour_FG(3);        /*Setze Farbe auf rot*/
                printf("FALSCH");
                setColour_FG(1);        /*Setze Farbe auf weiss*/
                printf("\033[44;5H");   /*Gehe an Position (5, 44)*/
                printf("\033[K\r");     /*Loesche die komplette Zeile*/
                printf("\033[44;5H");   /*Gehe an Position (5, 44)*/
                printf("Letzte Wette: ");
                setColour_FG(3);        /*Setze Farbe auf rot*/
                printf("-1");
                setColour_FG(1);        /*Setze Farbe auf weiss*/
        }

        printf("\033[43;5H");   /*Gehe an Position (5, 43)*/
        printf("\033[K\r");     /*Loesche die komplette Zeile*/
        printf("\033[43;5H");   /*Gehe an Position (5, 43)*/
        printf("Budget: ");
        if (*wett_geld > 5) {
                setColour_FG(2);        /*Setze Farbe auf gruen*/
                printf("%i", *wett_geld);
                setColour_FG(1);        /*Setze Farbe auf weiss*/
        } else if (*wett_geld < 5) {
                setColour_FG(3);        /*Setze Farbe auf rot*/
                printf("%i", *wett_geld);
                setColour_FG(1);        /*Setze Farbe auf weiss*/
        } else {
                printf("%i", *wett_geld);
        }

        return check_error;
}

/**/
int restliche_auslosung_punkte_wetten(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, struct mannschaften **before_gewinner, int *gewinner_zahl)
{
          int coinflip = 0;
          int i;

          /*Im Viertelfinale und weiter spielen die erste Mannschaft mit der Darauffolgenden.*/
          int team_eins = 0;
          int team_zwei = 1;

          srand(time (NULL));

          for(i = 0; i < finale; i++) {
            /*Ermittlung der Random zahlen*/
            coinflip = rand();
            coinflip %= 2;
            /*Speichert die Ergebnisse des Coinflips*/
            gewinner_zahl[i] = coinflip;
            /*Ermittelt den Sieger. Wenn der coinflip gleich 0 ist, dan Gewinnt die erste Mannschaft
            und wenn sie 1 ist gewinnt die zweite Mannschaft.
            Speichert die Gewinner und Verlierer*/
            if(coinflip == 0) {
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
int achtel_gruppen_auslosung_wetten(int finale, struct mannschaften **temp_gewinner, struct mannschaften **temp_verlierer, int *gewinner_zahl)
{
          /*Speichert die Nummer der Gengerteams, welche schon gespielt haben*/
          int *gegner_gruppe;

          /*Ermittelt eine Random für die Gegnerische zahl die in der Methode finde_gegner()
          angepasst um zwischen eingeschlossen 1 und 7 zu sein*/
          int gegner_gruppe_nummer;
          /*wir verwendet um den Gewinner/ Vertlierer zu ermitteln*/
          int coinflip;

          int i;

          srand(time (NULL));

          gegner_gruppe = malloc(finale * sizeof(int));

          for(i = 0; i < finale; i++) {
                /*Ermittlung der Random zahlen*/
                    coinflip = rand();
                    coinflip %= 2;
                    /*Speichert die Ergebnisse des Coinflips*/
                    gewinner_zahl[i] = coinflip;
                    gegner_gruppe_nummer = rand();
                    /*Ermittelt eine Randomzahl für die Gegnergruppe, die in der Methode finde_gegner()
                    angepasst wird. Sie muss zwischen 0 und 7 sein, da diese in dem Gruppenarray benützt werden*/
                    gegner_gruppe_nummer = finde_gegner(i, gegner_gruppe, gegner_gruppe_nummer, finale);
                    /*Speichert die Gegnernummer damit sie nicht nochmal ausgewählt wird*/
                    gegner_gruppe[i] = gegner_gruppe_nummer;
                    /*Ermittelt den Sieger. Wenn der coinflip gleich 0 ist, dan Gewinnt die erste Mannschaft
                    und wenn sie 1 ist gewinnt die zweite Mannschaft.
                    Speichert die Gewinner und Verlierer*/
                    if(coinflip == 0) {
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

void print_anleitung_wette()        /*Ausgabe, welche Zeichen erlaubt sind*/
{
        printf("\033[47;5H"); /*Gehe zu Position (5, 47)*/
        printf("Druecke '1' oder '2' abhaengig auf welches Team du wetten willst");
        printf("\033[100;0H"); /*Gehe zur letzten Zeile*/
}

void delete_anleitung_wette()        /*Ausgabe, welche Zeichen erlaubt sind*/
{
        printf("\033[47;5H"); /*Gehe zu Position (5, 47)*/
        printf("\033[K\r");
        printf("\033[100;0H"); /*Gehe zur letzten Zeile*/
}
