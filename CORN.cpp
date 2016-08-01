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
#include <sstream>
#define pb push_back
#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)
#define modulus 10000007
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

#define Pi 3.1415
int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	string left;
	double maxm = 0;
	while(t--){
		cin >> left;
		istringstream ss(left);
	    string token;
	    std::vector<string> values;
	    while(getline(ss, token, 'e')) {
	        values.push_back(token);
	    }
	    // for(int i=0;i<values.size();i++) cout << values[i] << endl;
	    double R = stod(values[0]);
	    double cr = stod(values[1]);
	    double H = stod(values[2]);
	    double k = Pi*R*(sqrt(H*H + R*R));
	    //cout << k*cr << endl;
	    maxm=ceil(k*cr);
	    cout << (int)maxm << endl;
 	}
	//cout << (int)maxm << endl;
	
}