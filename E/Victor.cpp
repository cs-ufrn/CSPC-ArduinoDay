#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

int n, m, dis[MAXN], F;
vector<int> adj[MAXN], cost[MAXN];
set<pair<int,int> >fila;

int main(){
	scanf("%d%d%d", &n, &m, &F);
	for(int i = 0; i < m; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[v].push_back(u);
		cost[v].push_back(c);
	}
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
	int k;
	scanf("%d", &k);
	while(k--){
		int v;
		scanf("%d", &v);
		printf("%d\n", dis[v]);
	}
}
