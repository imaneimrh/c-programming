#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void *al_memchr(const void *s, int x, size_t n)
{
	size_t i;
	const char *temp;

	temp = s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == x)
			return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}

void *al_memset(void *str, int c, size_t n){
	unsigned char z;
	char *p;
	size_t i;

	p = str;
	z = c;
	i = 0;
	while (i < n)
	{
		p[i] = z;
		i++;
	}
	return (p);
}

void *al_memcpy(void *destination, const void *source, size_t n){
	size_t i;
	char *dest;
	char *s;

	dest = (char *)destination;
	s = (char *)source;

	if (n==0 || destination == source)
		return (destination);
	i = 0;
	while (n > 0){
		dest[i] = s[i];
		n--;
		i++;
	}
	return(destination);
}

void	*al_memmove(void *destination, const void *s, size_t n){
	size_t i;
	char *dest;
	const char	*source;

	dest = (char*)destination;
	source = (char*)s;
	i = 0;
	if (dest == source)
		return (destination);
	if (source < dest){
		while (i++ < n)
			dest[n - i] = source[n - i];
        }
	else{
		i = 0;
		while (n-- > 0){
			dest[i] = source[i];
			i++;
		}
	}
	return (destination);
}

char* al_strdup(const char *source){
	char *p;
	int	i;
	i = 0;
	while (source[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (source[i] != '\0')
	{
		p[i] = source[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

  
//write a function that takes an int array and its lenght and sort it in place in ascending order.
 void isort(int arr[], size_t n){ 
    int i, element, j; 
    for (i = 1; i < n; i++){ 
        element = arr[i];
         j = i - 1;
         while (j >= 0 && arr[j] > element){ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
    arr[j + 1] = element; 
    } 
}   
// Function to print the elements of an array
void printArr(int arr[], int n) { 
int i; 
for (i = 0; i < n; i++) 
printf("%d ", arr[i]); 
printf("\n"); 
}  











int main() {

    printf("-----------------application de la fonction ~al_memchr~ :\n");

    char test[100];
    char x;
    char *ptrx;

    printf("veuillez saisir une chaine de caractere dans laquelle on effectue la recherche: \n");
    gets(test);

    printf("veuillez saisir une valeur a rechercher: ");
    scanf("%c",&x);

    ptrx = (char*)memchr(test, x, strlen(test));

    if (ptrx != NULL) printf("\nle caractere '%c' existe, elle occupe la %ldeme position (il est d'indice %ld).\n",x, 1+(ptrx-test),(ptrx-test) );
    else printf("\n'%c' n'existe pas.\n",x);


    printf("\n----------------application de la fonction ~al_memset~ :\n");

    char str[50] = "je suis entrain de faire TP5";
    printf("\navant al_memset(): %s\n", str);

    al_memset(str, '~', 7);
  
    printf("apres al_memset():  %s\n", str);

    printf("\n----------------application de la fonction ~al_memcpy~ :\n");
    const char s[50] = "test reussi!";
    char dest[50] = "on est entrain de tester la fonction ~al_memcpy";
    printf("avant ~al_memcpy~ dest = %s\n", dest);
    al_memcpy(dest, s, strlen(s)+1);
    printf("apres ~al_memcpy~ dest = %s\n", dest);

    printf("\n----------------application de la fonction ~al_memmove~ :\n");
    const char s1[50] = "test reussi avec al_memmove! ";
    char dest1[50] = "on est entrain de tester la fonction ~al_memmove";
    printf("avant ~al_memmove~ dest = %s\n", dest1);
    al_memmove(dest1, s1, strlen(s1)+1);
    printf("apres ~al_memmove~ dest = %s\n", dest1);

    printf("\n----------------application de la fonction ~al_strdup~ :\n");
    const char* ori = "tester la fonction ~al_strdup";
    char* copie = strdup(ori);
    printf( "le string original: %s\n", ori );
    printf( "la fonction al_strdup~ retourne la copie: %s\n", copie );
    free( copie );

    printf("\n----------------application de la fonction ~isort~ :\n");
    int arr[] = {17, 18, 19, 20}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    isort(arr, n); 
    printArr(arr, n); 
    return 0;
    }

  