#include <bits/stdc++.h>
using namespace std;

int main(){
    int v[5], ans = 1; //v[] = vetor com os elementos, ans = resposta
    
    for(int i = 0; i < 5; i++) //Fazendo a leitura dos elementos
        scanf("%d", v+i);  //Lendo o elemento v[i]
        
    for(int i = 1; i < (1<<5); i++){ //Testanto cada conjunto de elementos
        if(__builtin_popcount(i) > 3) // Desde que tenha no maximo 3 deles
            continue;
        int cur = 1; //Força total caso escolha esse conjunto
        for(int j = 0; j < 5; j++)
            if(i&(1<<j)) //Se o elemento j esta no conjunto
                cur *= v[j]; //Entao ele irá contribuir para o produto
        ans = max(ans, cur); //Verifica se o conjunto escolhido forneceu uma resposta maior
    }
    printf("%d\n", ans); //Escreve a resposta
}
