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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll n = 1000001;
	ll arr[1000001]={0};
	ll count=0;
	for(size_t i=2;i<n;i++){
		if(arr[i]==0){
			for(int j=i;j<n;j+=i){
				count=0;
				ll temp = j;
				while(temp%i==0){
					temp/=i;
					count++;

				}
				arr[j] = max(arr[j],count);
			}
		}
		//cout << arr[i] << "  i " << i  << endl;
	}

	int t;
	cin >> t;
	ll ans=1;
	int s=1;
	// for(int i =	1;i<101;i++)
	// 	cout << arr[i] << " " << i << endl;
	for(int i=1;i<n;i++){
		if (arr[i]<3)
		{
			arr[i] = ans;
			ans++;
		}
		else
			arr[i]=-1;
	}
	while(t>0){
		ll a;
		cin >>a;

		if (arr[a]>0)
		{
			printf("Case %d: %lld\n",s,arr[a]);
			ans++;s++;
		}
		else{
			printf("Case %d: Not Cube Free\n",s);s++;
		}
		t--;
	}
	
}