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
bool  vis[51][51]={0};
int n,m,maxim;

char getval(int i,int j,vector<string> arr){
    if(i<n && i>=0 && j<m && j>=0) return arr[i][j];
    else return '0';
}

void dfs(int x,int y , vector<string> arr,int d){
    maxim = max(d,maxim);
    vis[x][y]=1;
    int ans=0;
    for(int i=x-1;i<=x+1;i++){
        for(int j= y-1;j<=y+1;j++){   
            if(getval(i,j,arr)!='0')
            {
                if(!vis[i][j]){
                    
                    if(getval(i,j,arr) - arr[x][y]==1){
                        vis[i][j] = 1;
                        dfs(i,j,arr,d+1);
                    }
                }
            }      
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("route.in","r",stdin);
    //freopen("route.out","w",stdout);
    //freopen("F:/in.txt", "r", stdin);
    //freopen("F:/output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int c=1;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) cout << vis[i][j] << " ";
    //         cout << endl;
    // }
    while(n && m){
        memset(vis,false,sizeof(bool)*51*51);
        vector<string> arr(n);
        ::maxim=0;
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='A'){
                    //cout << i <<  " " << j << endl;
                    dfs(i,j,arr,1);
                }
            }
        }
        cin >> n >>m;
        printf("Case %d: %d\n",c++,::maxim);
    }
    return 0;
}



