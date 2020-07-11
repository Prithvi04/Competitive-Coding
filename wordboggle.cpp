// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// User function template for C++
bool ispresent(string str,vector<string>&dictionary)
{
    for(int i=0;i<dictionary.size();i++)
    if(str.compare(dictionary[i])==0)
    return true;
    
    return false;
}
void boggleutil(vector<vector<char> >& board,vector<string>&dictionary,int i,int j,int m,int n,vector<vector<bool>>&visited,vector<string>&res,string &str)
{
    visited[i][j]=true;
    str+=board[i][j];
    
    if(ispresent(str,dictionary)==true)
    res.push_back(str);
    
    for(int row=i-1;row<=i+1 && row<m;row++)
    for(int col=j-1;col<=j+1 && col<n;col++)
    if(row>=0 && col>=0 && visited[row][col]==false)
    boggleutil(board,dictionary,row,col,m,n,visited,res,str);
    
    visited[i][j]=false;
    str.erase(str.length()-1);
}
vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    int m=board.size();
    int n=board[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    vector<string>res;
    string str="";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            boggleutil(board,dictionary,i,j,m,n,visited,res,str);
        }
    }
    return res;
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dictionary;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int r, c;
        cin >> r >> c;
        vector<vector<char> > board(r);
        for (int i = 0; i < r; i++) {
            board[i].resize(c);
            for (int j = 0; j < c; j++) cin >> board[i][j];
        }
        vector<string> output = boggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
