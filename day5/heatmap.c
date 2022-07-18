#include <stdio.h>

void encercler(int X, int entier, int tableau[20][20]){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(tableau[i][j]==X){
//(entier <= tableau[i-1][j-1] && tableau[i-1][j-1]<=57) 
//parceque X>au code ascii de tous les entiers donc cette affectation doit etre verifiee 
//avec la condition sur les nombres si ca depasse 57 (ascii de 9) on ne remplace pas)
//tout les entiers ont un code ascii > a celui du point donc si on ajoute pas || on n'aura jamais ascii entier<ascii tablaeu[][]
//donc jamais d'affectation
                if(i!=0 && j!=0 && ( (entier <= tableau[i-1][j-1] && tableau[i-1][j-1]<=57) || tableau[i-1][j-1]==46))
                tableau[i-1][j-1] = entier;

                if(i!=0 &&  ( (entier<= tableau[i-1][j] && tableau[i-1][j]<=57) || tableau[i-1][j]==46))
                tableau[i-1][j] = entier;

                if(i!=0 && j!=19 && ((entier <= tableau[i-1][j+1] && tableau[i-1][j+1]<=57) || tableau[i-1][j+1]==46))
                tableau[i-1][j+1] = entier;

                if(j!=0 && ( (entier <= tableau[i][j-1] && tableau[i][j-1]<=57) || tableau[i][j-1]==46))
                tableau[i][j-1] = entier;

                if(j!=19 && ((entier <= tableau[i][j+1] && tableau[i][j+1]<=57) || tableau[i][j+1]==46))
                tableau[i][j+1] = entier;

                if(j!=0 && i!=19 && ((entier <= tableau[i+1][j-1] && tableau[i+1][j-1]<=57) || tableau[i+1][j-1]==46))
                tableau[i+1][j-1] = entier;

                if(i!=19 && ((entier <= tableau[i+1][j] && tableau[i+1][j]<=57) || tableau[i+1][j]==46))
                tableau[i+1][j] = entier;

                if(i!=19 && i!=19 && ((entier <= tableau[i+1][j+1] && tableau[i+1][j+1]<=57) || tableau[i+1][j+1]==46))
                tableau[i+1][j+1] = entier;
            }
        }
    }
return;
}

void affichage(int tableau[20][20]){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++)
        if(65<=tableau[i][j] && tableau[i][j]<=122 || tableau[i][j]==46 || tableau[i][j]==42){
            if(j==19)
            printf(" %c\n",tableau[i][j]);
            else
            printf(" %c ",tableau[i][j]);
        }
        else{
            if(tableau[i][j]>=10){
                if(j==19)
                printf("%d\n ",tableau[i][j]);
                else
                printf("%d ",tableau[i][j]);
            }
            else{
                if(j==19)
                printf(" %d\n ",tableau[i][j]);
                else
                printf(" %d ",tableau[i][j]);
            }
        }
        }
    printf("\n\n");
    return;
}


void heatmap(int X, int tableau[20][20]){
    encercler('X',0, tableau);
    for (int i=0; i<20; i++){
       encercler(i,i+1, tableau); 
    }
    return;
}




int main() {

//creer un tableau de 20x20
int tableau[20][20];

for(int i=0; i<20; i++){
    for(int j=0; j<20; j++)
        tableau[i][j]='.';
}

//choisir deux positions pour les joueurs
tableau[9][3] = 'Y';
//tableau[19][4] = 'X';
//tableau[18][3] = 'X';
tableau[5][7] = 'X';

heatmap('X', tableau);

printf("HEATMAP\n\n");
affichage(tableau);


return 0;
}
