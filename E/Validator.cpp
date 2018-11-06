#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(auto i=(a); i<(b); i++)
#define dec(i,n,a) for(auto i=(n); i>=(a); i--)
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define EPS 3e-8
#define fcin ios_base::sync_with_stdio(false)
#define db(x) cerr << #x << " == " << x << endl
#define _ << " " <<
#define MAXN 200001
#define LOGN 29
typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n, m, F;
ll dis[MAXN];
vector<int> adj[MAXN], cost[MAXN];
set<pair<ll,int> >fila;

int main(){
	assert(scanf("%d%d", &n, &m)!=EOF);
	char cccc;
	assert(scanf("%c", &cccc)!=EOF && cccc == '\n');
	assert(scanf("%d", &F)!=EOF);
	assert(2 <= n && n <= 200000);
	assert(1 <= m && m <= 200000);
	assert(1 <= F && F <= n);
	for(int i = 0; i < m; i++){
		int u, v, c;
		assert(scanf("%d%d%d", &u, &v, &c)!=EOF);
		assert(1 <= u && u <= n);
		assert(1 <= v && v <= n);
		assert(u != v);
		assert(1 <= c && c <= 10000);
		adj[v].push_back(u);
		cost[v].push_back(c);
	}
	for(int i = 1; i <= n; i++)
		dis[i] = -1;
	dis[F] = 0;
	fila.insert(make_pair(0,F));
	while(!fila.empty()){
		ll d = fila.begin()->first;
		int v = fila.begin()->second;
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
	rep(i,1,n+1){
		assert(0 <= dis[i] && dis[i] < 2e9+2);
	}
	int k;
	assert(scanf("%d", &k)!=EOF);
	assert(1 <= k && k <= n);
	set<int> Vs;
	rep(i,0,k){
		int v;
		assert(scanf("%d", &v)!=EOF);
		assert(1 <= v && v <= n);
		Vs.insert(v);
		printf("%lld\n", dis[v]);
	}
	assert(sz(Vs) == k);
	char c;
	assert(scanf(" %c", &c) == EOF);
}
