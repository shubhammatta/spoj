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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(false); 
    int t;
    cin >> t;
    long long int N;
    while(t>0){
    	memset(dp, 0, sizeof(dp[0][0]) * 1004 * 1004);
    	int H,A;
    	cin >> H >> A ;
    	cout << rec(H+3,A+2) + 1 << endl;
        t--;
    }
    return 0;
}



