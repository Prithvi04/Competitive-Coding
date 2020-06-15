// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool cmp(Item a,Item b)
{
    return (a.value/a.weight)>(b.value/b.weight);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr,arr+n,cmp);
    double res=0.0;
    for(int i=0;i<n;i++)
    {
        if(W>=arr[i].weight)
        {
            res+=arr[i].value;
            W-=arr[i].weight;
        }
        else
        {
            res+=(W/arr[i].weight)*arr[i].value;
            break;
        }
    }
    return res; 
}


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends