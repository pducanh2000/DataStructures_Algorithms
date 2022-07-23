class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin=0, end=nums.size()-1;
        while (end-begin > 1){
            int mid = (end+begin)/2;
            if (target > nums[mid]){
                begin = mid+1;
            }
            else{
                end = mid;
            }
        }
        if (target == nums[begin]){
            return begin;
        }
        else if(target == nums[end]){
            return end;
        }
        else {
            return -1;
        }
    }
};
