//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // cause a xor a = 0, b xor a xor a = b
        int ans = nums[0];
        for (int i=1; i< nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
