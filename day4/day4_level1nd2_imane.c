#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//************************************************************LEVEL 01****************************************************************
unsigned long al_strlen(char* string){
    unsigned long k=0;
    while(string[k] != '\0'){
        k++;
    }
    return k;
}

char* al_strcpy(char* destination, char* source){
    int j=0;
    unsigned n = strlen(source);
    unsigned m = strlen(destination);
    while(j < n){
        destination[j] = source[j];
        j++;
    }
    destination[j]='\0';
    return destination;
}

char* al_strcat(char* destination, const char* source)
{
    int i, j;
    for (i = 0; destination[i] != '\0'; i++); //pour passer a la fin de la string de destination
    for (j = 0; source[j] != '\0'; j++) {
        destination[i + j] = source[j];
    }
    destination[i + j] = '\0';
    return destination;
}


void str_reverse(char * string){
    char rev[1000];
    int i=0, j=0;
    while(string[i] != '\0'){
        i++;
    }
    int c = i-1;
    for(j=0; j < i; j++){
        rev[j] = string[c];
        c--;
    }
    rev[j] = '\0';
    strcpy(string, rev);
    return;
}

//forbidden functions: strlen, strcpy, strcat, malloc
void reverse_string(char str[], int i, int j){
    char temp;
    while(i<j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

void str_wreverse (char* str){
    //char str
    int i, j;
    j=0;
    i=0;
    while(str[j])
    {
        for(j=i;str[j]&&str[j]!=' ';j++);
        reverse_string(str, i, j-1);
        i=j+1;
    }
    return;
}

//*********************************************************LEVEL 02*********************************************************************
size_t	al_strlcpy(char *destination, const char *source, size_t destsize){
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (!destination)
		return (destsize);
	k = al_strlen((char *)source);
	if (destsize > 0)
	{
		while (source[i] != '\0' && i < (destsize - 1))
		{
			destination[i] = ((char*)source)[i];
			i++;
		}
		destination[i] = 0;
	}
	return (k);
}


size_t	al_strlcat(char *destination, const char *source, size_t destsize){
	size_t	k;
	size_t	i;
	k = 0;
	i = 0;
	while (destination[i] != '\0' && i < destsize)
		i++;
	if (destination[i] == '\0'){
		while (source[k] != '\0' && destsize - 1 > i + k){
			destination[i + k] = source[k];
			k++;
		}
		destination[i + k] = '\0';
	}
	while (source[k] != '\0')
	{
		k++;
	}
	return (k + i);
}

















int main(){

    printf("----------application de la fonction ~al_strlen~:\n");
    char mot[50];
    printf("veuillez saisir un mot pour calculer sa longueur: ");
    gets(mot);
    printf("la longueur donnee par ~al_strlen~ est: %lu\n\n", al_strlen(mot));
    printf("la longueur donnee par strlen est: %lu\n\n", strlen(mot));
    


    printf("----------application de la fonction ~al_strcpy~ :\n");
    char s1[20];
    char s2[20];
    printf("avant al_strcpy~, veillez saisir la destination: ");
    gets(s1);
    printf("avant al_strcpy~, veillez saisir la source: ");
    gets(s2);
    al_strcpy(s1, s2);   
    printf("apres al_strcpy~ (destination): %s \n\n",s1);

    printf("----------application de la fonction ~al_strcat~ :\n");
    char s3[20];
    char s[20];
    printf("avant ~al_strcat, veuillez saisir la destination: ");
    gets(s3);
    printf("avant ~al_strcat, veuillez saisir la source: ");
    gets(s);
    al_strcat(s3, s);  
    printf("apres ~al_strcat (destination): %s \n\n",s3);
    
    printf("----------application de la fonction ~str_reverse~: \n");
    char s4[40];
    printf("veuillez saisir une chaine pour l'inverser: ");
    gets(s4);
    str_reverse(s4);
    printf("l'inverse de la chaine saisie est: %s\n", s4);

    printf("\n----------application de la fonction ~str_wreverse~: \n");
    char s5[40];
    printf("veuillez saisir une chaine pour l'inverser EN PLACE: ");
    gets(s5);
    str_wreverse(s5);
    printf("l'inverse de la chaine saisie  EN PLACE est: %s\n", s5);

    printf("\n----------application de la fonction ~al_strlcpy~: \n");
    char s6[50];
    char s7[50];
    printf("veuillez saisir la destination: " );
    gets(s6);
    printf("veuillez saisir la source: " );
    gets(s6);
    printf("ce que retourne ~al_strlcpy: %zu\n", al_strlcpy(s6, s7, sizeof(s6)));

    printf("\n----------application de la fonction ~al_strlcat~: \n");
    char s8[50];
    char s9[50];
    printf("veuillez saisir la destination: " );
    gets(s8);
    printf("veuillez saisir la source: " );
    gets(s9);
    printf("ce que retourne ~al_strlcat: %zu\n", al_strlcpy(s8, s9, sizeof(s8)));
    printf("\n\n");
    return 0;
}
