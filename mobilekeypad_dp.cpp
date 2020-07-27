#include<bits/stdc++.h>
using namespace std;

int countkeypad(char keypad[][3],int n)
{
    if(keypad==NULL || n<=0)
    return 0;
    if(n==1)
    return 10;
    
    int key[10][n+1];
    for(int i=0;i<=9;i++)
    {
        key[i][0]=0;
        key[i][1]=1;
    }
    
    int row[]={0,-1,1,0,0};
    int col[]={0,0,0,-1,+1};
    
    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(keypad[i][j]!='*' && keypad[i][j]!='#')
                {
                    int num=keypad[i][j]-'0';
                    key[num][k]=0;
                    for(int r=0;r<5;r++)
                    {
                        int rc=i+row[r];
                        int cc=j+col[r];
                        if(rc>=0 && rc<4 && cc>=0 && cc<3 && keypad[rc][cc]!='*' && keypad[rc][cc]!='#')
                        {
                            int newnum=keypad[rc][cc]-'0';
                            key[num][k]+=key[newnum][k-1];
                        }
                    }
                }
                
            }
        }
    }
    int tot=0;
    for(int i=0;i<=9;i++)
    tot+=key[i][n];
    
    return tot;
    
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
	    char keypad[4][3]={{'1','2','3'}, 
                           {'4','5','6'}, 
                           {'7','8','9'}, 
                           {'*','0','#'}};
	    int res=countkeypad(keypad,n);
	    cout<<res<<endl;
	    
	}
	return 0;
}