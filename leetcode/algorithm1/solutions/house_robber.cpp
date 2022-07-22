//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int max_at_index(int i, vector<int>& memo, vector<int>& nums){
        if(i<0){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int result;
        if(i<=1){
            result = nums[i];
        }
        else {
            result = nums[i] + max(max_at_index(i-2, memo, nums), max_at_index(i-3, memo, nums));
        }
        memo[i] = result;
        return result;
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        int num_house = nums.size();
        int max_rob = max(max_at_index(num_house-1, memo, nums), max_at_index(num_house-2, memo, nums));
        return max_rob;
    }
};
