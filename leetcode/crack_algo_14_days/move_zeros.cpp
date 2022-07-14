class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_zero = 0;
        int i=0;
        while(i<nums.size()-num_zero){
            if(nums[i]==0){
                num_zero++;
                for (int j=i; j<nums.size()-num_zero; j++){
                    swap(nums[j], nums[j+1]);
                }
            }
            else i++;
        }
    }
};
