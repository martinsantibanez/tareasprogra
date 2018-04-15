#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Tarea 4 - ICI 1142-1
Martín Santibáñez
19.525.124-K
*/


void permutar(char frase[]){
    int i;
    for(i=1; i<strlen(frase); i+=2){
        char aux = frase[i];
        frase[i] = frase[i-1];
        frase[i-1] = aux;
    }
}
void rot13(char frase[]){
    int i;
    for(i=0; i<strlen(frase); i++){
        if(frase[i]!=' ')
            frase[i] = (frase[i]+13-'a')%26+'a';
    }
}
void slide(char frase[]){
    int i;
    char *aux = (char*)malloc(strlen(frase)*sizeof(char));
    strcpy(aux, frase);
    int mov = strlen(frase)/2;
    for(i=0; i<strlen(frase); i++){
        if(!(strlen(frase)%2==1 && i==strlen(frase)-1)){
            if(i-mov<0)
                frase[i] = aux[strlen(frase) + (i-mov)-1];
            else
                frase[i] = aux[i-mov];
        }
    }
}
void murcielago(char frase[]){
    int i, j, k;
    char murc[] = "murcielago";
    char alrvs[] = "ogaleicrum";
    for(i=0; i<strlen(frase); i++){
        for(j=0; j<strlen(murc); j++){
            if(frase[i] == murc[j]){
                frase[i] = alrvs[j];
                break;
            }
        }
    }
}


int main(){
    int i;
    char palabrita[999];
    //char palabrita[] = "gorila magila"; //test only
    gets(palabrita);
    char acciones[999];
    gets(acciones);
    for(i=0;i<strlen(acciones);i++){
        if(acciones[i]=='V')
            permutar(palabrita);
        else if(acciones[i]=='I')
            rot13(palabrita);
        else if(acciones[i]=='N')
            slide(palabrita);
        else if(acciones[i]=='C')
            murcielago(palabrita);
    }
    printf("\n%s", palabrita);
}
