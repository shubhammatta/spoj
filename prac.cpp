#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
       int n;
    int k;
    int count=0;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k,0);

    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i]; b[(a[a_i])%k]++;
        
    }
    count = min(1,b[0]);
    for(int i=1;i<k;i++){
        
        if(i>=k-i){
            break;
        }else{
            count+=max(b[i],b[k-i]);
        }
    }
    if(k%2==0)
    count+=min(1,b[k/2]);
    
    cout<<count<<endl;
    
 
    return 0;
    
}