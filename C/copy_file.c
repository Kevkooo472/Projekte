#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int copy_file(FILE *quelle, char *filename);

int main(void)
{

}

int copy_file(FILE *quelle, char *filename)
{
    FILE *copy;
    int read, write, i = 0;
    /* Ueberpruefen ob Dateizugriff moeglich ist */
    quelle = fopen(filename, "r");
    if (quelle == NULL) {
        printf("Oeffnen der Textdatei '%s' nicht moeglich.\n", filename);
        return 0;
    }
    copy = fopen("kopie.txt", "w");
    if (copy == NULL) {
        printf("Oeffnen der Kopie fehlgeschlagen.\n");
        return 0;
    }
    /* Quell-Textdatei einlesen */
    read = fgetc(quelle);

}