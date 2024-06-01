#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n, m;
		int mat[40][40]={0};
		cin>>n>>m;
		for(int i=1; i<=m; i++){
			int x, y;
			cin>>x>>y;
			mat[x][y]=mat[y][x]=1;
		}
		vector<int>v;
		for(int i=1; i<=n; i++)v.push_back(i);	
		int flag=0;			
		while(true){
			int i;
			for(i=1;  i<v.size(); i++){
				if(!mat[v[i]][v[i-1]])break;
			}	
			if(i == v.size()){
				flag=1;break;
			}
			if(!next_permutation(v.begin(),v.end()))break;	
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
