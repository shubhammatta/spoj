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
int a,b;
bool between(int t){
	if(t>=a && t<=b) return true;
	return false;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	
	cin >> a >> b;
	vector<int> X(n);
	for(int i=0;i<n;i++){
		cin >> X[i];
	}
	if(n==1){
		if(between(X[0])) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else{
		int s = n>>1;
		int t = n-s;
		int mask= 1;
		ll count=0;
		vector<int> a1;
		vector<int> a2;

		while(mask<1<<s){
			int i=0;
			ll p = 0;
			for(;i<20;i++){
				if(mask& 1LL<<i) {
					p+=X[i];
				}
			}
			a1.pb(p);
			if(between(p)) count++;
			mask++;
		}
		mask = 1;
		while(mask < 1<<t){
			int i=0;
			ll p = 0;
			for(;i<20;i++){
				if(mask& 1LL<<i) {
					p+=X[i+s];
				}
			}
			a2.pb(p);
			if(between(p)) count++;
			mask++;
		}
		//cout << count << endl;
		sort(a1.begin(),a1.end());
		sort(a2.begin(),a2.end());
		//for(int i=0;i<a1.size();i++) cout << a1[i] << " "; cout << endl;
		//for(int i=0;i<a2.size();i++) cout << a2[i] << " "; cout << endl;
		for(int i=0;i<a1.size();i++){
			int t1 = lb(a2,a-a1[i]) - a1.begin();
			int t2 = ub(a2,b-a1[i]) - a1.begin();
			count+= (t2-t1);
		}
		if(between(0)) count++;
		cout << count << endl;
	}
	
}