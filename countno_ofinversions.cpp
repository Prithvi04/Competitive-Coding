//O(NlogN) mergesort based most optimal solution
//Naive is standard O(N^2) solution
//Other solutions are using set and C++ STL lower_bound() O(N^2) solution

#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>arr,vector<int>temp,int start,int mid,int end)
{
    int i,j,k;
    i=start;
    j=mid;
    k=start;
    int inv_count=0;
    while((i<=mid-1) && (j<=end))
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            
            inv_count+=mid-i;
        }
        
    }
    while(i<=mid-1)
    temp[k++]=arr[i++];
    
    while(j<=end)
    temp[k++]=arr[j++];
    
    for(int i=start;i<=end;i++)
    arr[i]=temp[i];
    
    return inv_count;
}
int mergesort(vector<int>arr,vector<int>temp,int start,int end)
{
    int mid,inv=0;
    while(start<end)
    {
        mid=(start+end)/2;
        inv+=mergesort(arr,temp,start,mid);
        inv+=mergesort(arr,temp,mid+1,end);
        inv+=merge(arr,temp,start,mid+1,end);
    }
    //cout<<inv<<endl;
    return inv;
    
}
int main()
 {
	//code
	//cout<<"Hello Geeks, this is Prithvi"
	int x;
	cin>>x;
	while(x--)
	{
	    int n;
	    cin>>n;
	    vector<int>arr(n,0);
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    vector<int>temp(n,0);
	    cout<<mergesort(arr,temp,0,n-1)<<endl;
	}
	return 0;
}