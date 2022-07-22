// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j = numbers.size()-1;
        while (1){
            int curr_sum = numbers[i] + numbers[j];
            if (curr_sum < target){
                i++;
            }
            else if(curr_sum > target){
                j--;
            }
            else{
                break;
            }
        }
        vector<int> res = {i+1, j+1};
        return res;
    }
};
