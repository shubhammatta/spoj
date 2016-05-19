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
#include <string>

#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define modulus 10000007
#define MOD 1000000007

using namespace std;
#define ll long long int

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

ll min(ll a,ll b){
	return a>b?b:a;
}

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

int primeinfact(int n,int prime){
	int count =0 ;
	//cout << "here" << endl;
	//if(prime>n)return 0;
	while(n!=0){
		n/=prime;
		count +=n;
	}
	//cout << count << " count " <<  prime<< endl;
	return count;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll a ,b,temp;
	cin >> a >> b;
	temp = b;
	vector<int> primes(b,0);
	for(int i=2;i<=b/2;i++){
		while(temp%i==0){
			temp/=i;
			primes[i]++;
		}
	}
	ll ans = 2;
	for(int i=2;i<=b/2;i++){
		if(primes[i]!=0){
			while(primeinfact(ans,i)!=primes[i]){
				ans++;
			} 
		}
	}
	if(ans>a) cout << ans -a -1 << endl;
	else cout << 0 << endl;
	

	
}