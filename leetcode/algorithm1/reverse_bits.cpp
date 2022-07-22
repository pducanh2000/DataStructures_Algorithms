//https://leetcode.com/problems/reverse-bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // get reverse string bit
        vector<int> reverse_bit;
        while(n){
            reverse_bit.push_back(n%2);
            n = n/2;
        }
        while(reverse_bit.size() < 32){
            reverse_bit.push_back(0);
        }
        // get the ouput number
        uint32_t ans=0;
        uint32_t factor=1;
        for(int i=31; i>-1;i--){
            ans += reverse_bit[i]*factor;
            factor *= 2;
        }
        return ans;
    }
};
