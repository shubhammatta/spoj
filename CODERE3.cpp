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
#define ll long long int

long long max3(ll a , ll b , ll c){
	return max(a,max(b,c));
}
long long int dp[1004][1004]={0};

// void rec(ll arr[], ll N){
	
// 	for(ll index=N-1;index>=0;index--)		
// 		dp[index] = max3(arr[index]+dp[index+2], arr[index+1] + arr[index] + dp[index+4],arr[index+1] + arr[index]+arr[index+2]+ dp[index+6]);
		
// }

long long int rec(ll h , ll a){
	if(h<=5 || a<=0) return 0;
	else{
		if(dp[h][a]!=0) return dp[h][a];
		return dp[h][a] = max(((a>10)?2:0)+rec(h-2,a-8),((h>20)?2:0) + rec(h-17,a+7));
	}
}

int lbs( int arr[], int n )
{
   int i, j;
 
   /* Allocate memory for LIS[] and initialize LIS values as 1 for
      all indexes */
   int *lis = new int[n];
   for (i = 0; i < n; i++)
      lis[i] = 1;
 
   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
 
   /* Allocate memory for lds and initialize LDS values for
      all indexes */
   int *lds = new int [n];
   for (i = 0; i < n; i++)
      lds[i] = 1;
 
   /* Compute LDS values from right to left */
   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
 
 
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
     if (lis[i] + lds[i] - 1 > max)
         max = lis[i] + lds[i] - 1;
   return max;
}
 
/* Driver program to test above function */
int main()
{
  int t;cin>>t;
  while(t>0){
  	int n;
  	cin >> n;
  	int arr[n];
  	for(int i=0;i<n;i++)cin>>arr[i];
  	cout << lbs(arr,n) << endl;
  	t--;
  }
  
  return 0;
}



