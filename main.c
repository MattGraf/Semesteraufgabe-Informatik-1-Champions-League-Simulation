#include "./Gruppenphase/gruppen.h"
#include "./Titelseite/titelseite.h"
#include "./Farben/farben.h"
#include "./Auslosung/auslosung.h"

int main(void)
{
        int check_error;

        check_error = read_groups();

        if (check_error == BUFFER_ERROR) {
                printf("Pufferfehler\n");
                return BUFFER_ERROR;
        } else if (check_error == INVALID_INPUT) {
                printf("Falsche Eingabe\n");
                return INVALID_INPUT;
        }

        order_groups();
        generate_auslosung_random();
        generate_auslosung_punkte();

        generate_auslosung_punkte();

        check_error = print_page();

        if (check_error == BUFFER_ERROR) {
                printf("Pufferfehler\n");
                return BUFFER_ERROR;
        } else if (check_error == INVALID_INPUT) {
                printf("Falsche Eingabe\n");
                return INVALID_INPUT;
        }

        return VALID_INPUT;
}
