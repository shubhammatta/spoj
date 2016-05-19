#include<stdio.h>

#define min(a,b)(a<b?a:b)
int m;
int l;
double dp[551][3306];
double rec(int n ,int sum)
{
	if(sum==l&&n==m+1)
	return 1;
    if(n==m+1||sum>=l)
	return 0;
	if(dp[n][sum]!=-1)
	{
	return dp[n][sum]/6;
}
    double k;
    int x=min(6,l-sum);
	for(int i=1;i<=x;i++)
	{
		k=rec(n+1,sum+i);
		if(dp[n][sum]==-1 && k>=0)
		dp[n][sum]=k;
		else
		dp[n][sum]=k+dp[n][sum];	
	}
	return dp[n][sum]/6;
}
int main()
{
	 int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		scanf("%d%d",&m,&l);
		if(m>=548||l>6*m||l>3300)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=l;j++)
			{
				dp[i][j]=-1;
			}
		}

		short int s=100*rec(1,0);
		printf("%d\n",s);
	}
}
