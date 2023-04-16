#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 16
#define VALID_INPUT 0
#define INVALID_INPUT -3
#define BUFFER_ERROR -2

#define VAL_LENGTH(i, DIM) (i < DIM)


int flush_buffer(void) 
{
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
                {}
        return c != EOF;
}

int read_binary(int binary[])
{
        int i = 0;
        char c = getchar();
        while (VAL_LENGTH(i, DIM)) {
                /*ASCII v. 0 -> 48 u. 1 -> 49*/
                switch (c) {
                        case '0':
                        case '1':
                                binary[i] = c - 48;
                                i++;
                                break;        
                        case EOF:
                                return BUFFER_ERROR;
                        case '\n':
                                break;
                        default:
                                return INVALID_INPUT;
                }
                c = getchar();
        }
        if (c != '\n') {
                if (c == EOF || !flush_buffer()) {
                        return BUFFER_ERROR;
                }
                return INVALID_INPUT;
        }
        if (VAL_LENGTH(i, DIM)) {
                return INVALID_INPUT;
        }
        return VALID_INPUT;
}

double decode_fk(int binary[], int n, int k)
{
        /* n -> Länge, k -> Nachkommstellen*/
        int i;
        double a = 0;
        for (i = 0; i < n; i++) {
                a += (binary[i] * pow(2, n - k - 1 - i));
        }
        return a;
}

int read_and_decode_fk()
{
        /*k = Nachkommstellen*/
        int k, status, binary[DIM];
        char c;
        printf("Die FK-Codierung hat %i Bit.\n", DIM);
        printf("Mit wie viel Nachkommstellen soll die Codierung erfolgen?\n");
        status = scanf("%i", &k);
        if (status != 1 || (c = getchar() != '\n')) {
                if (c == EOF || !flush_buffer()) {
                        return BUFFER_ERROR;
                }
                return INVALID_INPUT;
        }
        printf("Binaercode eingeben:  ");
        status = read_binary(binary);
        if (status) {
                /*gibt Fehlerwert bei Fehler zurück*/
                return status;
        }
        printf("Decodierung: %f\n", decode_fk(binary, DIM, k));
        return VALID_INPUT;
}

int main(void) 
{
        int status;
        status = read_and_decode_fk();
        if (status) {
                printf("Fehlercode: %i", status);
        }
        return 0;
}