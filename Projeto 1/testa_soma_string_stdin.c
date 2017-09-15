#include <stdio.h>
#include <stdlib.h>
#include "string_soma.h"


int main(int argc, char const *argv[])
{

    char string[50];
    int soma;

    gets(string);

    soma = soma_string(string);

    printf("%d\n", soma);


    return 0;
}