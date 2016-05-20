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
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>

#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define MOD 1000000007
#define modulus 1
using namespace std;
#define ll long long

ll powerwithmodulus(ll base, ll exponent)
{
    ll result = 1;
    base%=modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// int gcd(int a, int b)
// {
//     while(b) b ^= a ^= b ^= a %= b;
//     return a;
// }

int sum1(long long int x){
	int count=0;
	while(x!=0)
		{count+=x%10;x/=10;}
	return count;
}

long long int rec(long long int b){
	if(b/10==0) return b*(b+1)/2;
	else if(b==10) return 46;
	else{
		return (int(b/10)!=1) ? (10*rec(b/10 -1) + (b/10)*46 + (b%10)*sum1(b/10) + rec(b%10)) : (46+(b%10)*sum1(b/10) + rec(b%10)) ;
 	}
}

long long sum(long long N){
    if(N/10==0) return N*(N+1)/2;
    int i=0;
    long long n=N;
    while(n/10!=0){
        i++;
        n/=10;
    }
    int p=pow(10,i);
    return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
}



int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	long long int n,m;
	cin >> n >> m;
	vector<long long int > arr(n);
	cin >> arr[0];
	ll maxim = 0;
	ll last = 0;
	for(int i=1;i<n;i++){
		cin >> arr[i];
		arr[i]+=arr[i-1];
		if(arr[i]<=m)
			{maxim = max(maxim, arr[i]);last=i;}
	}
	//ll maxim=0;
	for(ll i=n;i>last;i--){
		//maxim = max(maxim,rec(arr,0,i,m,i));
		if(arr[i]-arr[0]<=m){
			maxim = max(maxim,arr[i]-arr[0]);
		}
		else{
			ll start=0;
			ll end =i;
			ll tmp = i;
			while(start!=end){
				ll mid = (start+end)/2;
				if(arr[tmp]-arr[mid]>m){
					start=mid+1;
				}
				else
				{
					end = mid;
				}
			}
			maxim = max(maxim,arr[tmp]-arr[start]);
		}
	}
	cout << maxim << endl;
	return 0;
	
}