#include<stdio.h>
/*Tarea 1
Martín Santibáñez Avalos
19.525.124-K
*/
int main(){
    int inf,sup;
    scanf("%d %d", &inf, &sup);
    int i,j, sumdiv=0, cantdiv=0, maxsum=0, maxdiv=0, num =0;
    for(i=inf;i<=sup;i++){
        cantdiv=0;
        sumdiv=0;
        for(j=1;j<i;j++){
            if(i%j==0){
                cantdiv++;
                sumdiv+=j;
            }
        }
        if(cantdiv>maxdiv && sumdiv>i){
            maxdiv = cantdiv;
            num = i;
            maxsum = sumdiv;
        }

    }
    if(num!=0){
        printf("Entre %d y %d, el numero %d tiene %d divisores y la suma de sus divisores es %d\n", inf, sup, num, maxdiv, maxsum);
    } else {
        printf("No se encontro numero que cumpliera las condiciones!\n");
    }

}
