You are given an array arr[ ], of n integers. Minimize the max difference the between pairs of adjacent array elements by inserting at most k elements in the array.
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int minimizedMaxDiff(int arr[], int n, int k);

int main()
{
    int arr[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int k;
        cin>>k;
        
        cout<< minimizedMaxDiff(arr,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends


//User function Template for C++

int minimizedMaxDiff(int arr[], int n, int k)
{
    // code here
    int max_diff=INT_MIN;
    for(int i=0;i<n-1;i++)
    max_diff=max(max_diff,abs(arr[i]-arr[i+1]));
    
    if(max_diff==0)
    return 0;
    
    int best=1;
    int worst=max_diff;
    int mid,req;
    while(best<worst)
    {
        mid=best+(worst-best)/2;
        req=0;
        for(int i=0;i<n-1;i++)
        {
            req+=(abs(arr[i]-arr[i+1])-1)/mid;
            
        }
        if(req>k)
        best=mid+1;
        else
        worst=mid;
    }
    return worst;
}
