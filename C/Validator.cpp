#include <bits/stdc++.h>
using namespace std;

int n, m, p[30][30], x, y;

int main(){
	assert(scanf("%d%d", &n, &m)!=EOF);
	assert(1 <= n && n <= 30 && 1 <= m && m <= 30);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			assert(scanf("%d", &p[i][j])!=EOF);
			assert(1 <= p[i][j] && p[i][j] <= 30);
		}
	assert(scanf("%d%d", &x, &y)!=EOF);
	assert(1 <= x && x <= 30 && 1 <= y && y <= 30);
	for(int l = 0; l < x; l++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m*y; j++)
				printf("%d%c", p[i][j%m], " \n"[j==m*y-1]);
	assert(scanf("%d",&x)==EOF);
}
