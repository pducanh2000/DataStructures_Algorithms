//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_ones=0;
        while(n){
            num_ones += n%2;
            n = n/2;
        }
        return num_ones;
    }
};
