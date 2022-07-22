//https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        while(!(n%2)){
            n = n/2;
        }
        if (n!=1){
            return false;
        }
        return true;
    }
};
