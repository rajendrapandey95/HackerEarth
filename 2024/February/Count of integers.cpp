 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 17;
int phi[maxn], divs[maxn];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i = 1; i < maxn; i++){
		phi[i] += i;
		for(int j = i * 2; j < maxn; j += i)
			phi[j] -= phi[i];
		for(int j = i; j < maxn; j += i)
			divs[j]++;
	}
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cout << n - phi[n] - divs[n] + 1 << '\n';
	}
}
