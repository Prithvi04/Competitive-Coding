#include<bits/stdc++.h>
using namespace std;
void maxindex(vector<int>arr,int n)
{
    int Lmin[n],Rmax[n];
    Lmin[0]=arr[0];
    for(int i=1;i<n;i++)
    Lmin[i]=min(Lmin[i-1],arr[i]);
    
    Rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    Rmax[i]=max(Rmax[i+1],arr[i]);
    
    int i=0,j=0;
    int diff=-1;
    while(i<n && j<n)
    {
        if(Lmin[i]<=Rmax[j])
        {
            diff=max(diff,j-i);
            j++;
        }
        else
        i++;
    }
    if(diff!=-1)
    cout<<diff<<endl;
    else
    cout<<0<<endl;
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
	    
	    maxindex(arr,n);
	}
	return 0;
}