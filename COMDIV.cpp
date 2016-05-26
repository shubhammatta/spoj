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

unsigned int gcd(unsigned int u, unsigned int v)
{
  int shift;

  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
 
  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  /* From here on, u is always odd. */
  do {
       /* remove all factors of 2 in v -- they are not common */
       /*   note: v is not zero, so while will terminate */
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;

       /* Now u and v are both odd. Swap if necessary so u <= v,
          then set v = v - u (which is even). For bignums, the
          swapping is just pointer movement, and the subtraction
          can be done in-place. */
       if (u > v) {
         unsigned int t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);

  /* restore common factors of 2 */
  return u << shift;
}

int sum1(long long int x){
	int count=0;
	while(x!=0)
		{count+=x%10;x/=10;}
	return count;
}

int primes[100000];
int cnt=0;
bool arr[1000011]={0};
void seive(){
	for(int i=2;i<1001;i++){
		//cout << i << endl;
		if(arr[i]==0)
		{
			for(int j=i*i;j<1000011;j+=i){
					arr[j]=1;
				}
			//cout << i << endl;
			//primes[cnt++]=i;
		}
	}
	primes[0]=2;
	cnt=1;
	for(int i=3;i<1000011;i+=2){
		if(arr[i]==0)
			primes[cnt++]=i;
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
		
	int a,b;
	seive();
	// for(int i=0;i<100;i++)
	// 	cout << primes[i] << " " << i << endl;
	while(t--){
		//memset(arr,0,1000001);
		cin >> a >> b;
		a = gcd(a,b);
		if(a==1)
			cout << 1 << endl;
		else
		{
			int count=0;
			long long int ans=1;
			for(int i=0;i <= 78500 && primes[i]<=a ;i++){
				count=0;
				//cout << primes[i] << " s fd" << endl;
				while(a%primes[i]==0){
					//cout << primes[i] << endl;
					a/=primes[i];
					count++;
				}
				ans*=(count+1);
			}
			cout << ans << endl;
		}

	}

	
}