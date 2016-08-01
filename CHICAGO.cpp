/*
***************************************************************************************************************
 
                          Author : SHUBHAM MATTA
                          HACKERRANK HANDLE: voidcoder
                          SPOJ Handle: shubhammatta
                          Codeforces Handle: voidCoder
 
**************************************************************************************************************
*/
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <utility>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <sstream>

#define FOR(i,start,end) for(size_t i=start;i<end;i++)
#define rFOR(i,end,start) for(size_t i=end,i>=start;i--)
#define MOD 1000000007
#define line cout<<endl
#define ll long long int
#define ld long double
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mp make_pair
#define memory(x,y) memset(x,y,sizeof(x))
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)
#define ii pair<ll,ll>
#define F first
#define S second

using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}

string IntToString (int a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}

ll powerwithmodulus(ll base, ll exponent,ll modulus){
    ll result = 1; base%=modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1) result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void printArray(int arr[] , int n){ FOR(i,0,n) cout << arr[i] << " " ; line;}

void dijkstra(int m,int n,vector<vector<pair<int,double> > > adj)
{
    vector<bool> vis(n+1,0);
    vector<double> dis(n+1,0.00000);
    priority_queue<pair<double,int> > Q;
    Q.push(mp(100.000000,1));
    dis[1] = 100.00000;
    vis[1] = 1;
    while(!Q.empty()){
        pair<double,int> now = Q.top();Q.pop();
        for(int i=0;i<adj[now.S].size();i++){
            int k = adj[now.S][i].F;
            if(!vis[k]){
                vis[k] = 1;
                double val = adj[now.S][i].S * now.F/100;
                dis[k] = val;
                Q.push(mp(val,k));
            }
        }
    }
    cout << dis[n] << endl;
}



int main(){
    int n,m;
    cin >> n;
    while(n!=0){
        cin >> m;
        vector<vector<pair<int,double> > > adj(n+1);
        int fr,to;double x;
        for(int i=0;i<m;i++){
            cin >> fr >> to >> x;
            adj[fr].pb(mp(to,x));
            adj[to].pb(mp(fr,x));
        }
        dijkstra(m,n,adj);
        cin >> n;
    }
}