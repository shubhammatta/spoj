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

ll largestPowerOf2(ll n)
{
    return (ll)pow(2, floor(log(n) / log(2)));
}

int main() {
   //int n,d;
   string s;
   cin >> s;
   while(s!="00e0")
   {
      /*The following loop is the DP
      implementaion of Josephus problem*/
   // cout << s << endl;
      int x = stoi(s.substr(0,2));
      int y = s[3]-'0';
       //cout << x  << " " << y << endl;

      int n = x*pow(10,y);
      int d=2;
      
         
      cout <<   (n- largestPowerOf2(n))*2 + 1 << endl;
        cin >> s; 
   }
   return 0;
}


