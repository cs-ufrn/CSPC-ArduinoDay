#include <bits/stdc++.h>
using namespace std;

int main(){
	int v[5], ans = 1;
	for(int i = 0; i < 5; i++){
		assert(scanf("%d", v+i)!=EOF);
		assert(-10 <= v[i] && v[i] <= 10);
	}
	for(int i = 1; i < (1<<5); i++){
		if(__builtin_popcount(i) > 3)
			continue;
		int cur = 1;
		for(int j = 0; j < 5; j++)
			if(i&(1<<j))
				cur *= v[j];
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	assert(scanf("%d", &v[0]) == EOF);
}
