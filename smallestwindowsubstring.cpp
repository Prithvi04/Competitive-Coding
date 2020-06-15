class Solution {
public:
    int n=256;
    string minWindow(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        if(len1<len2)
            return "";
        
        vector<int>hash_s(n,0);
        vector<int>hash_t(n,0);
        
        for(int i=0;i<len2;i++)
            hash_t[t[i]]++;
        
        int start=0,start_index=-1,minlen=INT_MAX;
        int count=0;
        
        for(int i=0;i<len1;i++)
        {
            hash_s[s[i]]++;
            
            if(hash_t[s[i]]!=0 && hash_s[s[i]]<=hash_t[s[i]])
                count++;
            if(count==len2)
            {
                while(hash_s[s[start]]>hash_t[s[start]] ||hash_t[s[start]]==0)
                {
                    if(hash_s[s[start]]>hash_t[s[start]])
                    {
                        hash_s[s[start]]--;
                        
                    }
                    start++;
                }
                int len_window=i-start+1;
                if(len_window<minlen)
                {
                    minlen=len_window;
                    start_index=start;
                }
            }
        }
        if(start_index!=-1)
            return s.substr(start_index,minlen);
        else
            return "";
    }
};