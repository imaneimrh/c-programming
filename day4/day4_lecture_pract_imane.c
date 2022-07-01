#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//*******************************************LECTURE PRACTICE*******************************************

//Q1, Q2, Q3, Q4, Q5, Q6 veuillez les voir dans main.

//QU 7
//rewrite the function gets using getchar function.

char *al_gets(char *str){
    int ch, i = 0;  
    char *ptr = str; 
    do  
    {  
        ch = getchar(); 
        ptr[i] = ch;
        i++; 
    } while (ch != '\n');  
    ptr[i] = '\0';
    return str; 
} 

//QU 8
//rewrite the function puts using putchar function.
char *al_puts(char *str){
    int i = 0;  
    do  
    {  
        putchar(str[i]);
        i++; 
    } while (str[i] != '\0');  
    return str; 
} 


int main(){
    
    //1 
    printf("QU 1\n");
    char string1[]="hello";
    printf("%s\n",string1);
    
    //2
    printf("QU 2\n");
    char string2[100];
    strcpy(string2,"world");
    printf("%s\n",string2);
    
    //3 concatenate 
    printf("QU 3\n");
    char string3[100];
    int i=0;
    while(string1[i] != '\0'){
        string3[i] = string1[i];
        i++;
    }
    string3[i] = ' ';
    i++;
    int j = 0;
    while(string2[j] != '\0'){
        string3[i] = string2[j];
        i++;
        j++;
    }
    string3[i]='\0';
    printf("string 1: %s\n",string1);
    printf("string 2: %s\n",string2);
    printf("string apres concatenation sans utiliser string.h: %s\n",string3);
    
    //4
    printf("QU 4\n");
    char string4[100]="";
    printf("string 1: %s\n",string1);
    printf("string 2: %s\n",string2);
    strcat(string4, string1);
    strcat(string4, " ");
    strcat(string4, string2);
    printf("string apres concatenation avec strcat: %s\n",string4);
  
    //5
    printf("QU 5\n");
    char string5[strlen(string1) + strlen(string2) + 1];
    printf("string 1: %s\n",string1);
    printf("string 2: %s\n",string2);
    strcpy(string5, string1);
    strcpy(string5+strlen(string1), " ");
    strcpy(string5+strlen(string1)+1, string2);
    printf("string apres concatenation avec strcpy: %s\n",string5);
    
    //6
    printf("QU 6\n");
    char s1[ ] = "Hello";
    char s2[ ] = "hello";
    char s3[ ] = {'h', 'e', 'l' , 'l', 'o', '\0'};

    printf("%d\n",strcmp(s1, s2)); //doit rendre un entier negatif car H(dans s1 ; premier argument) < h(dans s2 ; deuxieme argument) sur la table ascii, le reste des caracteres sont egaux.
    printf("%d\n",strcmp(s2, s1)); //doit rendre un entier negatif car h(dans s2 ; premier argument) > H(dans s1 ; deuxieme argument) sur la table ascii, le reste des caracteres sont egaux.
    printf("%d\n",strcmp(s1, s3)); //s3 est le meme que s1, donc le meme traitement.
    printf("%d\n",strcmp(s2, s3)); //s3 et s1 sont egaux, alors le resultat est 0.
    
    //7
    //veuillez voir la fonction al_gets en haut de la page.
    printf("QU 7\n");
    printf ("saisissez une chaine de caractere: (cliquez sur entrer pour arreter).\n");  
    char string7[150];
    al_gets(string7);

    //8
    //veuillez voir la fonction al_puts en haut de la page.
    printf("la chaine de caractere saisie: \n");
    al_puts(string7);   

    //9

    //write a program that reads a string from standard input and compare it with a word of your choice 
    //if they match write "success" to the standard output else write "failed" to the standard error. 
    //(using fgets and fputs).

    char w_choice[80];
    char string9[80];
    int r;
    printf("entrer string9: ");
    fgets(string9, 80, stdin);
    printf("entrer w_choice: ");
    fgets(w_choice, 80, stdin);
    r = strcmp(w_choice, string9);
    if (r == 0) 
        fputs("success\n", stdout);
    else 
        fputs("failed\n", stdout);

    return 0;
}
