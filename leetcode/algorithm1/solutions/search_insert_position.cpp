class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size()-1, low=0;
        int mid = (high+low)/2;
        while(high-low>1){
            if (nums[mid] > target){
                high = mid -1;
            }
            else{
                low = mid;
            }
            mid = (high+low)/2;
        }
        if (nums[high]<target){
            return high+1;
        }
        else if (nums[low]>=target){
            return low;
        }
        return high;
    }
};
