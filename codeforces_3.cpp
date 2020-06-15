#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int main()
{
    int n1,n2;

    cin>>n1>>n2;

    int arr[n1];
    for(int i=0;i<n1;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n1-1;i++) 
    {

        for(int j=i+1;j<n1;j++)
        {
            sum+=abs(arr[i]-arr[j]);

        }
    }
    cout<<(sum%n2)<<endl;

    return 0;
}