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

//#define long long long
const long M = 1000000007; // modulo
int F[1000000];

long long int f(long n) {
	if(n<1000000)
	{
		long k=n/2;
		if (F[n] > 0) return F[n];
		else if (n%2==0) { // n=2*k
	 		return F[n] = (((2*f(k-1)*f(k))%M + (f(k)*f(k))%M) + M) % M ;
	 	} else { // n=2*k+1
	 		return F[n] = ((f((n-1)/2)*f((n-1)/2))%M + (f((n+1)/2)*f((n+1)/2))%M) % M;
	 	}
		
	}
	else
	 {
		long k=n/2;
		 if (n%2==0) { // n=2*k
	 		return (((2*f(k-1)*f(k))%M + (f(k)*f(k))%M) + M) % M ;
	 	} else { // n=2*k+1
	 		return ((f((n-1)/2)*f((n-1)/2))%M + (f((n+1)/2)*f((n+1)/2))%M) % M;
	 	}
	 }
}

int main(){

	long n;
	F[0]=0;
	F[1]=1;
	F[2] = 1;
	F[3] = 2;
	int t;cin >> t;
	int m;
	for(int i=4;i<1000000;i++)
		{F[i]=-1;}
	// for(int i=0;i<100;i++)
	// 	{cout << f(i) << " " << i << endl;}
	while(t--){
		cin >> n >> m;
		long long int temp1 = f(m+2);
		if(temp1<0) temp1+=M;
		long long int temp2 = f(n+1);
		if(temp2<0) temp2+=M;
		cout << (temp1 - temp2 +M)%M << endl;
		
	}
}