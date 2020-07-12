// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    set<pair<int,int>>s;
    vector<int>dis(V,INT_MAX);
    dis[src]=0;
    s.insert(make_pair(0,src));
    
    while(!s.empty())
    {
        pair<int,int>p=*(s.begin());
        s.erase(s.begin());
        
        int u=p.second;
        for(int i=0;i<g[u].size();i++)
        {
            if(g[u][i]!=0)
            {
                int v=i;
                int weight=g[u][i];
                if(dis[v]>(dis[u]+weight))
                {
                    if(dis[v]!=INT_MAX)
                    s.erase(s.find(make_pair(dis[v],v)));
                    
                    dis[v]=dis[u]+weight;
                    s.insert(make_pair(dis[v],v));
                }
            }
        }
    }
    return dis;
}