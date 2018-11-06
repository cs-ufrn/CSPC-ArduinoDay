#include <bits/stdc++.h>
using namespace std;

int main(){
	int v[5], ans=1, cont;
	for(int i=0; i<5; i++) cin >> v[i];
	for(int i=0; i<(1<<5); i++){
		int aux= 1;
		cont=0;
		for(int j=0; j<5; j++){
			if(i&(1<<j)){
				aux*= v[j];
				cont++;
			}
		}
		if(cont<=3)
			ans= max(ans, aux);
	}
	cout << ans << endl;
}
