// Program to show segment tree to demonstrate lazy
// propagation
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
#define MAX 400010

long long int tree[MAX] = {0};  // To store segment tree
long long int lazy[MAX] = {0};  // To store pending updates
        long long int arr[MAX]={0};
void updateRangeUtil(long long int si, long long int ss, long long int se, long long int us,
                     long long int ue, long long int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se){
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    long long int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
void updateRange(long long int n, long long int us, long long int ue, long long int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
long long int getSumUtil(long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    long long int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
long long int getSum(long long int  n, long long int  qs, long long int  qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}
void constructSTUtil(long long int arr[], long long int ss, long long int se, long long int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
void constructST(long long int  arr[], long long int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}
int maxSubArraySum(int size , int start , int end)
{
   int max_so_far = arr[start];
   int curr_max = arr[start];
 
   for (int i = start+1; i <= end; i++)
   {
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
int main()
{
    
        long long  int n ,c;
        cin >> n;
        memset(tree,0,MAX*sizeof(int));       memset(lazy,0,MAX*sizeof(int));
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        constructST(arr, n);
        cin >> c;
        while(c--)
        {
            int ch; cin >> ch;
            if(ch==0){
                int i1,i2,add;
                cin >> i1 >> add;
                updateRange(n, i1-1, i1-1, add - arr[i1-1]);
                arr[i1-1] = add;
            }
            else{
                int i1 ,i2;
                cin >> i1 >> i2;
                i1-=1;i2-=1;
                long long int max1=maxSubArraySum(n,i1,i2);
                
                cout << max1 << endl;
            }
}
    return 0;
}