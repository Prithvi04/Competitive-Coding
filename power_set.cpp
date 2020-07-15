class Solution {
public:
	//to print all subsets of a given number or array of number
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int set_size=pow(2,n);
        vector<vector<int>>res;
        for(int i=0;i<set_size;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
        
    }
};