#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

char **strsplit( const char *str, char delimiter )
{
    char *i;
    char *j;
    unsigned int k;

    char *newStr = strdup( str );

    // compter le nombre de delimiteurs
    for ( i = newStr, k = 0; *i; i++ )
    {
        if ( delimiter == *i )
            k++;
    }

    // k delimiteurs cad N + 1 mots, plus 
    // un NULL terminator
    char **result = calloc( 2 + k, sizeof( *result ) );

    // premier result est le debut du string original
    result[ 0 ] = newStr;

    // on split the string en inserant des '\0' 
    // a la place des delimiteurs, et on remplit le tableau des pointeurs au meme temps

    i = newStr;
    k = 1;
    
    for( ; ; )
    {
        // on cherche le delimiteur suivant
        j = strchr( i,delimiter);
        if ( NULL == j ) 
            break; // si on a plus de delimiteurs on sort de la boucle

        // sinon on remplace ce delimiteur par '\0'
        *j = '\0';

        // alors, i pointe sur le mot suivant
        i = j + 1;

        // on remplit le tableau des pointeurs par l'adresse du mot suivant
        result[ k ] = i;

        k++;
    }

    return( result );
}

int main()
{
    char **result;
    char string[100]="tester la fonction strsplit";
    int i=0;
    result = strsplit(string, ' ');
    while(result[i] != NULL){
        printf("mot[%d]: ",i);
        puts(result[i]);
        i++;
    }

    return( 0 );
}