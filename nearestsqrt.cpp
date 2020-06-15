#include <iostream>
#include <math.h>
using namespace std;

int main() {
	//code
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    int a;
	    cin>>a;
	    int x=(int)sqrt(a);
	    if(x>1 && pow(x,2)!=a)
	    {
	        if(abs((int)pow(x,2)-a)<(abs((int)pow(x+1,2)-a)))
	        cout<<pow(x,2)<<endl;
	        else if(abs((int)pow(x,2)-a)>(abs((int)pow(x+1,2)-a)))
	        cout<<pow(x+1,2)<<endl;
	        else
	        cout<<pow(x+1,2)<<endl;
	    }
	    else if(pow(x,2)==a && x>1)
	    cout<<pow(x-1,2)<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}