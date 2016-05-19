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
double dp[2000][300];
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

double dice(int k , int n){
	long long int sum;
	if(6*n<k)return 0;
	else if(k<n) return 0;
	else if(n==0 && k!=0)
		return 0;
	else if(n!=0 && k==0)
		return 0;
	else if(n==0 && k==0)
		return 1;
	else if(dp[k][n]!=-1)
		return dp[k][n]/6;
	else{
		dp[k][n] = dice(k-1,n-1) + dice(k-2,n-1) +dice(k-3,n-1)+dice(k-4,n-1)+dice(k-5,n-1)+dice(k-6,n-1);
		return dp[k][n]/6;
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n,k,s;//number of cars
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;

		scanf("%d %d",&n,&k);
		if(n>545||k>6*n||k>1908||k<n)
		{
			printf("0\n");
			continue;
		}
		loop(i,0,k+1)
			loop(j,0,n+1)
				dp[i][j]=-1;
		// loop(i,1,k+1)
		// 	loop(j,1,n+1)
		// 		{int bca = dice(i,j)*100 ;if(bca>0)cout << bca	<< " " << j <<  " " << i <<endl;}
		int ans = dice(k,n)*100;
		cout << ans<< endl;
	}
	
	
}