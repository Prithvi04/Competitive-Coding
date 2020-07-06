class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        //O(N^2) DP solution TLE in leetcode
        /*vector<int>dp(n,INT_MAX);
        dp[0]=0;//0 ways to reach 0th position
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++) //iterate from 0th to ith pos
            {
                if(j+nums[j]>=i && dp[j]!=INT_MAX) //if it can reach ith pos and already reached jth with some jumps
                    dp[i]=min(dp[i],dp[j]+1); //update jumps at ith pos with min jumps
            }
        }
        return dp[n-1];*/
        if(n<2)
            return 0;//base case
        int ans=1,lim=nums[0];//already made a jump and fixing the limit
        int maxindexreach=nums[0];
        for(int i=1;i<n;i++)
        {
            if(i>lim) //ready to make another jump
            {
                ans++;//increment the jumps
                lim=maxindexreach;//update limit
            }
            maxindexreach=max(maxindexreach,i+nums[i]);//ith to lim find max reachable point from  there.
        }
        return ans;

        //The above solution is O(NlogN) time complexity an optimization over standard dp solution.
    }
};