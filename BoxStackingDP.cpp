// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct box
{
    int l,w,h;
    box(int length,int width,int height)
    {
        l=length;
        w=width;
        h=height;
    }
    
};
bool cmp(box &a,box &b)
{
    return (a.l*a.w)>(b.w*b.l);
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<box> vec;
    for(int i=0;i<n;i++)
    {
        //3 possible combination of l,b,h
        box m1(length[i],width[i],height[i]);
        vec.push_back(m1);
        box m2(max(height[i],width[i]),min(height[i],width[i]),length[i]);
        vec.push_back(m2);
        box m3(max(height[i],length[i]),min(height[i],length[i]),width[i]);
        vec.push_back(m3);
    }
    
    sort(vec.begin(),vec.end(),cmp); //sort based on base area of the box
    n=(3*n);
    int msis[n];
    //Apply LIS to get maximum height
    msis[0]=vec[0].h;
    for(int i=1;i<n;i++)
    {
        msis[i]=vec[i].h;
        for(int j=0;j<i;j++)
        {
            if(vec[j].w>vec[i].w && vec[j].l>vec[i].l)//needs l and b of lower box should be more to stack up
            msis[i]=max(msis[i],msis[j]+vec[i].h);//stores max height seq for that index
        }
    }
    int res=0;//Gets overall maximum
    for(int i=0;i<n;i++)
    res=max(res,msis[i]);
    
    return res;
}