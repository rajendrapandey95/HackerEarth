#include<bits/stdc++.h>

using namespace std;



#define st_clk double st=clock();

#define end_clk double en=clock();

#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;





#define f_in(st) freopen(st,"r",stdin);

#define f_out(st) freopen(st,"w",stdout);



#include<cstdio>

#include<iostream>

#include<algorithm>



using namespace std;





char str[3005];



bool comp(int i,int j){

    return (str[i]!=str[j])? str[i]>str[j]: i<j;

}





int main(){

	 #ifndef ONLINE_JUDGE

     f_in("in5");

     f_out("out5");

     #endif

     int t,n,i,in[3001];

     scanf("%d",&t);

     while(t--){

	    scanf("%s%d",str,&n);

	    n--;

	    for(i=0;str[i]!='\0';i++)	in[i]=i;

	    sort(in,in+i,comp);

	    for(i=0;str[i]!='\0';i++,n=in[n]) putchar(str[n]);

	    puts("");

	 }

     return 0;

}




