#include<bits/stdc++.h>
using namespace std;
bool hcontains(string s,string arr[])
{
    int n=sizeof(arr)/sizeof(arr[0]);
    //cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        if(arr[i].compare(s)==0)
        return true;
    }
    return false;
}

void wordbreak(string arr[],string check,int n)
{
    int s=check.size();
    bool dp[s+1];
    memset(dp,false,sizeof(dp));
    
    for(int i=1;i<=s;i++)
    {
        if(dp[i]==false && hcontains(check.substr(0,i),arr))
        dp[i]=true;
        
        if(dp[i]==true)
        {
            if(i==s)
            {
            cout<<1<<endl;
            break;
            }
            
            for(int j=i+1;i<=s;j++)
            {
                if(dp[j]==false && hcontains(check.substr(i,j-i),arr))
                dp[j]=true;
                
                if(j==s && dp[j]==true )
                {
                cout<<1<<endl;
                break;
                }
            }
        }
    }
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
	    string arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    string check;
	    cin>>check;
	    wordbreak(arr,check,n);
	}
	return 0;
}