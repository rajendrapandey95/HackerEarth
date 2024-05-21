#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n;

int dp[5005][5005];

ll s[5005];

int mintillnow[5005];

int solve(int pos,int mini) {
    if(pos== n+1){
        return 0;
    }
    if(dp[pos][mini]!=-1){
        return dp[pos][mini];
    }
    int min1 = mintillnow[pos-1];
    int min2 = mini;
    int res = 0;
    if(s[pos]> min1 && s[pos] > min2){
        res = solve(pos+1,mini);
    }
    if(s[pos]<= min1){
        res=max(res,solve(pos+1,min1)+1);
        res=max(res,solve(pos+1,min2)+1);
    }
    if(s[pos]<= min2 && s[pos]>min1){
        res=max(res,solve(pos+1,s[pos])+1);
        res=max(res,solve(pos+1,min2));
    }
    dp[pos][mini]=res;
    return res;
}

void compress() {
    vector<ll> temp;
    map<ll,int> f;
    for(int i=1;i<=n;i++){
        temp.push_back(s[i]);
    }
    sort(temp.begin(),temp.end());
    f[temp[0]]=1;
    for(int i=1;i<n;i++){
        if(f[temp[i]]==0){
            f[temp[i]]=f[temp[i-1]]+1;
        }
    }
    for(int i=1;i<=n;i++){
        s[i]=f[s[i]];
    }
}

int main() {
    cin>>n;
    int mini = 5005;
    mintillnow[0]=mini;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    compress();
    for(int i=1;i<=n;i++){
        mini = min((ll)mini,s[i]);
        mintillnow[i] = mini;
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,5001)<<endl;
}
