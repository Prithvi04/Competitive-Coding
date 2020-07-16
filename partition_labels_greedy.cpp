class Solution {
public:
    //O(N) solution with O(charlen) extra space.
    vector<int> partitionLabels(string S) {
        vector<int>lastoccur(26,0);
        for(int i=0;i<S.size();i++)
            lastoccur[S[i]-'a']=i;
        
        int start=0,end=0;
        vector<int>res;
        for(int i=0;i<S.size();i++)
        {
            end=max(end,lastoccur[S[i]-'a']);
            if(i==end)
            {
                int len=end-start+1;
                res.push_back(len);
                start=end+1;
            }
        }
        return res;
        
    }
};