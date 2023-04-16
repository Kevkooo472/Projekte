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