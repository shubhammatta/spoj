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

int rec(string s,int start , int end){
	if(start>=end)
		return 0;
	else if(dp[start][end]!=-1)
		return dp[start][end];
	else{
		if(s[start]==s[end])
			return dp[start][end] = rec(s,start+1,end-1);
		else{
			return dp[start][end] = min(rec(s,start,end-1)+1,rec(s,start+1,end)+1);
		}
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	while(t>0){
		string s;
		memset(dp, -1, sizeof dp); 
		cin >> s;
		cout << rec(s,0,s.length()-1) << endl;
		t--;
	}
	
}