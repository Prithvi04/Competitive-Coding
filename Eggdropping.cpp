//A typical question in Dyynamic Programming.
#include<bits/stdc++.h>
using namespace std;
void eggdrop(int n,int k)
{
    int egg[n+1][k+1];
    //egg[i][j] is the minimum number attempts required by i eggs used in j floors
    for(int i=0;i<=n;i++)
    {
        egg[i][0]=0;
        egg[i][1]=1;
    }
    //Zero trials for 0 floors and 1 trial for 1 floor
    for(int j=1;j<=k;j++)
    {
        egg[1][j]=j;
    }
    //We need j trials for j floors with 1 egg
    int res;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            egg[i][j]=INT_MAX;
            //Optimal Substructure property
            for(int x=1;x<=j;x++)
            {
                res=1+max(egg[i-1][x-1],egg[i][j-x]);
                //if the egg breaks then we consider below x-1 floors (i-1,x-1)
                //if the egg dosen't break then we consider above floors (i,j-x).
                if(res<egg[i][j])
                egg[i][j]=res;
            }
            
        }
    }
    //Finally the result.
    cout<<egg[n][k]<<endl;
}
int main()
 {
	//code
	//cout<<"Hello Geeks, this is Prithvi"
	int x;
	cin>>x;
	while(x--)
	{
	    int n,k;
	    cin>>n>>k;
	    eggdrop(n,k);
	}
	return 0;
}