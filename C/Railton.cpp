#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, g[1000][1000];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin >> g[i][j];
	}
	
	cin >> x >> y;
	while(x--){
		for(int k=0; k<n; k++){
			for(int j=0; j<y; j++){
				for(int i=0; i<m; i++){
					cout << g[k][i] << " ";
				}
			}
			cout << endl;
		}
	}
}
