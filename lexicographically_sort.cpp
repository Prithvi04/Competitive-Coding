// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void sort_by_order( vector <string> &words, string &alphabets );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string alphabets;
        cin>> alphabets;
        
        int n;
        cin>>n;
        vector<string> words(n);
        for(int i=0; i<n; i++)
            cin>> words[i];
        
        sort_by_order( words, alphabets );
        
        for(int i=0; i<n; i++)
            cout<< words[i] << " ";
        cout<< endl;
    }
    return 1;
}

// } Driver Code Ends
void sort_by_order( vector <string> &words, string &alphabets )
{
    // just sort the sstrings as mentioned
    // do not print anything
    unordered_map <char,int> order;
    for( int i=0 ; i<alphabets.size() ; i++ )
        order[alphabets[i]] = i;
    
    for(int i=0; i<words.size(); i++)
        for(int j=0; j<words[i].size(); j++)
            words[i][j] = 'a' + order[ words[i][j] ];
    
    sort( words.begin() , words.end() );
    
    for(int i=0; i<words.size(); i++)
        for(int j=0; j<words[i].size(); j++)
            words[i][j] = alphabets[ words[i][j] - 'a' ];
    
    
}
