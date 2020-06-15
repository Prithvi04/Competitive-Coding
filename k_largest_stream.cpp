// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void kthLargest(int arr[], int n, int k)
{
	// your code here
	priority_queue<int,vector<int>,greater<int>> pq; // making Minheap
	
	for(int i=0;i<n;i++)
	{
	    if(pq.size() < k) 
			pq.push(arr[i]);
		else // if size becomes equal to k
		{
			if(arr[i] > pq.top()) // if top element is smaller than arr[i]
			{
				pq.pop();
				pq.push(arr[i]);
			}
		}
		
		if(pq.size()<k)
			cout<<-1<<" ";
		else
			cout<<pq.top()<<" "; // print the current top element
	}

}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
    
	    kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends