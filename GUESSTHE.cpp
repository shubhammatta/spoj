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


#define ll long long int
/* Driver program to test insertion sort */

int gcd(int a,int b){
    if(b==0) return a;
    if(a==0) return b;
    return gcd(b,a%b);
}



int main()
{
    //cout << gcd(1,110) << endl;
    string s;cin >> s;
    while(s!="*"){
        int n = s.length();
        vector<int> divi,nondivi;
        for(int i=0;i<n;i++){
            if(s[i]=='Y'){
                divi.push_back(i+1);
            }
            else nondivi.push_back(i+1);
        }
        if(divi.size()==0) {cout << -1<< endl; cin >>s;continue;}
        if(divi[0]!=1){ cout << -1 << endl;cin >> s;continue;}
        if(divi.size()==1 && divi[0]==1) {cout << 1 << endl;cin >> s;continue;}
        ll lcm = divi[0]*divi[1]/gcd(divi[0],divi[1]);
        for(int i=2;i<divi.size();i++){
            lcm = lcm*divi[i]/gcd(lcm,divi[i]);
        }
        //cout << lcm << endl;
        bool x= true;
        for(int i=0;i<nondivi.size();i++){
            if(lcm%nondivi[i]==0) {x=false;break;}
        }
        if(x) cout << lcm << endl;
        else cout << -1 << endl;
        cin >>s;
    }
    return 0;
}
