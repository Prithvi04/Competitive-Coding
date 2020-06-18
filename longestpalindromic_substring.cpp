#include<bits/stdc++.h>
using namespace std;
void print(string s1,int s,int e)
{
    for(int i=s;i<=e;i++)
    cout<<s1[i];
    
    cout<<endl;
}
void LP(string s1,int n)
{
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    int maxlen=0;
    //String of length 1 is always palindromic
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true;
        maxlen=1;
    }
    int start=0;
    bool flag=false;
    //checking string of length 2
    for(int i=0;i<n-1;i++)
    {
        if(s1[i]==s1[i+1] && flag==false)
        {
        dp[i][i+1]=true;
        maxlen=2;
        start=i;
        flag=true;
        }
        else if(s1[i]==s1[i+1])
        dp[i][i+1]=true;
        
        
    }
    //checking string of len>=3, if element at ith pos = jth pos and elements between i+1 and j-1 are palindromic then this string from ith to jth is palindromic
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            
            if(s1[i]==s1[j] && dp[i+1][j-1]==true)
            {
                dp[i][j]=true;
                if(k>maxlen)
                {
                    start=i;
                    maxlen=k;
                }
            }
            
        }
    }
    //printing the substring
    print(s1,start,start+maxlen-1);
    
}
int main()
 {
	//code
	//cout<<"Hello Geeks, this is Prithvi"
	int x;
	cin>>x;
	while(x--)
	{
	    string s1;
	    cin>>s1;
	    //string s2="";
	    int n=s1.size();
	    //for(int i=n-1;i>=0;i--)
	    //s2+=s1[i];
	    LP(s1,n);
	}
	return 0;
}