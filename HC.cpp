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
    int t,n;cin >> t;
    string s; int a,b;
    while(t--){
        cin >> n;
        a=0,b=0;
        while(n--){
            cin >> s;
            if(s=="lxh") a++;
            else b++;
        }
        if(a%2==1) cout << "lxh" << endl;
        else cout << "hhb" << endl;
    }
    return 0;
}
