#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

main(void)
{
    FILE* archivo = fopen("C:/Users/DanielaPQ/Documents/daniela.html", "rb");
    size_t tamano;
    char* contenido;
    int space = 0;
    int i = 0;
    char *c;
    int valorInt;

    //Move el puntero al fin
   fseek(archivo, 0, SEEK_END);

    // Cuantas caracteres esta del principio
    tamano = ftell(archivo);

    // Move el puntero al principio, asi que puede leer el archvio
    // del principio
    fseek(archivo, 0, SEEK_SET);

    // Ahora, contenido siempre sera el tamano correcto
    contenido = malloc(tamano * sizeof(char));

    fread(contenido, sizeof(char), tamano, archivo);

c = contenido;
while (*c != '\0') {
    if (*c == ' ') *c = '_';


    if (*c == '<'){
        do {*c = ' ';
        c++;
        }while (*c != '>');

    }

    if (*c == '>') *c = ' ';
     c++;
}

printf( "c: \"%s\" \n", contenido);

    // Aqui, haz las cosas que quieres hacer con contenido ...

    // Por ejemplo:
    //printf("Contenido:\n%s\n", contenido);

    // Esta espacio ya no necesita existar
    free(contenido);



}
