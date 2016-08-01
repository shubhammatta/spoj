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
#define modulus 10000007
using namespace std;
#define ll long long
int dp[6100][6100];
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

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	vector<int> p(64,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
		for(int j=0;j<64;j++){
			if(a[i]&(1LL<<j)) p[j]++;
		}
		//for(int j=0;j<10;j++) cout << p[j] << " "; cout << endl;
	}
	//for(int i=0;i<64;i++) cout << p[i] << " "; cout << endl;

	for(int i=0;i<64;i++){
		if(p[i]>0 && p[i]<n) p[i]=1;
		else p[i]=0;
	}
	//for(int i=0;i<64;i++) cout << p[i] << " "; cout << endl;
	unsigned ll ans=0;
	for(int i=0;i<64;i++){
		if(p[i]) ans+=1LL<<i;
		//cout << ans << i << endl;
	}
	cout << ans << endl;
	
}