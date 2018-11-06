#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

int n, m, dis[MAXN], F; //Dis[i] = menor tempo de i para F
vector<int> adj[MAXN], cost[MAXN]; //Lista de adjacência e custos
set<pair<int,int> >fila; //Fila para o algoritmo de Dijkstra

int main(){
    scanf("%d%d%d", &n, &m, &F);
    for(int i = 0; i < m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c); //Coloca as arestas no sentido oposto
        adj[v].push_back(u);        //Para ao invés de ir para F, sair de F para as demais
        cost[v].push_back(c);
    }
    //Algoritmo de Dijkstra a partir de F:
    for(int i = 1; i <= n; i++)
        dis[i] = -1;
    dis[F] = 0;
    fila.insert(make_pair(0,F));
    while(!fila.empty()){
        int d = fila.begin()->first, v = fila.begin()->second;
        fila.erase(fila.begin());
        if(d != dis[v])
            continue;
        for(int i = 0; i < (int)adj[v].size(); i++){
            int u = adj[v][i], c = cost[v][i];
            if(dis[u] == -1 || dis[u] > dis[v] + c){
                dis[u] = dis[v]+c;
                fila.insert(make_pair(dis[u],u));
            }
        }
    }
    //Fim do algoritmo de Dijkstra
    int k;
    scanf("%d", &k);
    while(k--){ //Para cada query
        int v;
        scanf("%d", &v); //Le a cidade
        printf("%d\n", dis[v]); //E mostra a resposta
    }
}
