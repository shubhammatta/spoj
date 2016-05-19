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

#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin>>t;
	vector<int> arr(100000001,0);
	vector<int> count(100000001,0); 
	for(int i=2;i<=100000000;i++){
		if(arr[i]==0)
		{
			for(int j=2*i;j<=100000000;j+=i){
				if(arr[j]==0)
					arr[j]++;
				else
					break;
			}
			count[i] = count[i-1]+1;
		}
		else
			count[i] = count[i-1];

	}
	while(t!=0){
		double y = t/log(t);
		double ans = (count[t]-y)*100.0/count[t];
		printf("%0.1lf\n",ans);
		cin >> t;

	}
	
}