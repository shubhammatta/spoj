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

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	long long int n,k,a,b,c,d;
	scanf("%lld %lld\n", &n ,&k);
	n%=modulus ;k%=modulus ;
	while(n!=0 && k!=0)
	{
		long long  int sum = 2*powerwithmodulus ((n-1) ,k )%modulus;
		sum%=modulus ;
		b = powerwithmodulus (n ,k )%modulus;
		c=2*powerwithmodulus ((n-1),(n-1))%modulus ;
		d=powerwithmodulus (n ,n)%modulus;
		sum = ((sum + b)%modulus + (c +d )%modulus)%modulus;
		printf("%lld\n",sum );
		scanf("%lld %lld", &n ,&k);
		n%=modulus ;k%=modulus ;

	}

	
	
}