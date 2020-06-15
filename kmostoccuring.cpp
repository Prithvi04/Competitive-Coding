// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


// Function to print the k numbers with most occurrences 
int print_N_mostFrequentNumber(int arr[],int n, int k) 
{ 
	// Your code here
	unordered_map<int,int>mp;
	priority_queue<int>pq;
	int res=0;
	for(int i=0;i<n;i++)
	{
	    mp[arr[i]]++;
	}
	for(auto it:mp)
	{
	    pq.push(it.second);
	}
	while(k--)
	{
	    res+=pq.top();
	    pq.pop();
	}
	return res;

} 



// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends