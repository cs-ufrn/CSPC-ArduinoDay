#include <bits/stdc++.h>
#define MAXN 600*600+10
using namespace std;

int n, m, H = 0, F = 1, disH[MAXN], disF[MAXN];
char grid[600][600];
vector<int> adj[MAXN];

int get(int i, int j){
	return i*m + j + 2;
}

void add(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void bfs(int v, int * dis){
	for(int i = 0; i < MAXN; i++)
		dis[i] = -1;
	dis[v] = 0;
	queue<int> fila;
	fila.push(v);
	while(!fila.empty()){
		v = fila.front();
		fila.pop();
		for(int i = 0; i < (int)adj[v].size(); i++)
			if(dis[adj[v][i]] == -1){
				dis[adj[v][i]] = dis[v]+1;
				fila.push(adj[v][i]);
			}
	}
}

char s[1024];

int main(){
	assert(scanf("%d%d", &n, &m)!=EOF);
	assert(1 <= n && n <= 600 && 1 <= m && m <= 600);
	for(int i = 0; i < n; i++){
		assert(scanf("%s",s)!=EOF);
		assert((int)strlen(s)==m);
		for(int j = 0; j < m; j++){
			assert(s[j] == '.' || s[j] == '#' || s[j] == 'H' || s[j] == 'F');
			grid[i][j] = s[j];
			if(grid[i][j] == 'H')
				add(H, get(i,j));
			if(grid[i][j] == 'F')
				add(F,get(i,j));
			if(i > 0 && grid[i][j] != '#' && grid[i-1][j] != '#')
				add(get(i,j),get(i-1,j));
			if(j > 0 && grid[i][j] != '#' && grid[i][j-1] != '#')
				add(get(i,j),get(i,j-1));
		}
	}
	assert(adj[H].size() == 1);
	char cc;
	assert(scanf(" %c", &cc) == EOF);
	bfs(H,disH);
	bfs(F,disF);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(i==0 || j==0 || i==n-1 || j==m-1){
				if(disH[get(i,j)] != -1 && (disH[get(i,j)] < disF[get(i,j)] || disF[get(i,j)] == -1)){
					puts("Corre!");
					return 0;
				}
			}
	puts("Vish!");
}

