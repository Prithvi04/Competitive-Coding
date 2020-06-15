// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void print(int x,int (*sol)[MAX])
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}


 // } Driver Code Ends

void printmatrix(int (*m)[MAX],int x)
{
    for (int i = 0; i < x; i++) 
{ 
   for (int j = 0; j < x; j++) 
   { 
      cout << m[i][j] << " "; 
   } 
     
   // Newline for new row 
   cout << endl; 
}
}
int i=0,j=0;
bool isSafe(int i,int j,int x,int (*m)[MAX])
{
    return (i<x && j<x && m[i][i]>0);
}


void solve(int x, int (*m)[MAX])
{
    // ADD YOUR CODE HERE
    if(i==x-1 && j==x-1)
    {
        m[i][j]=1;
        printmatrix(m,x);
        return;
    }
    //int flag=0;
    if(isSafe(i,j,x,m)==true)
    {
        m[i][j]=1;
        for(int k=m[i][j];k>0;k--)
        {
            if(isSafe(i+k,j,x,m)==true)
            {
                m[i+k][j]=1;
                i=i+k;
                break;
            }
            //if(flag!=1)
            //{
                for(int k=m[i][j];k>0;k--)
                {
                    if(isSafe(i,j+k,x,m)==true)
                    {
                        m[i][j+k]=1;
                        j=j+k;
                        break;
                    }
                }
            //}
        }
    }
    solve(x,m);
}



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m[100][100];
        int x;
        cin>>x;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
                cin>>m[i][j];
        }

        solve(x,m);

    }
    return 0;
}
  // } Driver Code Ends