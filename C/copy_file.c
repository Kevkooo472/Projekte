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
        printf("Oeffnen der Textdatei '%s' fehlgeschlagen.\n", filename);
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
    if (fclose(quelle) != 0) {
        printf("Schliessen der Quelldatei '%s' fehlgeschlagen.\n", filename);
        return 0;
    }
    if (fclose(ziel) != 0) {
        printf("Schliessen der Kopie fehlgeschlagen.\n");
        return 0;
    }
    if (read == EOF && feof(quelle) == 0) {
        printf("EOF\n");
        return -1;
    }
    return 1;
}