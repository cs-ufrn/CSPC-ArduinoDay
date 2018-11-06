#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;
long long qtd[MAXN];

int main() {
  int n;
  cin >> n;
  for (auto i = 0; i < n; ++i) {
	int x; cin >> x;
	qtd[x]++;
  }
  long long ans = 0;
  for (int i = 1; i < MAXN; ++i) {
	ans += (qtd[i] * (qtd[i] - 1));
	for (int j = i + i; j < MAXN; j += i) {
	  ans += (qtd[i] * qtd[j]);
	}
  }
  cout << ans << endl;
}
