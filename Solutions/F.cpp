#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;

int n;
long long qt[MAXN]; //Salva a quantidade de ocorrências de cada número

int main(){
    scanf("%d", &n); //Lendo a quantidade de números
    for(int i = 0; i < n; i++){
        int v;
        scanf("%d", &v); //Lendo cada número
        qt[v]++; //Incrementando as ocorrências
    }
    long long ans = 0; //Resposta inicialmente é 0
    for(int i = 1; i < MAXN; i++){ //Para cada número i
        ans += qt[i]*(qt[i]-1); //Considera os pares de índices distintos onde os elementos são iguais a i
        
        for(int j = i+i; j < MAXN; j += i) //Considera cada j que é múltiplo de i
            ans += qt[i]*qt[j];             //Adiciona os pares de índices onde o primeiro é j e o segundo é i
    }
    printf("%lld\n", ans); //Mostra a resposta
}

