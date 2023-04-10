#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include "bittypes.h"

int h_spiegeln(const bitmapRGB *original, bitmapRGB *ergebnis)
{
        long_t i, j;
        long_t w = original->width;
        long_t h = original->height;
        ergebnis->pixel = (pixelRGB *) malloc(w * h * sizeof(pixelRGB));
        if (ergebnis->pixel == NULL)
                return -1;
        ergebnis->width = w;
        ergebnis->height = h;
        for (i = 0; i < h; ++i)
                for (j = 0; j < w; ++j) {
                        ergebnis->pixel[i * w + j] = original->pixel[(w * h - (i * w)) - j];
                }
        return 0;
}

int main(int argc, char *argv[])
{
        bitmapRGB quelle;
        bitmapRGB ziel;
        int res;
        if (argc != 3) {
                printf("Nicht genug Kommandozeilenparameter.\n");
                printf("<Programm> <Quelle> <Ziel> \n");
                return 1;
        }
        printf("Test 1\n");
        res = loadBitmapRGB(argv[1], &quelle);
        if (res != BMP_OK) {
                printf("Fehler (%i) Lesen %s.\n", res, argv[1]);
                return 1;
        }
        printf("Test 2\n");

        res = h_spiegeln(&quelle, &ziel);
        if (res != BMP_OK) {
                free(quelle.pixel);
                printf("Spiegeln konnte nicht ausgeführt werden.\n");
                return 1;
        }

        res = saveBitmapRGB(argv[2], &ziel);
        if (res != BMP_OK) {
                free(quelle.pixel);
                free(ziel.pixel);
                printf("Fehler (%i) Schreiben %s\n", res, argv[2]);
                return 1;
        }
        printf("Test 3\n");

        free(quelle.pixel);
        free(ziel.pixel);
        return 0;
}