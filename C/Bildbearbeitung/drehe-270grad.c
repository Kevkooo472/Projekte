#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"
#include "bittypes.h"

int drehe90(const bitmapRGB *original, bitmapRGB *drehung)
{
        long_t w = original->width, h = original->height, i, j;
        pixelRGB *o = original->pixel, *d;

        d = (pixelRGB*) malloc(w * h * sizeof(pixelRGB));
        if (d == NULL)
                return -1;
        
        drehung->pixel = d;
        drehung->width = h;
        drehung->height = w;

        for (i = 0; i < w; ++i) {
                for (j = 0; j < h; ++j) {
                        d[i * h + j] = o[(j * w) + (w - 1 - i)];
                }
        }

        return 0;
}

int main(int argc, char *argv[])
{
        bitmapRGB quelle, ziel;
        int ret_val;

        if (argc != 3) {
                printf("Benutzung %s <Quelle> <Ziel>\n", argv[0]);
                printf(" <Quelle> Name Original-Bild\n");
                printf(" <Ziel> Name konvertiertes Bild\n");
                return EXIT_FAILURE;
        }

        if ((ret_val = loadBitmapRGB(argv[1], &quelle)) != BMP_OK) {
                printf("Fehler %i Lesen '%s'\n", ret_val, argv[1]);
                return EXIT_FAILURE;
        }

        if ((ret_val = drehe90(&quelle, &ziel)) != BMP_OK) {
                free(quelle.pixel);
                printf("Fehler (%i) Drehen '%s'\n", ret_val, argv[1]);
                return EXIT_FAILURE;
        }

        if ((ret_val = saveBitmapRGB(argv[2], &ziel)) != BMP_OK) {
                free(quelle.pixel);
                free(ziel.pixel);
                printf("Fehler (%i) Schreiben '%s'\n", ret_val, argv[2]);
                return EXIT_FAILURE;
        }

        free(quelle.pixel);
        free(ziel.pixel);
        return EXIT_SUCCESS;
}