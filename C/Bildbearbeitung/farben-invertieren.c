#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"
#include "bittypes.h"


int invfarbe(const bitmapRGB *original, bitmapRGB *ergebnis)
{
        long_t i, j, w = original->width, h = original->height;
        pixelRGB *o = original->pixel;
        pixelRGB *e = (pixelRGB *) malloc(w * h * sizeof(pixelRGB));
        if (e == NULL)
                return -1;
        ergebnis->pixel = e;
        ergebnis->width = w;
        ergebnis->height = h;
        for (i = 0; i < h; ++i) {
                for (j = 0; j < w; ++j) {
                        e->red = 255 - o->red;
                        e->blue = 255 - o->blue;
                        e->green = 255 - o->green;
                        ++e;
                        ++o;
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

        if ((ret_val = invfarbe(&quelle, &ziel)) != BMP_OK) {
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