#include "titelseite.h"

int print_page()        /*Ausgabe der Titelseite und starten des Programms*/
{
        int i;

        setColour_BG(1);        /*Setze Hintergrundfarbe auf blau*/

        printf("\033[8;0;0t");  /*Setze gesamten Hintergrund auf blau*/
        setColour_FG(1);      /*Setze Schriftfarbe auf weiss*/

        printf("\033[2J");      /*Leere die Terminalseite*/
        printf("\033[H");       /*Gehe zu Position (0, 0)*/

        for (i = 0; i < 15; i++) {
                printf("\n");
        }

        /*Ausgabe vom Programmtitel mithilfe Box-drawing characters*/
        printf("\t\t\t_________ .__                          .__                      \n");
        printf("\t\t\t\\_   ___ \\|  |__ _____    _____ ______ |__| ____   ____   ______\n");
        printf("\t\t\t/    \\  \\/|  |  \\\\__  \\  /     \\\\____ \\|  |/  _ \\ /    \\ /  ___/\n");
        printf("\t\t\t\\     \\___|   Y  \\/ __ \\|  Y Y  \\  |_> >  (  <_> )   |  \\\\___ \\ \n");
        printf("\t\t\t \\______  /___|  (____  /__|_|  /   __/|__|\\____/|___|  /____  > \n");
        printf("\t\t\t        \\/     \\/     \\/      \\/|__|                  \\/     \\/         \n");
        printf("\t\t\t.____                                                           \n");
        printf("\t\t\t|    |    ____ _____     ____  __ __   ____                     \n");
        printf("\t\t\t|    |  _/ __ \\\\__  \\   / ___\\|  |  \\_/ __ \\                    \n");
        printf("\t\t\t|    |__\\  ___/ / __ \\_/ /_/  >  |  /\\  ___/                    \n");
        printf("\t\t\t|_______ \\___  >____  /\\___  /|____/  \\___  >                   \n");
        printf("\t\t\t        \\/   \\/     \\//_____/             \\/                            \n");


        printf("\033[45;5H");   /*Gehe zu Position (5, 45)*/
        printf("Zum Auswaehlen des Modus bitte 'w'/'W' zum Hochgehen und\n");

        printf("\033[46;5H");   /*Gehe zu Position (5, 46)*/
        printf("und 's'/'S' zum Runtergehen druecken und durch Enter bestaetigen\n");

        printf("\033[47;5H");   /*Gehe zu Position (5, 47)*/
        printf("Wenn Sie sich entschieden haben, koennen Sie durch 'b'/'B' den Modus auswaehlen");

        /*Ausgabe des Menues*/
        printf("\033[50;5H");   /*Gehe zu Position (5, 50)*/
        printf("[x] Gruppenanzeige\n");

        printf("\033[51;5H");   /*Gehe zu Position (5, 51)*/
        printf("[ ] Simulation - Zufall\n");

        printf("\033[52;5H");   /*Gehe zu Position (5, 52)*/
        printf("[ ] Simulation - Ergebnisse\n");

        printf("\033[53;5H");   /*Gehe zu Position (5, 53)*/
        printf("[ ] Wettsimulation\n");

        printf("\033[54;5H");   /*Gehe zu Position (5, 54)*/
        printf("[ ] Beenden\n");

        printf("\033[100;0H");  /*Gehe zur letzten Zeile*/

        return choose_mode();
}

