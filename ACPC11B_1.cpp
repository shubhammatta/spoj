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
#include <limits.h>
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

int mindiff(int array1[], int array2[] , int N1, int N2){
	int i=0,j=0;
	int minDiff = INT_MAX;
	while ( i < N1 && j < N2 )
    {
		if( array1[i] == array2[j] )
		return 0;
		int diff = abs( array1[i] - array2[j] );
		            minDiff = min( diff, minDiff );
		if( array1[i] > array2[j] )
		                j++;
		else
		                i++;
	}
	if( i < N1 ) //array1 has some more elements
        {
            j--; // j has reached the end, move it to last element
			while ( i < N1 )
			            {
			int diff = abs( array1[i] - array2[j] );
			                minDiff = min( diff, minDiff );
			                i++;
			            }
			        }
			else //array2 has some more elements
			        {
			            i--;
			while ( j < N2 )
			            {
			int diff = abs( array1[i] - array2[j] );
			                minDiff = min( diff, minDiff );
			                j++;
            }
        }
        return minDiff;
}



int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int t;cin >>t;
	//int arr[2200]={0};
	while(t--){
		int N1,N2;
		cin >> N1;
		int arr1[N1];
		for(int i=0;i<N1;i++){
			cin >> arr1[i];
		}
		cin >> N2;
		int arr2[N2];
		for(int i=0;i<N2;i++){
			cin >> arr2[i];
		}
		int min1 =INT_MAX;
		for(int i=0;i<N1;i++){
			for(int j=0;j<N2;j++){
				if(min1 > abs(arr1[i]-arr2[j]))
					min1 = abs(arr1[i]-arr2[j]);
			}
		}
		cout << min1 << endl;
	}

	return 0;
	
}