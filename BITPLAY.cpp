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
#define pb push_back
#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)
#define modulus 10000007
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


int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,k;cin >>t;
	while(t--){
		cin >> n >> k;
		if(k==0) cout << -1 << endl;
		else{
			int ones = __builtin_popcount(n);
			int ans = 1;
			k--;
			if(ones>k){
				ans = n;
				int i=1;
				while(__builtin_popcount(ans)!=k){
					if(ans& 1<<i){
						ans-= 1<<i;
					}
					i++;
				}
				cout << ans+1 << endl;
			}
			else if(ones == k){
				ans = n;
				int i=1;
				while(!(ans&1<<i)) i++;
				//cout << ans << " " << i << endl;
				ans -= 1<<i;
				ans+= 1<<(i-1);
				//cout << ans << endl;
				cout << (ans|=1) << endl;
			}
			else{
				ans = n;
				int i=1;
				while(!(ans&1<<i)) i++;
				//cout << i << endl;
				ans-=1<<i;
				i--;
				k-=ones;
				k++;
				//cout << i << " " << k << " " << ans << endl;
				for(int j=i;j>0 && k>0;j--,k--){
					ans|=1<<j;
				}
				cout << (ans|1) << endl;
			}
		}
	}
	
}