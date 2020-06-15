#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x,int y,int n)
{
    if(x>0 && x<=n && y>0 && y<=n)
    return true;
    else
    return false;
}
int  fight(pair<int,int>source,pair<int,int>dest,int n)
{
    bool visited[n+1][n+1]={false};
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(source.first,source.second),0));
    visited[source.first][source.second]=true;
    int res=-1;
    int x[]={-2,-2,2,2,-1,-1,1,1};
    int y[]={-1,1,-1,1,-2,2,-2,2};
    while(q.empty()==false)
    {
        pair<pair<int,int>,int>p=q.front();
        q.pop();
        if(p.first.first==dest.first && p.first.second==dest.second)
        return p.second;
        
        for(int i=0;i<8;i++)
        {
            if(isSafe(p.first.first+x[i],p.first.second+y[i],n))
            {
                if(visited[p.first.first+x[i]][p.first.second+y[i]]==false)
                {
                    visited[p.first.first+x[i]][p.first.second+y[i]]=true;
                    q.push(make_pair(make_pair(p.first.first+x[i],p.first.second+y[i]),p.second+1));
                    
                }
                
            }
            
        }
    }
    
}
int main()
 {
	//code
	//cout<<"Hello Geeks, this is Prithvi"
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    int a,b;
	    cin>>a>>b;
	    pair<int,int>source;
	    source.first=a;
	    source.second=b;
	    cin>>a>>b;
	    pair<int,int>dest;
	    dest.first=a;
	    dest.second=b;
	    int y=fight(source,dest,x);
	    cout<<y<<endl;
	}
	return 0;
}