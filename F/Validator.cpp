#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;

int n;
long long qt[MAXN];

int main(){
	assert(scanf("%d", &n)!=EOF);
	assert(1 <= n && n <= 1000000);
	for(int i = 0; i < n; i++){
		int v;
		assert(scanf("%d", &v)!=EOF);
		assert(1 <= v && v <= 1000000);
		qt[v]++;
	}
	{
		int v;
		assert(scanf("%d", &v)==EOF);
	}
	long long ans = 0;
	for(int i = 1; i < MAXN; i++){
		ans += qt[i]*(qt[i]-1);
		for(int j = i+i; j < MAXN; j += i)
			ans += qt[i]*qt[j];
	}
	printf("%lld\n", ans);
}

