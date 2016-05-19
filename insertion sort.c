//
//  main.c
//  insertion code
//
//  Created by IRON MAN on 06/01/15.
//  Copyright (c) 2015 IRON MAN. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    // insert code here...
    int n,i,k,m,g,temp,j;
    
    printf("input t how many numbers u want to sort\n --->");
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    //if(num[0]>num[1]){
      //  temp=num[0];
        //num[0]=num[1];
        //num[1]=temp;
        
    //}
    clock_t start,end;
    start=clock();
    for(i=1;i<n;i++)
    {
        for(j=i;j>=0;j--){
            if(num[j]<=num[j-1])
            {
                temp=num[j-1];
                num[j-1]=num[j];
                num[j]=temp;
            }
        }
        //for(k=0;k<n;k++){
     //   printf("%d ",num[k]);
        
     //   }
    }
    end=clock();
    printf("%f",(double)(end-start));
    printf("sorted array is--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",num[i]);
    }
    
    //printf("Hello, World!\n");
    return 0;
}
