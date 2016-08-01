#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
using namespace std;
 
// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
}
 


int main()
{
    string s;
    while(getline(cin,s)){
        string data = s;
        transform(data.begin(), data.end(), data.begin(), ::tolower);
        if(s.length()==1){
            cout << 0 << endl;
        }
        else{
            string k = data;
            int n = k.length();
            for(int i=0;i<n;i+=2){
                k[i]-=32;
            }
            string k1 = data;
            for(int i=1;i<n;i+=2){
                k1[i]-=32;
            }
            //cout << editDistDP(k1,s) << endl <<editDistDP(k,s) << endl;
            int p = min(editDistDP(k1,s,n,n),editDistDP(k,s,n,n));
            cout << p << endl;
        }
    }
}