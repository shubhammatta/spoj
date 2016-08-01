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

int tree[4*100000];
int A[100000];

ll BIT[4*100200]={0}, a[200200]={0}, n;
void update(ll x, ll val)
{
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
ll query(int x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf("%lld", &n);
     ll tmp= n;
     n=200000;
     int i;
     for(i = tmp; i >=1; i--)
     {
           scanf("%lld", &a[i]);
           //update(n-i+1, a[i]);
     }
     for(int i=1;i<=tmp;i++) update(i,a[i]);
     ll q,ch,l,r,x;
     cin >> q;
     while(q--){
      cin >> ch;
      if(ch==1){
        cin >> l >> r;
        cout << query(tmp-l+1) - query(tmp-r) << endl;
      }
      else{
        cin >> x;
        update(tmp+1,x);tmp++;
      }
     }
     //printf("sum of first 10 elements is %d\n", query(10));
     //printf("sum of all elements in range [2, 7] is %d\n", query(7)–query(1));
     return 0;
}

