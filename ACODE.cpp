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

long long int rec(string s,int index){
	if(index==s.length()-1 || index==s.length())
		return 1;
	else{
		if(chartoint(s[index])*10+chartoint(s[index+1]) <=26){
			return rec(s,index+1)+ rec(s,index+2);
		}
		else {
			return rec(s,index+1);
		}
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	string s;
	cin >> s;
	while(s!="0"){
		int p = 1;
		long long int arr[s.length()];
		loop(i,0,s.length()) arr[i]=0;
		arr[0] = 1;
		if(chartoint(s[0])*10+chartoint(s[1])<=26 && s[0]!='0' && s[1]!='0')
			arr[1] = 2;
		else
			arr[1] = 1;
		for(int i=2;i<s.length();i++){
			if(s[i]!='0')
			{
				if(chartoint(s[i-1])*10+chartoint(s[i])<=26 && s[i-1]!='0'){
					arr[i] = arr[i-1] +arr[i-2];
				}
				else {
					arr[i] = arr[i-1];
				}
			}
			else{
				if(chartoint(s[i-1])*10+chartoint(s[i])<=26 && s[i-1]!='0')
					arr[i] = arr[i-2];
				else
					p=0;
			}
		}
		// loop(i,0,s.length()){
		// 	cout << arr[i] << " ";
		// }
		// nl;
		if(p!=0)
		cout << arr[s.length()-1] << endl;
		else cout << 0 << endl;
		cin >> s;
	}	
}