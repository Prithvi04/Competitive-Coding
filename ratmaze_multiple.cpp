// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isSafe(int i,int j,vector<int>maze[],int N)
{
    return (i<N && j<N && maze[i][j]!=0);
}
void printmat(vector<vector<int>>res,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solvemazeRec(int i,int j,vector<int>maze[],vector<vector<int>>&res,int N)
{
    if(i==N-1 && j==N-1)
    {
        res[i][j]=1;
        return true;
    }
    else if(isSafe(i,j,maze,N)==true)
    {
        res[i][j]=1;
        for(int k=1;k<=maze[i][j] && k<N;k++)
        {
            if(solvemazeRec(i+k,j,maze,res,N)==true)
            return true;
            
            if(solvemazeRec(i,j+k,maze,res,N)==true)
            return true;
        }
        res[i][j]=0;
        //return false;
    }
    return false;
}
void solve(int N, vector<int> maze[]) {
    // write code here
    vector<vector<int>>res(N,vector<int>(N,0));
    if(solvemazeRec(0,0,maze,res,N)==false)
    cout<<-1<<endl;
    else
    {
        printmat(res,N);
    }
}