class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if (n<=1; k<0){
            return;
        }
        vector<int> res(n);
        for (int  i=0; i<n; i++){
            res[i] = nums[i];
        }
        for (int i=0; i<n; i++){
            nums[i] = res[(n+i-k)%n];
        }
        
    }
};

// second solution
    void reverseArray(vector<int>&nums,int i,int j){
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverseArray(nums,0,n-k-1);
        reverseArray(nums,n-k,n-1);
        reverseArray(nums,0,n-1);
    }
