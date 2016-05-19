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
#define nl  cout<<endl
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

char inttochar(int n){
	char c = n-1+ 'a';
	return c;
}

int chartoint(char c){
	return c-'0';
}


bool prime(long long int x){
	for(int i=3;i<=sqrt(x);i+=2)
		if(x%i==0) return false;
	return true;
}


// long long int rec(long long int i){
// 	if(i < 1000000)
// 		return arr[i];
// 	else {
// 		if(i%2==0){
// 			return arr[i-1]+2;
// 		}
// 		else if(i%3==0)
// 			return rec(i-1) +3;
// 		else if(prime(i)){
// 			return rec(i-1) + i;
// 		}
// 		else{
// 			for(int j=3;j<=sqrt(i);j+=2){
// 				if(i%j==0){
// 					return rec(i-1) + j;
// 				}
// 			}
// 		}
// 	}
// }



int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	vector<int> arr(1000000,0);
	int t;
	cin >> t;
	for(int i=2;i<1000000;i++){
		if(i%2==0){
			arr[i] = arr[i-1]+2;
		}
		else if(i%3==0)
			arr[i] = arr[i-1] +3;
		else if(prime(i)){
			arr[i] = arr[i-1] + i;
		}
		else{
			for(int j=3;j<=sqrt(i);j+=2){
				if(i%j==0){
					arr[i] = arr[i-1] + j;
					break;
				}
			}
		}
	}
	while(t>0){
		long long int test;
		cin >> test;
		cout << arr[test] << endl;
		t--;
	}
}