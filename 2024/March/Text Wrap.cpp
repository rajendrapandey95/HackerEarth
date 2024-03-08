#include<bits/stdc++.h>

using namespace std;







#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define int long long



bool check(int mid,vector<int>&v,int m){

    if(v[0]>mid) return false;

    int curW=v[0];

    int line=1;

    int n=(int)v.size();    

    for(int i=1;i<n;i++){

        if(v[i]>mid) return false;



        else{

            if(mid<(curW+v[i]+1)){

                line++;

                curW=v[i];

            }

            else{

                curW+=v[i]+1;

            }

        }



    }

    return line<=m;

}

void solve()

{



    int lo=0;

    int n,m;

    cin>>n>>m;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int hi=LLONG_MAX;

    int ans=hi;

    while(lo<=hi){

        int mid=(lo)+((hi-lo)>>1);

        if(check(mid,v,m)){

            ans=mid;

            hi=mid-1;

        }

        else lo=mid+1;



    }

    cout<<ans<<"\n";





}





signed main()

{

    fast



    solve();

    return 0;

}
