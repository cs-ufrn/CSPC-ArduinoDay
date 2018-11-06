#include <bits/stdc++.h>
using namespace std;

int n, m, p[30][30], x, y;

int main(){
    scanf("%d%d", &n, &m); //Lendo as dimensoes
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &p[i][j]); //Lendo a matriz
    scanf("%d%d", &x, &y);
    for(int l = 0; l < x; l++) //Para cada uma das X sequencias da matriz
        for(int i = 0; i < n; i++) //Para cada uma das N linhas das matrizes nessa sequencia
            for(int j = 0; j < y; j++) //Para cada uma das Y cópias nessa linha
                for(int k = 0; k < m; k++) //Para cada uma das M colunas dessa cópia
                    printf("%d%c", p[i][k], (k==m-1) ? '\n' : ' '); //Mostra o elemento (i,k) da matriz
}
