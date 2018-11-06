#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	assert(scanf("%d %d", &n, &m)!=EOF);
	assert(50 <= n && n <= 300);
	assert(50 <= m && m <= 300);
	printf("%d\n", n*m);
	assert(scanf("%d", &n)==EOF);
}