int choose_mode()       /*Menue-Auswahl*/
{
        int mode;
        int check_error, choose;
        char input, c;

        mode = 1;
        choose = 1;
        check_error = INVALID_INPUT;

        while (choose) {        /*Solange die Eingabe ungueltig ist tue*/
                do {
                        printf("\033[1A"); /*Gehe eine Zeile nach oben*/

                        input = getchar();
                        input = tolower(input);

                        if (input == EOF) {
                                return BUFFER_ERROR;
                        }

                        if (input == '\n') {    /*Springen zum while-Anfang -> '\n' wird rueckgaengig gemacht*/
                                continue;
                        }


                        if ((input != 'w' && input != 's' && input != 'b') || (c = getchar()) != '\n') {
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

                printf("\033[1A");      /*Gehe eine Zeile nach oben*/
                printf("\033[K\r");     /*Loesche diese Zeile*/
                printf("\033[1B");      /*Gehe eine Zeile nach unten*/

                switch (input) { /*Ueberpruefe, welche gueltige Eingabe gewaehlt wurde*/
                        case 'w':
                                mode--;

                                if (mode < MIN_MODE) {
                                        mode = MIN_MODE;
                                }

                                break;
                        case 's':
                                mode++;

                                if (mode > MAX_MODE) {
                                        mode = MAX_MODE;
                                }

                                break;

                        case 'b':
                                choose = 0;
                                break;
                }

                switch (mode) { /*Veraendere entsprechend das Menue*/
                        case 1:
                                printf("\033[50;5H");   /*Gehe zu Position (5, 50)*/
                                printf("[x");           /*Mode = 1: Gruppenanzeige*/
                                printf("\033[51;5H");   /*Gehe zu Position (5, 51)*/
                                printf("[ ");
                                printf("\033[52;5H");   /*Gehe zu Position (5, 52)*/
                                printf("[ ");
                                printf("\033[53;5H");   /*Gehe zu Position (5, 53)*/
                                printf("[ ");
                                printf("\033[54;5H");   /*Gehe zu Position (5, 54)*/
                                printf("[ ");
                                printf("\033[100;H");   /*Gehe zur letzten Zeile*/
                                break;
                        case 2:
                                printf("\033[50;5H");
                                printf("[ ");
                                printf("\033[51;5H");
                                printf("[x");           /*Mode = 2: Simulation - Zufall*/
                                printf("\033[52;5H");
                                printf("[ ");
                                printf("\033[53;5H");
                                printf("[ ");
                                printf("\033[54;5H");
                                printf("[ ");
                                printf("\033[100;H");
                                break;
                        case 3:
                                printf("\033[50;5H");
                                printf("[ ");
                                printf("\033[51;5H");
                                printf("[ ");
                                printf("\033[52;5H");
                                printf("[x");           /*Mode = 3: Simulation - Ergebnisse*/
                                printf("\033[53;5H");
                                printf("[ ");
                                printf("\033[54;5H");
                                printf("[ ");
                                printf("\033[100;H");
                                break;
                        case 4:
                                printf("\033[50;5H");
                                printf("[ ");
                                printf("\033[51;5H");
                                printf("[ ");
                                printf("\033[52;5H");
                                printf("[ ");
                                printf("\033[53;5H");
                                printf("[x");           /*Mode = 4: Wettsimulation*/
                                printf("\033[54;5H");
                                printf("[ ");
                                printf("\033[100;H");
                                break;
                        case 5:
                                printf("\033[50;5H");
                                printf("[ ");
                                printf("\033[51;5H");
                                printf("[ ");
                                printf("\033[52;5H");
                                printf("[ ");
                                printf("\033[53;5H");
                                printf("[ ");
                                printf("\033[54;5H");
                                printf("[x");           /*Mode = 5: Beenden des Programms*/
                                printf("\033[100;H");
                                break;

                }

                printf("\033[100;0H");  /*Gehen zur letzten Zeile*/

        }

        check_error = switch_mode(mode);

        return check_error;
}

int switch_mode(int mode)       /*Moduswechsel*/
{
        switch(mode) {
                case 1:
                        print_groups();
                        print_anleitung(1);
                        back();
                        break;
                case 2:
                        print_auslosung_random();
                        print_anleitung(2);
                        back_and_restart(mode);
                        break;
                case 3:
                        print_auslosung_punkte();
                        print_anleitung(2);
                        back_and_restart(mode);
                        break;
                case 4:
                        wetten();
                        back_and_restart(mode);
        }

        return VALID_INPUT;
}

int back()      /*Erwarten der Eingabe zum Wechsel zum Hauptmenue*/
{
        int check_error;

        char input;
        char c;

        check_error = INVALID_INPUT;

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

                if ((input != 'z') || (c = getchar()) != '\n') {
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

        print_page();   /*Wechsel zum Hauptmenue*/

        return VALID_INPUT;
}

int back_and_restart(int mode)  /*Erwarten der Eingabe zum Wechsel zum Hauptmenue oder Starten einer neuen Simulation
        abhaengig von Simulation, welche in 'mode' mitgegeben wird*/
{
        int check_error;

        char input;
        char c;

        check_error = INVALID_INPUT;

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


                if ((input != 'z' && input != 'n') || (c = getchar()) != '\n') {
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

        if (input == 'z') {
                print_page(); /*Bei Eingabe 'z', wechsel zum Hauptmenue*/
        } else if (input == 'n'){
                switch(mode) { /*Ueberpruefung, welche Simulation erneut durchgefuehrt werden soll*/
                        case 2:
                                generate_auslosung_random();
                                print_auslosung_random();
                                print_anleitung(2);
                                check_error = back_and_restart(mode);
                                break;
                        case 3:
                                generate_auslosung_punkte();
                                print_auslosung_punkte();
                                print_anleitung(2);
                                check_error = back_and_restart(mode);
                                break;
                        case 4:
                                wetten();
                                check_error = back_and_restart(mode);
                                break;
                        default:
                                return INVALID_INPUT;
                }
        }

        return check_error;
}

void print_anleitung(int method)        /*Ausgabe, welche Zeichen erlaubt sind*/
{
        printf("\033[60;5H"); /*Gehe zu Position (5, 60)*/
        printf("Druecke 'z'/'Z' zum Zurueckgehen.\n");
        if (method > 1) {
                printf("\033[4C"); /*Gehe vier Spalten nach rechts*/
                printf("Druecke 'n'/'N' zum Erstellen einer neuen Simulation");
        }
        printf("\033[100;0H"); /*Gehe zur letzten Zeile*/
}

int flush_buff()
{
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return c != EOF;
}
