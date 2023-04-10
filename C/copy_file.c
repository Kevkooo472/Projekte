#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int copy_file(FILE *quelle, char *filename);

int main(void)
{

}

int copy_file(FILE *quelle, char *filename)
{
    FILE *ziel;
    int read, write, i = 0;
    /* Ueberpruefen ob Dateizugriff moeglich ist */
    quelle = fopen(filename, "r");
    if (quelle == NULL) {
        printf("Oeffnen der Textdatei '%s' nicht moeglich.\n", filename);
        return 0;
    }
    ziel = fopen("kopie.txt", "w");
    if (ziel == NULL) {
        printf("Oeffnen der Kopie fehlgeschlagen.\n");
        return 0;
    }
    /* Quell-Textdatei einlesen */
    read = fgetc(quelle);
    while (read != EOF) {
        /* Schreiben in Zieldatei */
        write = fputc(read, ziel);
        if (write != read || write == EOF)
            break;
        ++i;
        read = fgetc(quelle);
    }
    

}