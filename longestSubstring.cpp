class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        //Tricky sliding window approach by strategically moving i and j.
        vector<int>arr(256,0);
        int i=0,j=0;
        int n=s.size();
        arr[s[0]]++;
        int count=1;
        while(j!=n-1)
        {
            if(arr[s[j+1]]==0)
            {
                j++;
                arr[s[j]]++;
                count=max(count,j-i+1);
            }
            else
            {
                arr[s[i]]--;
                i++;
            }
        }
        return count;
        
    }
};