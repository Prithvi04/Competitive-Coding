int minimumSwaps(vector<int> arr) {
    int n=arr.size();
    pair<int,int>p[n];//actual position and correct position
    vector<bool>vis(n,false);//visited array
    for(int i=0;i<n;i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+n);//sort it to actual position
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i] || p[i].second==i)//correct position already or visited already
        continue;

        int j=i;
        int cyclecount=0;
        while(!vis[j])
        {
            vis[j]=true;
            j=p[j].second;
            cyclecount++;//number of elements visited in a single cycle
        }
        if(cyclecount>0)
        {
            res+=(cyclecount-1);//swaps=cyclecount-1 for each cycle.
        }
    }
    return res;


}