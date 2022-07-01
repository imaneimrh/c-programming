#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//exercice 1 **************************************************************************************************************
typedef struct
{
    float real;
    float imaginary;

}complex;

void showcase(complex y){
    printf("%f + %f i \n\n", y.real, y.imaginary);
    return;
}

complex addition(complex x, complex y){
    complex sum;
    sum.real = x.real + y.real;
    sum.imaginary = x.imaginary + y.imaginary;
    return sum;
}

complex substract(complex x, complex y){
    complex sub;
    sub.real = x.real - y.real;
    sub.imaginary = x.imaginary - y.imaginary;
    return sub;
}

complex multiply(complex x, complex y){
    complex multiple;
    multiple.real = x.real*y.real - x.imaginary*y.imaginary;
    multiple.imaginary = x.real*y.imaginary + y.real*x.imaginary;
    return multiple;
}

complex divide(complex x, complex y){
    complex div, multiple;
    float deno;
    multiple.real = x.real*y.real + x.imaginary*y.imaginary;
    multiple.imaginary = y.real*x.imaginary - x.real*y.imaginary;
    deno= (y.real)*(y.real) + (y.imaginary)*(y.imaginary);
    div.real = multiple.real*(1/deno);
    div.imaginary = multiple.imaginary*(1/deno);
    return div;
}

//***********************************************************************************************************************

//exercice 2 **************************************************************************************************************

typedef struct
{
    int entier;
    char string[100];
}ex2;

void swap_contents(ex2* X, ex2* Y){
    int *Xe = &(*X).entier;
    int *Ye = &(*Y).entier;
    int temp=*Xe;
    *Xe = *Ye;
    *Ye = temp;
    char tempss[100];
    strcpy(tempss, (*X).string);
    strcpy((*X).string, (*Y).string);
    strcpy((*Y).string,tempss);
    return;
}

//***********************************************************************************************************************

//exercice 3 **************************************************************************************************************
typedef struct
{
    char name[500];
    char phonenumber[100];
    int ID;
}contact;

void printPerson(contact *person) {
    printf("Name : %s\n", person -> name);
    printf("Phone Number : %s\n\n", person -> phonenumber);
}

void add(contact *person) {
    printf("Insert full name: ");
    fgets(person -> name, 500, stdin);
    printf("\n");
    printf("Insert phone number: ");
    fgets(person -> phonenumber, 100, stdin);
}

void list(contact *book) {
    for (int i = 0; i < 8; i++) {
        printPerson(&book[i]);
    }
}

void quit()
{
  exit(0);
}

//***********************************************************************************************************************












int main()
{
    printf("------------------------------EXERCICE 1------------------------------\n\n");
    //application exercice 1_______________________________________________________________________________________________
    complex cnum1, cnum2, sum, diff, multiple, div;
    printf("Enter real and imaginary part of first complex number:\n");
    scanf("%f %f", &cnum1.real, &cnum1.imaginary);
    showcase(cnum1);
    printf("Enter real and imaginary part of second complex number:\n");
    scanf("%f %f", &cnum2.real, &cnum2.imaginary);
    showcase(cnum2);


    sum = addition(cnum1, cnum2);
    diff = substract(cnum1, cnum2);
    multiple = multiply(cnum1, cnum2);
    div = divide(cnum1, cnum2);

    printf("la somme: \n");
    showcase(sum);
    printf("la difference: \n");
    showcase(diff);
    printf("la multiplication: \n");
    showcase(multiple);
    printf("la division: \n");
    showcase(div);
    //____________________________________________________________________________________________________________________
    printf("------------------------------EXERCICE 2------------------------------\n\n");
    //application exercice 2_______________________________________________________________________________________________
    ex2 un = {34, "age de Leila"};
    ex2 deux = {20, "age de Meriem"};
    printf("first variable: %d, %s\n\n", un.entier, un.string);
    printf("second variable: %d, %s\n\n", deux.entier, deux.string);
    swap_contents(&un, &deux);
    printf("swaaaap!\n");
    printf("first variable: %d, %s\n\n", un.entier, un.string);
    printf("second variable: %d, %s\n\n", deux.entier, deux.string);

    //____________________________________________________________________________________________________________________
    printf("------------------------------EXERCICE 3------------------------------\n\n");
    //application exercice 3_______________________________________________________________________________________________
    contact* book = calloc (8, sizeof(contact)); 
    printf("enter contacts\n\n");
    for (int i = 0; i < 8; i++) {
        printf("Person %d:\n", i+1);
        add(&book[i]);
    }
    printf("\n\nBOOK""""""""""""""""""""""""""""""""""""""""""""""""""""""\n\n");
    list(book);
    if (book) free (book);
    return 0;
}
