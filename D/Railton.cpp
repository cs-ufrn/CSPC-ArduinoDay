#include <bits/stdc++.h>
using namespace std;

#define INF 100000

int n, m, x, y, t;
char g[666][666];
int d[666][666][2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool inside(int a, int b){ return a>=0 && b>=0 && a<n && b<m;}
pair<int,int> f, h;
queue <pair<pair<int,int>, int> > fila;

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			d[i][j][0]= d[i][j][1]= INF;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> g[i][j];
			if(g[i][j]=='H'){
				fila.push(make_pair(make_pair(i,j),0));
				d[i][j][0]=0;
			}
			else if(g[i][j]=='F'){
				fila.push(make_pair(make_pair(i,j),1));
				d[i][j][1]=0;
			}

		}
	}
	
	while(!fila.empty()){
		x= fila.front().first.first;
		y= fila.front().first.second;
		t= fila.front().second;
		fila.pop();
		
		for(int i=0, nx, ny; i<4; i++){
			nx= x + dx[i];
			ny= y + dy[i];
			if(!inside(nx, ny) || d[nx][ny][t]!=INF || g[nx][ny]=='#') continue;
			d[nx][ny][t]= d[x][y][t] + 1;
			fila.push(make_pair(make_pair(nx, ny), t));
		}
	}
	
	bool ans=false;
	for(int i=0; i<n; i++){
		if(d[i][m-1][0] < d[i][m-1][1]) ans=true;
		if(d[i][0][0] < d[i][0][1]) ans=true; 
	}
	for(int i=0; i<m; i++){
		if(d[n-1][i][0] < d[n-1][i][1]) ans=true;
		if(d[0][i][0] < d[0][i][1]) ans=true;
	}
	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << d[i][j][0] << " ";	
		}
		cout << endl;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << d[i][j][1] << " ";	
		}
		cout << endl;
	}
	*/
	if(ans) cout << "Corre!\n";
	else cout << "Vish!\n";
}
