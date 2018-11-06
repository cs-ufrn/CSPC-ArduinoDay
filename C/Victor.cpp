#include <bits/stdc++.h>
using namespace std;

int n, m, p[30][30], x, y;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &p[i][j]);
	scanf("%d%d", &x, &y);
	for(int l = 0; l < x; l++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m*y; j++)
				printf("%d%c", p[i][j%m], " \n"[j==m*y-1]);
}
