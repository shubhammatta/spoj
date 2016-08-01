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
#include <utility>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <sstream>
int count_insertion;
int count_merge;
using namespace std;

class info{
public:
    int w , O,N;
    info(){;};
    info(int a, int b,int c){
        O=a;N=b;w=c;
    }
};

int rec(info arr[],int index,long long weight,int remO,int remN){
    if(remO<=0 && remN<=0) return weight;
    if(index<0 && (remO>0 || remN>0)) return INT_MAX;
    else {
        int k = min(rec(arr,index-1,weight,remO,remN),rec(arr,index-1,arr[index].w + weight,remO-arr[index].O,remN-arr[index].N));
        return k;
    }
}

int f(info arr[],int n , int reqO,int reqN){
    int dp[1009][22][80];
    for(int i=0;i<n;i++){
        for(int j=0;j<=reqO;j++){
            for(int k=0;k<=reqN;k++){
                dp[i][j][k] = 10000000;
                if(k==0 && j==0) dp[i][j][k]=0;
            }
        }
    }
    for(int j=0;j<=reqO;j++){
        for(int k=0;k<=reqN;k++){
            if((j>0 || k>0) && j<=arr[0].O && k<=arr[0].N) dp[0][j][k] = arr[0].w;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=reqO;j++){
            for(int k=0;k<=reqN;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(k<=arr[i].N && j<=arr[i].O) dp[i][j][k]=min(dp[i][j][k], arr[i].w);
                else dp[i][j][k]=min(dp[i][j][k],arr[i].w +dp[i-1][max(0,j-arr[i].O)][max(0,k-arr[i].N)]);
            }
        }
    }
    return dp[n-1][reqO][reqN];
}

/* Driver program to test insertion sort */
int main()
{
    int a,r,x,n;
    int t; cin>> t;
    while(t--){
        int reqo,reqn;
        cin >> reqo >> reqn;
        cin >> n;
        info * arr = new info[n];
        for(int i=0;i<n;i++){
            cin >> a >> r >> x;
            info T(a,r,x);
            arr[i] = T;
        }
        cout << f(arr,n,reqo,reqn) << endl;
    }
    return 0;
}
