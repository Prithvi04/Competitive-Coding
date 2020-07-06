class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);//appending 1 cost before and after all balloons.
        int n=nums.size();//calculating the actual size now
        int dp[n+1][n+1];//DP table, DP+divide and conquer problem
        for(int i=0;i<n;i++)
            dp[i][i]=0;//keeping base cases as zero
        
        for(int L=2;L<n;L++) //decides the window size in interest
        {
            for(int i=1;i<n-L+1;i++) //start pointer
            {
                int j=i+L-1;//end pointer
                
                dp[i][j]=INT_MIN; //Maximization problem
                for(int k=i;k<j;k++)//curr of the window
                {
                    int cost=dp[i][k]+dp[k+1][j]+(nums[i-1]*nums[k]*nums[j]);//window before curr+window after curr+(cost if curr is the last balloon to be busted)
                    if(cost>dp[i][j])
                        dp[i][j]=cost; //take max of all cost for the current window
                }
                
            }
        }
        return dp[1][n-1]; //cost for the complete ideally start=1 and end =n-1 ( 0 based indexing)
        
    }
};