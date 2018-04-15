#include<string.h>
#include<stdio.h>
/* Tarea 3 ICI 1142
Martín Santibañez
19.525.124-K
*/
int main(){
    int N, i;
    char palabra[105], j;
    int todas;
    scanf("%d\n", &N);
    for(i=0;i<N;i++){
        todas = 1;
        gets(palabra);
        char k = 'a';
        for(j='A'; j<='Z'; j++, k++){
            if(strchr(palabra, j)==NULL && strchr(palabra, k)==NULL){
                todas = 0;
            }
        }
        if(todas) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
