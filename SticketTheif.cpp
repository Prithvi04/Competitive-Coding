#include<bits/stdc++.h>
using namespace std;
void sticker(int arr[],int n)
{
    int incl=arr[0];
    int excl=0;
    int excl_new;
    
    for(int i=1;i<n;i++)
    {
        excl_new=(incl>excl)?incl:excl;
        //maximum excluding prev element
        
        //maximum incl preveious element
        incl=excl+arr[i];
        excl=excl_new;
        
    }
    int maxi=(incl>excl)?incl:excl;
    cout<<maxi<<endl;
    /*int dp[n];
    dp[0]=arr[0];
    dp[1]=arr[1];
    
    for(int i=2;i<n;i++)
    {
        dp[i]=arr[i];
        for(int j=0;j<i-1;j++)
        {
            dp[i]=max(dp[i],arr[i]+dp[j]);
        }
    }
    cout<<dp[n-1]<<endl;*/
    //wrong approach
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    sticker(arr,n);
	}
	return 0;
}