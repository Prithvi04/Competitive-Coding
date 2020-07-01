// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void findMaximumNum(string str, int k, string& max);

// Driver code
int main() {
    int t, k;
    string str;
    cin >> t;
    while (t--) {
        cin >> k;
        cin >> str;
        string max = str;
        findMaximumNum(str, k, max);

        cout << max << endl;
    }
    return 0;
}
// } Driver Code Ends
// function to find maximum integer possible by
// doing at-most K swap operations on its digits
void findMaximumNum(string str, int k, string& max) {
    // Your code here
    if(k==0)
    return;//return when k swaps are done
    
    int n=str.length();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i]<str[j])//jth number greater than i
            {
                swap(str[i],str[j]);//swap them
                
                if(str.compare(max)>0)
                max=str;//store maximum number obtained from all recursive calls
                
                findMaximumNum(str,k-1,max);//reduce k and make another recursive call
                
                swap(str[i],str[j]); //backtrack once you reach the base case.
            }
        }
    }

    
}
