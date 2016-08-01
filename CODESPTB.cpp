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
using namspace std;
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
  int i;
  for (i=0; i < n; i++)
  printf("%d ", arr[i]);
  printf("\n");
}
//Insertion Sort
void insertion_sort(int arr[],int n){
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i-1;
    while (j >= 0 && arr[j] > key)
    {
      count_insertion++;
      arr[j+1] = arr[j];
      j-=1;
    }
    arr[j+1] = key;
  }
}

/* Driver program to test insertion sort */
int main()
{
    int a,r,n;
    int t; cin>> t;
    while(t--){
        count_insertion=0;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> a[i];
        insertion_sort(arr,n);
        cout << count_insertion << endl;
    }
    return 0;
}
