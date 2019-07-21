#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
struct node
{
    long long start,position;
};
long long dp[2000][2000],a[2000][2000];
int main()
{
    char ch;
    long long n,m,i,j,l,max1,max2;
    stack<node> st;
    struct node temp;
    cin>>n>>m;
    getchar();
    for (i=1;i<=n;i++)
    {  
        for (j=1;j<=m;j++)
        {
            scanf("%c",&ch);
            if (ch=='0') a[i][j]=0;
            else a[i][j]=1;
        }
        getchar();
    }
    for (j=1;j<=m;j++)
    for (i=n;i>=1;i--)
    {
        if (a[i][j]==0) dp[i][j]=0;
            else dp[i][j]=dp[i+1][j]+1;
    }
    max1=0;
    max2=0;
    for (i=1;i<=n;i++)
    {
        while (!st.empty())
            st.pop();
        temp.start=1;
        temp.position=1;
        st.push(temp);
        for (j=2;j<=m;j++)
        {
            temp=st.top();
            if (dp[i][temp.position]<dp[i][j])
            {
                temp.start=j;
                temp.position=j;
                st.push(temp);
            }
            else
            {
                while (dp[i][temp.position]>=dp[i][j])
                {
                    if (max1<dp[i][temp.position]*(j-temp.start))
                    {
                        max2=max1;
                        max1=dp[i][temp.position]*(j-temp.start);
                    }
                    else if (max2<dp[i][temp.position]*(j-temp.start))  
                    {
                        max2=dp[i][temp.position]*(j-temp.start);
                    }
                    l=temp.start;
                    st.pop();
                    if (st.empty()) break;
                    temp=st.top();
                }
                temp.position=j;
                temp.start=l;
                st.push(temp);
            }
        }
        while (!st.empty())
        {
            temp=st.top();
            if (max1<dp[i][temp.position]*(m-temp.start+1))
            {
                max2=max1;
                max1=dp[i][temp.position]*(m-temp.start+1);
            }
            else if (max2<dp[i][temp.position]*(m-temp.start+1))
            {
                max2=dp[i][temp.position]*(m-temp.start+1);
            }  
            st.pop();
        }
    }
    printf("%lld\n",max2);
    return 0;
}