#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *caesar_decode(char key, const char *text)
{
        unsigned int i;
        char *res = malloc(sizeof(char) * (strlen(text) + 1));
        if (res == NULL) {
                printf("Speicherallokierung fehlgeschlagen.\n");
                return NULL;
        }
        for (i = 0; i < strlen(text); i++) {
                int temp = text[i] - (key - 'A');
                if (temp < 65) {
                        temp += 26;
                }
                res[i] = temp;
        }
        res[i] = '\0';
        return res;
}

char *caesar_encode(char key, const char *text)
{
        int i;
        char *res = malloc(sizeof(char) * (strlen(text) + 1));
        if (res == NULL) {
                printf("Speicherallokierung fehlgeschlagen.\n");
                return NULL;
        }
        for (i = 0; i < strlen(text); i++) {
                int temp = text[i] + (key - 'A');
                if (temp > 90) {
                        temp -= 26;
                }
                res[i] = temp;
        }
        res[i] = '\0';
        return res;
}

int main(void)
{
    char decoded[] = "DASISTEINTEST";
    char encoded[] = "URJZJKVZEKVJK";
    printf("%s wird zu %s encodiert\n", decoded, caesar_encode('R', decoded));
    printf("%s wird zu %s decodiert\n", encoded, caesar_decode('R', encoded));
    return 0;
}