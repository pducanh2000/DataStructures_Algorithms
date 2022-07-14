class Solution {
public:
        // Function for quicksort
        int partition(vector<int>& nums, int begin, int end){
            int pivot = nums[begin];
            int count = 0;
            for (int i = begin+1; i <= end; i++){
                if (nums[i] <= pivot){
                    count ++;
                }
            }
            
            int pivot_index = begin + count;
            swap(nums[pivot_index], nums[begin]);
            int i = begin, j = end;
            while(i < pivot_index && j > pivot_index){
                while(nums[i] <= pivot){
                    i++;
                }
                while (nums[j] > pivot){
                    j--;
                }
                if (i < pivot_index && j > pivot_index){
                    swap(nums[i++], nums[j--]);
                }
            }
            
            return pivot_index;    
        }
        // Quick sort function 
        void quicksort(vector<int>& nums, int begin, int end){
            if(end <= begin){
                return;
            }
            int p = partition(nums, begin, end);
            quicksort(nums, begin, p-1);
            quicksort(nums, p+1, end);
        }
    
        // Main function
        vector<int> sortedSquares(vector<int>& nums) {
            for (int i=0; i<nums.size(); i++){
                nums[i] = nums[i] * nums[i];
            }
            // Sort the vector nums
            quicksort(nums, 0, nums.size()-1);
            return nums;
        }
};
