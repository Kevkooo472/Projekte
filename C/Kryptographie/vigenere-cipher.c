#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *vigenere_encode(const char *key, const char *text)
{
        int i;
        char *res = malloc(sizeof(char) * (strlen(text) + 1));
        if (res == NULL) {
                printf("Speicherallokierung fehlgeschlagen\n");
                return NULL;
        }
        for (i = 0; i < strlen(text); i++) {
                int temp = text[i] + (key[i % strlen(key)] - 'A');
                if (temp > 'Z') {
                        temp -= 26;
                }
                res[i] = temp;
        }
        res[i] = '\0';
        return res;
}

char *vigenere_decode(const char *key, const char *text)
{
        int i;
        char *res = malloc(sizeof(char) * (strlen(text) + 1));
        if (res == NULL) {
                printf("Speicherallokierung fehlgeschlagen\n");
                return NULL;
        }
        for (i = 0; i < strlen(text); i++) {
                int temp = text[i] - (key[i % strlen(key)] - 'A');
                if (temp < 'A') {
                        temp += 26;
                }
                res[i] = temp;
        }
        res[i] = '\0';
        return res;
}


    int main(void)
{
    char decoded[] = "DASISTEINTEST";
    char encoded[] = "DKWGSDIGNDIQT";
    char key[] = "AKEY";
    printf("%s wird zu %s encodiert\n", decoded, vigenere_encode(key, decoded));
    printf("%s wird zu %s decodiert\n", encoded, vigenere_decode(key, encoded));
    return 0;
}
