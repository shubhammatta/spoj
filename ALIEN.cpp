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

int horner(std::vector<int> poly, int n, int x)
{
    long long result = poly[0];  // Initialize result
    //for(int i=0;i<=n;i++)
    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        result = ((result*x) + poly[i]);
    return result;
}
int lim;
//when a sliding window is given find max of each subarray O(n) time
void SlidingWindow(int arr[], int n, int k)
{
    std::deque<int>  Qi(k);
    int maxim = 0;
    int i;
    for (i = 0; i < k; ++i){
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) Qi.pop_back();  // Remove from rear
        Qi.push_back(i);
    }
    for ( ; i < n; ++i){
        int tmp =  arr[Qi.front()];
        if(tmp<=lim) maxim = max(maxim,tmp);
        while ( (!Qi.empty()) && Qi.front() <= i - k) Qi.pop_front();  // Remove from front of queue
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) Qi.pop_back();
        Qi.push_back(i);
    }
    int tmp =  arr[Qi.front()];
    if(tmp<=lim) maxim = max(maxim,tmp);
    return maxim;
}

int a[100006]={0};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("route.in","r",stdin);
    //freopen("route.out","w",stdout);
    //freopen("F:/in.txt", "r", stdin);
    //freopen("F:/output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;cin>>t;
    while(t--){
        cin >> n >> lim;
        vector<int> A(n);
        cin >> A[0];
        a[0] = A[0];
        for(int i=1;i<n;i++){
            cin >> A[i];
            a[i] = A[i] + a[i-1];
        }
        int start = 0;
        int end = n-1;
        vector<int> ans(100,0);
        while(start!=end){
            int mid = (start+end)>>1;
            int maxim = SlidingWindow(a,n,mid);
            ans[mid] = maxim;
            if(maxim>lim){
                
            }
        }
    }   
    return 0;
}



