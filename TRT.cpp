#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t;
int ** dp;
int answer(int arr[], int start , int end){
	if(end<start){
		return 0;
	}
	else if(dp[start][end]!=-1)
	{
		return dp[start][end];
	}
	else{
		int days = t - (end-start);
		return dp[start][end]= max(days*arr[start] + answer(arr,start+1,end),days*arr[end]+answer(arr,start,end-1));
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
       		cin >> arr[i];
    }   

    dp = new int*[t];
    for(int i=0;i<t;i++){
        dp[i] = new int[t];
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++)
            dp[i][j]=-1;
    }
    cout << answer(arr , 0,t-1)<<endl;
    return 0;
}

