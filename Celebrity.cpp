// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    vector<int>adj[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(M[i-1][j-1]==1)
            adj[i].push_back(j);
        }
    }
    int res=-1;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==0)
        res=i;
    }
    if(res==-1)
    return -1;
    
    int count=0;
    for(int i=0;i<=n;i++)
    {
        for(int j:adj[i])
        if(j==res)
        count++;
    }
    if(count!=n-1)
    return -1;
    
    return res-1;
}
//The graph approach (above code) O(n^2) with O(N) extra space in worst case
//A better approach is using two pointers (code  below) is O(N) with const extra space O(1).
//Two pointer approach
bool knows(int M[MAX][MAX],int a,b)
{
    return M[a][b];
}
int getId(int M[MAX][MAX], int n)
{
    int a=0,b=n-1;

    whie(a<b)
    {
        if(knows(a,b,M))
            a++;
        else
            b--;
    }

    for(int i=0;i<n;i++)
    {
        if(i!=a && knows(a,i,M) || !knows(i,a,M) )
            return -1;
    }
    return -1;
}