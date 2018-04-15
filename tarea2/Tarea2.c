#include<stdio.h>
#include<string.h>
/*
Tarea 2 ICI 1142
Martín Santibáñez Ávalos
19.525.124-K
*/

int main(){
    int i, j, m, n;
    scanf("%d %d", &m, &n);
    char alfa[m+1][n+1];
    int minas[m+1][n+1];

    for(i=0;i<m;i++){
            scanf("%s", &alfa[i]);
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            minas[i][j] = 0;
            if(alfa[i][j]=='*') minas[i][j] = -1;
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(minas[i][j]==-1){
                //lados arriba, abajo, izquierda, derecha
                if(i+1<m && minas[i+1][j]!=-1) minas[i+1][j]++;
                if(i-1>=0 && minas[i-1][j]!=-1) minas[i-1][j]++;
                if(j+1<n && minas[i][j+1]!=-1) minas[i][j+1]++;
                if(j-1>=0 && minas[i][j-1]!=-1) minas[i][j-1]++;
                //diagonales
                if(i-1>=0 && j-1>=0 && minas[i-1][j-1]!=-1) minas[i-1][j-1]++;
                if(i-1>=0 && j+1<n && minas[i-1][j+1]!=-1) minas[i-1][j+1]++;
                if(i+1<m && j-1>=0 && minas[i+1][j-1]!=-1) minas[i+1][j-1]++;
                if(i+1<m && j+1<n && minas[i+1][j+1]!=-1) minas[i+1][j+1]++;
            }
        }
    }
    printf("\n\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(minas[i][j]==-1) printf("*");
            else printf("%d", minas[i][j]);
        }
        printf("\n");
    }
    return 0;
}
