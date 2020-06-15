#include <climits> 
#include <iostream> 
using namespace std; 
//Quick select based(Random partiton) is the optimized solution for quick select.
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
  
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
}
int randomPartition(int arr[], int l, int r) 
{ 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(&arr[l + pivot], &arr[r]); 
    return partition(arr, l, r); 
} 
int kthsmallest(int arr[], int n, int k) 
{ 
    // If k is smaller than number of elements in array 
    int l=0,r=n-1;
    while(l<=r)
    {
        int p=randomPartition(arr,l,r);
        if(p==k-1)
        return arr[p];
        else if(p>k-1)
        r=p-1;
        else
        l=p+1;
    }
    return INT_MAX; 
} 
  

// Standard partition process of QuickSort().  It considers the last 
// element as pivot and moves all smaller element to left of it 
// and greater elements to right 
 
int main()
 {
    //code
    //cout<<"Hello Geeks, this is Prithvi"
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        {
            int y;
            cin>>y;
            arr[j]=y;
        }
        int k;
        cin>>k;
        int ans=kthsmallest(arr,n,k);
        cout<<ans<<endl;
    }
    
    return 0;
}