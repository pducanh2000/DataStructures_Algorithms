//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int get_num_step(int n, vector<int>& memo_arr){
        if(memo_arr[n]!=-1){
            return memo_arr[n];
        }
        int result;
        if(n<=2){
            result = n;
        }
        else if(memo_arr[n] == -1){
            result = get_num_step(n-1, memo_arr) + get_num_step(n-2, memo_arr);
        }
        memo_arr[n] = result;
        return result;
    }
    int climbStairs(int n) {
        vector<int> memo_arr(n+1, -1);
        
        int ans = get_num_step(n, memo_arr);
        return ans;
    }
};
