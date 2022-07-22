// https://leetcode.com/problems/permutations/
class Solution {
public:
    void backtracking(vector<vector<int>>& permutations, vector<int>& used, vector<int> nums, vector<int>& arr, int pos){
        if(pos==nums.size()){
            permutations.push_back(arr);
        }
        else{
            for(int i=0; i<nums.size(); i++){
                if(!used[i]){
                    arr[pos] = nums[i];
                    used[i] = 1;
                    backtracking(permutations, used, nums, arr, pos+1);
                    used[i] = 0;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> used (nums.size(), 0);
        vector<int> arr (nums.size());
        backtracking(permutations, used, nums, arr, 0);
        return permutations;
    }
};
