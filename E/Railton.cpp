#include <bits/stdc++.h>
using namespace std;

#define INF 1e15L
#define MAXN 200005

int dist[MAXN], n, m, f;
set <pair<int,int> > q;
vector <pair<int,int> > adj[MAXN];

main(){
	cin >> n >> m >> f;
	f--;
	for(int i=0, x, y, c; i<m; i++){
		cin >> x >> y >> c;
		x--; y--;
		swap(x,y);
		adj[x].push_back(make_pair(y,c));
	}
	
	for(int i=0; i<n; i++){
		dist[i]= INF;
	}
	
	dist[f]= 0;
	q.insert(make_pair(0, f));
	
	while(!q.empty()){
		int x= q.begin()->second;
		q.erase(q.begin());
		
		for(int i=0, d, y; i<adj[x].size(); i++){
			y= adj[x][i].first;
			d= adj[x][i].second;
			if(dist[x] + d < dist[y]){
				if(dist[y]!=INF)
					q.erase(make_pair(dist[y],y));
				dist[y]= dist[x] + d;
				q.insert(make_pair(dist[y],y));
			}
		}
	}
	
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int x;
		cin >> x;
		cout << dist[x-1] << endl;
	}
}
