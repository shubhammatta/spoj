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
#define ll long long int
long long maxm;
vector<ll> vec;
void add(ll a){
    //cout << a <<endl;
    //if(a > 1LL<<62 || a<0) return;
    ll a1 = a*10;
    ll a2 = a*10+1;
    if(a1< (1LL<<62) && a1>0) {vec.push_back(a1); add(a1);}
    if(a2 < (1LL<<62) && a2>0) {vec.push_back(a2); add(a2);}
    return;
}
/* Driver program to test insertion sort */
int main()
{
    //maxm = 1<<61;
    int a,r,x,n;
    int t; cin>> t;
    vec.push_back(0);
    vec.push_back(1);
    add(1LL);
    //for(int i=0;i<vec.size();i++) cout << vec[i] << " " ;cout << endl;
    // cout << vec.size();
    //int t;cin>>t;
    sort(vec.begin(),vec.end());
    //for(int i=1;i<100;i++) cout << vec[i] << endl;
    vector<ll> TTT(20020,0);
    for(int i=1;i<=20000;i++){
        
    }
    while(t--){
        cin >> n;
        for(int j=1;j<vec.size();j++){
            if(vec[j]%n==0) {cout << vec[j] << endl; break;}
        }
    }
    return 0;
}
